from flask import Blueprint, g, request, jsonify
import sqlite3
from tokandgen import checkTokenValidHandler, checkTokenValid
from misc import dict_factory, check_bus_or_user, gencon
from pagerrors import page_not_found, internal_error, forbbid_any
from datetime import datetime
import time

ASP_FOLDER = "/home/kj/Desktop/.d/ASP_INTERNAL"

client_api = Blueprint('client_api', __name__)


'''
This function is used to submit orders to the database.

'''
@client_api.route('/requests/form', methods=['POST'])
def api_cust_submit_form(key):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 
    
    if request.is_json:
        data = request.get_json()
        temp_phonenumber = data['info']['phonenumber']
        temp_name =data['info']['name']
        temp_uorb = data['info']['usertype']


        if temp_phonenumber:        
            if temp_uorb == "business":
                query = "SELECT iorderid,irequestid,id,linkid FROM businesses WHERE contactperson=? AND phonenumber=?;"
                to_filter = [temp_name, temp_phonenumber]
            elif temp_uorb == "user":
                query = "SELECT iorderid,irequestid,id,linkid FROM users WHERE contactperson=? AND phonenumber=?;"
                to_filter = [temp_name, temp_phonenumber]
            else:
                return page_not_found(request)        
        else:
            return page_not_found(request)

        base_conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
        base_conn.row_factory = dict_factory
        base_cur = base_conn.cursor()
        results = base_cur.execute(query, to_filter).fetchall()

        results_iorderid = results[0]['iorderid']
        results_irequestid = results[0]['irequestid']
        results_id = results[0]['id']
        results_linkid = results[0]['linkid']
        info_obj = data['info']
        request_arr = data['requests']

        temp_aord = info_obj['aord']
        temp_pointguyid = info_obj['pointguyid']
        temp_quorpo = info_obj['quorpo']
        temp_isactive = info_obj['isactive']

        confirmation = gencon()

        base_cur.execute(""" INSERT INTO busreq VALUES(?, ?, ?, ?, ?,?)""", (results_irequestid, confirmation, temp_pointguyid, datetime.fromtimestamp(time.time()).strftime('%Y-%m-%d %H:%M'), temp_quorpo, "0"))



        action_conn = sqlite3.connect(ASP_FOLDER+'/databases/action.db')
        action_conn.row_factory = dict_factory
        action_cur = action_conn.cursor()


        for i in range(len(request_arr)):
            temp_key = request_arr[i]['key']
            temp_partnumber = request_arr[i]['form']['partnumber']
            temp_quantity = request_arr[i]['form']['quantity']
            temp_designation = request_arr[i]['form']['designation']
            temp_brand = request_arr[i]['form']['brand']
            temp_price = request_arr[i]['form']['price']
            temp_delivery = request_arr[i]['form']['delivery']
            action_cur.execute("""INSERT INTO requests VALUES(NULL,?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?) """, (results_id, temp_partnumber, temp_quantity, temp_brand ,temp_designation, temp_isactive, temp_aord, temp_pointguyid, temp_quorpo, temp_key, results_irequestid, confirmation, temp_price, temp_delivery ))

        base_cur.close()
        base_conn.commit()
        base_conn.close()
        action_cur.close()
        action_conn.commit()
        action_conn.close()
        return '''{}'''.format(confirmation), 200
    else:
        return page_not_found(request)


'''
This function is used to fetch customer pending orders and quotations with items.

'''

