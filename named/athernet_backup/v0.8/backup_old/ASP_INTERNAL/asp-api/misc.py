import random
import sqlite3
ASP_FOLDER = "/home/kj/Desktop/.d/ASP_INTERNAL"

def dict_factory(cursor, row):
    d = {}
    for idx, col in enumerate(cursor.description):
        d[col[0]] = row[idx]
    return d


def strip_banned(x):
    return ''.join(e for e in x if e.isalnum())

def gencon():
    action_conn = sqlite3.connect(ASP_FOLDER+'/databases/action.db')
    action_conn.row_factory = dict_factory
    action_cur = action_conn.cursor()
    ogidx = action_cur.execute("""SELECT seq FROM sqlite_sequence WHERE name='requests'""").fetchall()[0]['seq']
    action_cur.close()
    action_conn.close()
    return str(ogidx+6959)


def exchangePhonenumber(pN):
    if (pN.startswith('079')):
        pN = pN.replace('079', '+96279')
    if (pN.startswith('078')):
        pN = pN.replace('078', '+96278')
    if (pN.startswith('077')):
        pN = pN.replace('077','+96277')  
    return pN

def checkInput(some_str):
    if (some_str != '' and some_str != None and some_str != 'NotFound' and some_str != 'undefined' and some_str != "null" and some_str != "Null"):
        return True
    else:
        return False    

def check_bus_or_user(type_name, type_value):
    query_users = """SELECT EXISTS (SELECT 1 FROM users WHERE %s=?);"""%type_name
    query_businesses = """SELECT EXISTS (SELECT 1 FROM businesses WHERE %s=?);"""%type_name
    to_filter = [type_value]

    conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    usr_result = cur.execute(query_users, to_filter).fetchall()
    bus_result = cur.execute(query_businesses, to_filter).fetchall()

    cur.close()
    conn.close()
    
    if (list(usr_result[0].values())[0]):
        return 'usr'
    elif (list(bus_result[0].values())[0]):
        return 'bus'
    else:
        return 'not registered'   

def ReArrangeData(old_data):
    new_data = []
    for i in old_data:
        item = i['item']
        new_data.append([item['partnumber'],item['partnumber'],item['quantity'],item['unit'],item['brand'],item['price'],str(int(item['quantity'])*int(item['price'])), item['delivery']])
    return new_data