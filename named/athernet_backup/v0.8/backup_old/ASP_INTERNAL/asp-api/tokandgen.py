import sqlite3
import random
from flask import jsonify
from pagerrors import page_not_found
import string
from misc import dict_factory, strip_banned, check_bus_or_user
from ssencss import sxor
from collections import Counter


ASP_FOLDER = "/home/kj/Desktop/.d/ASP_INTERNAL"
PRIVATE_KEY = "akmfasf11rsd!@daidm#"
################################### get max id ##############################

def get_id_max():
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    res = []
    x1 = cur.execute('SELECT linkid FROM users').fetchall()
    x2 = cur.execute('SELECT linkid FROM businesses').fetchall()
    conn.close()
    for i in x1:
        res.append(list(i.values())[0])
    for j in x2:
        res.append(list(j.values())[0])
    return max(res)

############################# get lowest pointguyid ##########################

def assign_pointguy():
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    res = []
    x1 = cur.execute('SELECT pointguyid FROM users').fetchall()
    x2 = cur.execute('SELECT pointguyid FROM businesses').fetchall()
    conn.close()
    for i in x1:
        res.append(list(i.values())[0])
    for j in x2:
        res.append(list(j.values())[0])
    x = Counter(['1','2','3','4','5','6','7','14','15','16','17'])  
    res = Counter(res)
    
    x.subtract(res)
    return x.most_common(1)[0][0]

############################ Check Tokens and more ############################

def checkTokenValidHandler(t):
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()    
    results = cur.execute('SELECT * FROM tokenlinkshandler;').fetchall()
    conn.close()
    for i in results:
        if t in i.values():
            return True
        else: 
            continue
    return False            

def checkTokenValid(t):
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()    
    results = cur.execute('SELECT * FROM tokenlinks;').fetchall()
    results2 = cur.execute('SELECT * FROM tokenlinksbusinesses;').fetchall()
    cur.close()
    conn.close()

    for i in results + results2:
        if t in i.values():
            return True
        else: 
            continue          
    return False          

def checkBeforeGenerating(phonenumber):
    dbPhoneNumbers = []
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    busPN = cur.execute(""" SELECT phonenumber FROM businesses;""").fetchall()
    tbusPN = cur.execute(""" SELECT phonenumber FROM tempbusinesses;""").fetchall()
    userPN = cur.execute(""" SELECT phonenumber FROM users;""").fetchall()
    cur.close()
    conn.close()
    for i in busPN + tbusPN + userPN:
        dbPhoneNumbers.append(i['phonenumber'])
    
    if phonenumber in  dbPhoneNumbers:
        return True
    else:
        return False               

############################### generate token ##############################

def id_generator(size=23, chars=string.ascii_lowercase + string.digits):

    return ''.join(random.choice(chars) for _ in range(size))    

############################## sql a new user ###############################

def generateNewUser(request, name, phonenumber, password, verificationID):
    if checkBeforeGenerating(phonenumber):
        page_not_found(request)

    passwordVal = sxor(password,PRIVATE_KEY)
    token = id_generator()
    newID = int(get_id_max()) + 1
    pointguyid = assign_pointguy()

    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    cond1 = cur.execute(""" INSERT INTO users VALUES(?, ?, NULL, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)""", (phonenumber, passwordVal,newID,newID,newID,token,'true', name, verificationID, pointguyid, '0', '0'))
    cond2 = cur.execute(""" INSERT INTO tokenlinks VALUES(?, ?)""", (token, verificationID))
    cur.close()
    conn.commit()
    conn.close()
    return get_data_for_reg_users(request, phonenumber, password)

def generateTempBusiness(contactperson, phonenumber, busname):
    if checkBeforeGenerating(phonenumber):
            page_not_found(request)

    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    busnamefiltered = strip_banned(busname)
    phonenumberfiltered = strip_banned(phonenumber)
    contactpersonfiltered = strip_banned(contactperson)
    phonenumberfiltered = '+' + phonenumberfiltered
    try:
        cond = cur.execute(""" INSERT INTO tempbusinesses VALUES(?, ?, ?, NULL)""", (busnamefiltered, phonenumberfiltered, contactpersonfiltered))
        conn.commit()
        cur.close()
        conn.close()
        # this needs to be edited....
        return jsonify(busnamefiltered, phonenumberfiltered, contactpersonfiltered)
    except:
        cur.close()
        conn.close()
        return False

########################### get data from dbs ##############################

def check_if_handler_exsits(request, phonenumber, token):
    query = "SELECT id,name,phonenumber,key,position,privilege,lat,lng FROM handlers WHERE key=?;"
    
    if (phonenumber.startswith('+962')):
        to_filter = [token]
    else:
        return page_not_found(request)    

    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    try:
        results = cur.execute(query, to_filter).fetchall()
        cur.close()
        conn.close()
        if len(results[0]) == 8:
            return jsonify(results)  
    except:
        conn.close()
        return page_not_found(request)
    return page_not_found(request)    

def get_data_for_reg_users(request, phonenumber, password):
    query = "SELECT phonenumber, pword, linkid, iorderid, irequestid, token, isloggedin, contactperson, vID, pointguyid, lat, lng, notificationtoken FROM users WHERE phonenumber=? AND pword=?;"
    to_filter = []

    if (phonenumber.startswith('+962')):
        to_filter.append(phonenumber)
    else:
        return page_not_found(request)

    if (phonenumber.startswith('+962')):
        to_filter.append(sxor(password, PRIVATE_KEY))
    else:
        return page_not_found(request)    

    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    try:
        results = cur.execute(query, to_filter).fetchall()
        reresults = results
        if len(reresults[0]) > 0: 
            reresults[0]["usertype"] = "user"
        cur.close()    
        conn.close()
        return jsonify(reresults)
    except:
        cur.close()    
        conn.close()
        return page_not_found(request)

def check_if_bus_or_usr(request, phonenumber):
    if (phonenumber.startswith('+962')):
        return(check_bus_or_user("phonenumber", phonenumber))
    else:
        return page_not_found(request)

def get_data_for_reg_bus(request, phonenumber, password):
    query = "SELECT busname, lat, lng, iorderid, irequestid, linkid, phonenumber, pword, token, isloggedin, contactperson, pointguyid FROM businesses WHERE"
    to_filter = []

    if (phonenumber.startswith('+962')):
        query += ' phonenumber=? AND'
        to_filter.append(phonenumber)
    else:
        return page_not_found(request)

    if (phonenumber.startswith('+962')):
        query += ' pword=? AND'
        to_filter.append(sxor(password, PRIVATE_KEY))
    else:
        return page_not_found(request)    

    query = query[:-4] + ';'
    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    try:
        results = cur.execute(query, to_filter).fetchall()
        reresults = results
        if len(reresults[0]) > 0:
            reresults[0]["usertype"] = "business"
        conn.close()
        return jsonify(reresults)
    except:
        conn.close()
        return page_not_found(request)

#############################################################################

def admin_login(request, username, password):
    if username == 'admin' and password == 'ilovetazweid123':
        api_res = make_response('Welcome To ASP-API!',200)
        api_res.set_cookie('adminLOGIN','smdm3d1dkpg5g34ttgsdgDGs', httponly=True, secure=True, max_age=60*60*24*365) 
        return api_res
    return page_not_found(request)