@client_api.route('/side/pending', methods=['GET'])
def api_cust_fetch_pending(key):
    g.key = key
    if not checkTokenValid(key):
        return forbbid_any(request) 

    temp_phonenumber = '+' + request.args.get('phonenumber').strip()
    uorb = request.args.get('u')
    
    base_conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    base_conn.row_factory = dict_factory
    base_cur = base_conn.cursor()      

    action_conn = sqlite3.connect(ASP_FOLDER+'/databases/action.db')
    action_conn.row_factory = dict_factory
    action_cur = action_conn.cursor()
    final_results = []

    if uorb == "user":
        query = "SELECT id,irequestid FROM users WHERE phonenumber=? AND token=?;"
    elif uorb == "business":
        query = "SELECT id,irequestid FROM businesses WHERE phonenumber=? AND token=?;"
    else:
        return page_not_found(request) 
    try:
        answer = base_cur.execute(query, [temp_phonenumber, key]).fetchall()
        query2 = "SELECT concode,pointguyid,quorpo,done FROM busreq WHERE irequestid=? AND done=?;"
        action_answer = base_cur.execute(query2, [answer[0]['irequestid'], "0"]).fetchall()
        base_cur.close()
        base_cur.close()

        if len(action_answer) == 0:
            action_cur.close()
            action_conn.close()
            return """{}""".format("No Items Found"), 200

        for x in action_answer:
            query3= "SELECT partnumber,quantity,brand,designation,quorpo,concod,price,aord FROM requests WHERE concod=? AND pointguyid=? AND quorpo=?;"
            to_filter3 = [x['concode'], x['pointguyid'], x['quorpo']]
            results = action_cur.execute(query3, to_filter3).fetchall()
            if len(results) != 0:
                name = results[0]['quorpo']+' #%s'%results[0]['concod']
                final_results.append({'title' : name , 'data' : results})
            else:
                return page_not_found(request)

        action_cur.close()
        action_conn.close()

        return jsonify(final_results)           
    except:
        return page_not_found(request)        


'''
This function is used to fetch the client done/previous purchase orders and quotations

'''

@client_api.route('/done', methods=['GET'])
def api_cust_send_done_qorp(key):
    g.key = key
    if not checkTokenValid(key):
        return forbbid_any(request) 

    temp_phonenumber = "+" + request.args.get('phonenumber').strip()
    uorb = request.args.get('u')
    temp_quorpo = request.args.get('q')

    
    base_conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    base_conn.row_factory = dict_factory
    base_cur = base_conn.cursor()      

    action_conn = sqlite3.connect(ASP_FOLDER+'/databases/action.db')
    action_conn.row_factory = dict_factory
    action_cur = action_conn.cursor()
    final_results = []

    if uorb == "user":
        query = "SELECT id,irequestid FROM users WHERE phonenumber=? AND token=?;"
    elif uorb == "business":
        query = "SELECT id,irequestid FROM businesses WHERE phonenumber=? AND token=?;"
    else:
        return page_not_found(request) 

    if temp_quorpo == "q":
        query3= "SELECT partnumber,quantity,brand,designation,quorpo,concod,price,aord FROM quotations WHERE concod=? AND pointguyid=? AND quorpo=?;"

    elif temp_quorpo == "p":
        query3= "SELECT partnumber,quantity,brand,designation,quorpo,concod,price,aord FROM orders WHERE concod=? AND pointguyid=? AND quorpo=?;"                   
    else:
        return page_not_found(request)

    try:
        answer = base_conn.execute(query, [temp_phonenumber,key]).fetchall()
        query2 = "SELECT concode,pointguyid,quorpo FROM busreq WHERE irequestid=? AND quorpo=? AND done=?;"
        action_answer = base_conn.execute(query2, [answer[0]['irequestid'], "Quote" if temp_quorpo == "q" else "Purchase", "1"]).fetchall()
        base_cur.close()
        base_conn.close()
        if (len(action_answer) > 0):
            for x in action_answer:
                results = action_cur.execute(query3, [x['concode'], x['pointguyid'], x['quorpo']]).fetchall()
                if len(results) != 0:
                    name = results[0]['quorpo'] + ' #%s'%results[0]['concod']
                    final_results.append({'title' : name , 'data' : results})
                else:
                    return """{}""".format("Zero items found"), 200
            action_cur.close()
            action_conn.close()
            if len(final_results) > 0:            
                return jsonify(final_results)     
            else:
                return """{}""".format("Zero items found"), 200
        else:
            return """{}""".format("Zero items found"), 200                  
    except:
        return page_not_found(request)    


