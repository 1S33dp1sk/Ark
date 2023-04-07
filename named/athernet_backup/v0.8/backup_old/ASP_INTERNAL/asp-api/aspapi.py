from flask import request, jsonify, send_file, send_from_directory,g, Flask
import sqlite3
import os
import random
import string
import time
import datetime
from termcolor import colored
from ssencss import xor_crypt_string, sxor,pre_security
from datetime import datetime
from pagerrors import page_not_found, internal_error, forbbid_any
from misc import dict_factory, strip_banned, gencon
from tokandgen import checkTokenValid, admin_login
from kauth import kauth
from pricing import priceit
from client import client_api
from manager import manager_api


app = Flask(__name__)

ASP_FOLDER = "/home/kj/Desktop/.d/ASP_INTERNAL"

app.config["MAIN_IMGS"] = ASP_FOLDER+"/MAIN_IMGS/"
app.config["CAR_IMGS"] = ASP_FOLDER+"/CAR_IMGS/"
app.config["LIST_IMGS"] = ASP_FOLDER+"/img_list"
app.config["CATEGORY_IMGS"] = ASP_FOLDER+"/CATEGORIES_LIST/"
app.config["BRAND_IMGS"] = ASP_FOLDER+"/BRAND_IMGS"
app.config["IND_IMGS"] = ASP_FOLDER+"/LIST_IMGS"


app.register_blueprint(client_api, url_prefix='/api/v1/<key>/cust')
app.register_blueprint(manager_api, url_prefix='/api/v1/<key>/bus/side/serv')

app.register_error_handler(404, page_not_found)
app.register_error_handler(500, internal_error)
app.register_error_handler(403, forbbid_any)




############################## HOME DIRECTORY #################################

########################## HTTPS://WWW.ASP-API.COM/ ###########################
@app.route('/', methods=['GET'])
def home():
   return '''Welcome to Aftermarket Spare Parts API'''
   # if( pre_security(request) ):
   #     return main_ASP_functions()
   # else:
   #     return page_not_found(request)    



@app.route('/kauth/', methods=['GET'])
def mainAuth():
    return kauth(request)
    

@app.route('/api/v1/admin/login', methods=['POST'])
def adminLogin():
    u_name = request.form['username']
    u_pass = request.form['password']:
    if u_name and u_pass:
        return admin_login(request,u_name,u_pass)
    return page_not_found(request)


############################ USING PARTS.DB #####################################
### GET ALL PARTS

@app.route('/api/v1/<key>/resources/parts/<category>', methods=['GET'])
def api_parts_all(key, category):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request)        
    conn = sqlite3.connect(ASP_FOLDER+'/databases/parts.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    cookie_id = request.cookies.get('adminLOGIN')
    if category.lower() == 'all':
        if not cookie_id == 'smdm3d1dkpg5g34ttgsdgDGs':
            all_parts = cur.execute('SELECT category,id,partnumber,ref FROM oldstock ORDER BY RANDOM() LIMIT 25;').fetchall()
        else:
            all_parts = cur.execute('SELECT * FROM oldstock ORDER BY RANDOM() LIMIT 25;').fetchall()
    else:
        if not cookie_id == 'smdm3d1dkpg5g34ttgsdgDGs':
            all_parts = cur.execute('SELECT category,id,partnumber,ref FROM oldstock WHERE category=? ORDER BY RANDOM() LIMIT 25;', (category.capitalize(),)).fetchall()
        else:
            all_parts = cur.execute('SELECT * FROM oldstock WHERE category=? ORDER BY RANDOM() LIMIT 25;', (category.capitalize(),)).fetchall()

    conn.close()
    return jsonify(all_parts)

### GET CURRENT PART LOOKUP

@app.route('/api/v1/<key>/search/resources/parts', methods=['GET'])
def api_parts_specific(key):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request)  

    cookie_id = request.cookies.get('adminLOGIN')
    currentdesignation = request.args['c']
    if not cookie_id == 'smdm3d1dkpg5g34ttgsdgDGs':
            query = '''SELECT category,id,partnumber,ref FROM oldstock WHERE partnumber LIKE '%'''+currentdesignation+'''%';'''
        else:
            query = '''SELECT * FROM oldstock WHERE partnumber LIKE '%'''+currentdesignation+'''%';'''

    conn = sqlite3.connect(ASP_FOLDER+'/databases/parts.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    try:       
        current_part_query = cur.execute( query ).fetchall()
        conn.close()
    except:
        return page_not_found(request)    
    if len(current_part_query) > 0:
        return jsonify(current_part_query)
    else:
        return page_not_found(request)    


@app.route('/api/v1/<key>/submit/notify', methods=['GET'])
def api_set_notification_token(key):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request)
    uorb = request.args.get('uorb').strip()
    if  uorb == "user":
        query = """UPDATE users SET notificationtoken=? WHERE token=?;"""
    elif uorb == "business":
        query = """UPDATE businesses SET notificationtoken=? WHERE token=?;"""
    else:
        return page_not_found(request)  
    try:      
        possible_token = request.headers.get('notify')
        token = possible_token.replace('uAuPckSPmpWe</5|vwsa8X}**a_C','').replace('2l4n12in4m1@$!@O$!@N$aslfkas','')
        
        conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
        conn.row_factory = dict_factory
        cur = conn.cursor()
        cur.execute(query, [possible_token, key])
        conn.commit()
        cur.close()
        conn.close()
        return '''{}'''.format('notification token added successfully'), 200
    except:
        return page_not_found(request)     



# @app.route('/api/v1/<key>/send/notification', methods=['POST'])
# def api_notify_concerns(key):
#     g.key = key
#     if not checkTokenValid(key):
#         return page_not_found(request)

#     uorb = request.args.get('uorb').strip()
#     if  uorb == "user":
#         query = """SELECT pointguyid from users WHERE token=?;"""
#     elif uorb == "business":
#         query = """SELECT pointguyid from businesses WHERE token=?;"""
#     else:
#         return page_not_found(request)  

#     if request.is_json:
#             jsonData = request.get_json()
#             for x in jsonData:
#                 noti_from = x['from']
#                 noti_sound = x['sound']
#                 noti_title = x['title']
#                 noti_body = x['body']
#                 noti_data = x['data']
#                 if 'quotation' in noti_title.lower() or 'purchase' in noti_title.lower():
#                     try:
#                         conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
#                         conn.row_factory = dict_factory
#                         cur = conn.cursor()
#                         result = cur.execute(query,[key]).fetchall()
#                         mypointguyid = result[0]['pointguyid']
#                         pointidToken = cur.execute("""SELECT notificationtoken from handlers WHERE id=?;""",[mypointguyid]).fetchall()
#                         pointidToken = pointidToken[0]['notificationtoken']
#                         return sendQorPoNotification(request, pointidToken, noti_sound, noti_title, noti_body, noti_data)
#                     except:
#                         return page_not_found(request)
#                 else:
#                     return page_not_found(request)
#     else:
#         return page_not_found(request)


############################ USING INDUSTRIAL.DB #####################################

# Function is used for BOTH

'''
This function is used for to fetch images for industrial images.

'''

    ############################  APIS FOR IMAGES  ##############################


@app.route('/api/v1/<key>/resources/industrial/<req>', methods=['GET'])
def api_industrial_all(key, req):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request)  

    req_list = [
    'categories',
    'Accessories',
    'Adhesive',
    'Bearings',
    'Belts',
    'Bushings',
    'Chain',
    'Grease',
    'Housing',
    'Conveyor',
    'Instruments',
    'Oil',
    'Pullies',
    'Seals',
    'Sprockets',
    'Tools',
    ]
    try:
        if req in req_list:
            conn = sqlite3.connect(ASP_FOLDER+'/databases/industrial.db')
            conn.row_factory = dict_factory
            cur = conn.cursor()
            query = "SELECT * FROM %s;"%req
            results = cur.execute(query).fetchall()
            conn.close()

            return jsonify(results)
        else:
            return page_not_found(request)   
    except:
        return page_not_found(request)        
        
#############################################################################################

@app.route('/api/v1/<key>/resources/img/logo', methods=['GET'])
def api_get_cars_logo_imgs(key):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request)
    if not request.args.get('id').isdigit():
        return page_not_found(request)   
    else:
        xid = request.args.get('id')
        xid = xid+ '.png'
        try:
            return send_from_directory(app.config["MAIN_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)

#############################################################################################

@app.route('/api/v1/<key>/resources/img/car/<req>', methods=['GET'])
def api_get_car_parts_imgs(key, req):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 
    req_list = [
    'bearings',
    'belts',
    'brakepads',
    'filters',
    'oils',]

    img_req_list =[
    'bearings_image_transparent.png',
    'drive_belts_image_transparent.png',
    'brake_pads_image_transparent.png',
    'filters_image_transparent.png',
    'oil_image_transparent.png']
    try:
        idx = req_list.index(req)
        xid = img_req_list[idx]
        try:
            return send_from_directory(app.config["LIST_IMGS"], filename=xid, as_attachment=False)
        except:
            return page_not_found(request)
    except :
        return page_not_found(request)        

#############################################################################################

@app.route('/api/v1/<key>/imgs/<req>', methods=['GET'])
def api_get_v1imgs(key, req):

    req_list = [
    'teRb0WyhUutngQ6uCzOoVe',
    '6ttTGDmGf2E9q7QcxFX1re',
    'nThhMbgOicBLvMHWjPzJmB',
    'kMKNgswgmZbCHbc8DVEZ8Y',
    'TH9c24ye1qrDv5PXycfGiU',
    '6jkquWSDFRnOP2Sb1KDgST',
    'Bf2wo634bmYC7Pfc46DdZz',
    'zj2HYRyd05SIjWvQnjlrwH',
    'cwgdqTQZyhfwHTjy0Lse3z',
    '4nwzdmB82kRCBqS61PiDd9',
    'sHIqOYWfgEGcDgInRYdeGM',
    '0imJ5lhrFIPgyBzU0Ue7XK',
    'IuP5XrqOSuErSt5x6Fx7OZ',
    'zXi7ORIGteYjkrwMfJxkUp',
    'zXi7ORIGteYjkrwMfJxkUpDrawing',
    'lbEU204gNFSjHkc2i2jq8t',
    'lbEU204gNFSjHkc2i2jq8tDrawing', 
    's5rpNuhRtr4WsnYrC0UgHS',
    's5rpNuhRtr4WsnYrC0UgHSDrawing',
    'VOaiCXYNHdk3tdZDKpyvSH',
    'VOaiCXYNHdk3tdZDKpyvSHDrawing',
    'mDTtl1iBuBS3mIQN13tlwv',
    'mDTtl1iBuBS3mIQN13tlwvDrawing',
    'K4JYAQHyB42Iv6e1ODVCYJ', 
    'K4JYAQHyB42Iv6e1ODVCYJDrawing', 
    '8EjCJ9uQGDgvJHBYR9pvfd',
    '8EjCJ9uQGDgvJHBYR9pvfdDrawing',
    'PJGVOgnyeVOi4ZiDVO1pAM',
    'PJGVOgnyeVOi4ZiDVO1pAMDrawing',
    'NQMaWtavT7sIx02OAOQoXJ',
    'NQMaWtavT7sIx02OAOQoXJDrawing',
    'uQFdRlAij35DvdSAbpWq9G', 
    'uQFdRlAij35DvdSAbpWq9GDrawing', 
    'O2TmS72ek5jlL4zCMn5GIz',
    'O2TmS72ek5jlL4zCMn5GIzDrawing',
    'AR7Ah1fLybR4esJojPShou',
    'AR7Ah1fLybR4esJojPShouDrawing',
    'XfVhZwuv6bl2V5GiHrSjcr',
    'XfVhZwuv6bl2V5GiHrSjcrDrawing',
    'ttEJS3meKEh9wy7O1ugFLB',
    'ttEJS3meKEh9wy7O1ugFLBDrawing',
    'tWoxxk7xxEdWT8anvUxM7V',
    'tWoxxk7xxEdWT8anvUxM7VDrawing',
    ]

    img_req_list =[
    'bearings.jpg',
    'belts.jpg',
    'seals.jpg',
    'housing.jpg',
    'conveyor.jpg',
    'accessories.jpg',
    'chains.jpg',
    'sprockets.jpg',
    'bushings.jpg',
    'tools.jpg',
    'instruments.jpg',
    'adhesives.jpg',
    'pullies.jpg',
    'Deep_groove.png',
    'deep_groove_drawing.jpg',
    'Cylindrical.png',
    'cylindircal_drawing.jpeg',
    'Spherical.jpg',
    'spherical_drawing.jpeg',
    'Angular.png',
    'angular_contact_drawing.jpeg',
    'Self_Aligning.png',
    'self_aligning_drawing.jpeg',
    'CARB.png',
    'carb_drawing.jpeg',
    'Tapered.png',
    'tapered_drawing.jpeg',
    'Needle.png',
    'needle_drawing.jpeg',
    'Y_bearing.png',
    'insert_bearing_drawing.jpeg',
    'Thrust.jpg',
    'thrust_drawing.jpeg',
    'Cam.png',
    'cam_follower_drawing.jpeg',
    'Rod.png',
    'rod_end_drawing.png',
    'One_Way.png',
    'Linear.jpg',
    'linear_bearing_drawing.jpeg',
    'Plain.png',
    'plain_bearing_drawing.jpeg', ]

    try:
        idx = req_list.index(req)
        xid = img_req_list[idx]
        try:
            return send_from_directory(app.config["IND_IMGS"], filename=xid, as_attachment=False)
        except:
            return page_not_found(request)
    except:
        return page_not_found(request)    

#############################################################################################

@app.route('/api/v1/<key>/resources/img/cars', methods=['GET'])
def api_get_car_imgs(key):

    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 
    if not request.args.get('id').isdigit():
        return page_not_found(request)
    else:    
        xid = request.args.get('id')
        xid = xid+ '.png'
        try:
            return send_from_directory(app.config["CAR_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)

#############################################################################################

@app.route('/api/v1/<key>/resources/img/bearings/<req>', methods=['GET'])
def api_get_bearings_imgs(key, req):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 

    req_list = [
    'ball',
    'tapered',
    'angular',
    'spherical',
    'self-aligning',
    'needle',
    'carb',
    'linear',
    'cylindrical']

    img_req_list = [
    'deep-groove.png',
    'tapered.png',
    'angular-contact.png',
    'spherical.png',
    'self-aligning.png',
    'needle.png',
    'carb.png',
    'linear.png',
    'cylindrical.png']

    try:
        idx = req_list.index(req)
        xid = img_req_list[idx] 
        try:
            return send_from_directory(app.config["CATEGORY_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)  
    except:
        return page_not_found(request)              

#############################################################################################

@app.route('/api/v1/<key>/resources/img/belts/<req>', methods=['GET'])
def api_get_belts_imgs(key, req):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 

    req_list = [
    'v-belt',
    'conveyorbelt',
    ]

    img_req_list = [
    'v-belt.png',
    'conveyor-belt.png',
    ]

    try:
        idx = req_list.index(req)
        xid = img_req_list[idx] 
        try:
            return send_from_directory(app.config["CATEGORY_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)  
    except:
        return page_not_found(request) 

#############################################################################################

@app.route('/api/v1/<key>/resources/img/oilandgrease/', methods=['GET'])
def api_get_oilandgrease_imgs(key):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 

    req_list = [
    'oil',
    'grease',
    ]

    img_req_list = [
    'oil.jpg',
    'grease.png',
    ]

    try:
        idx = req_list.index(req)
        xid = img_req_list[idx] 
        try:
            return send_from_directory(app.config["CATEGORY_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)  
    except:
        return page_not_found(request) 

#############################################################################################        


@app.route('/api/v1/<key>/resources/img/brands/<req>', methods=['GET'])
def api_get_brands_logos_imgs(key,req):
    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 
    req_list = [
    'conti',
    'skf',
    'timken',
    'fbj',
    'nsk',
    'mitsuba',
    'iko',
    'jns',
    'ina',
    'dongil',
    'asp',
    'tazweid',
    'pioneers', 
    ]
    if req in req_list:
        xid = '%s.png'%req
        try:
            return send_from_directory(app.config["BRAND_IMGS"],filename=xid, as_attachment=False)
        except FileNotFoundError:
            return page_not_found(request)   
    else:
        return page_not_found(request)        



@app.route('/api/v1/<key>/resources/industrial/<req>/props', methods=['GET'])
def api_get_sub_category_props(key,req):

    req_list = [
    'zXi7ORIGteYjkrwMfJxkUp',
    'lbEU204gNFSjHkc2i2jq8t',
    's5rpNuhRtr4WsnYrC0UgHS',
    'VOaiCXYNHdk3tdZDKpyvSH',
    'mDTtl1iBuBS3mIQN13tlwv',
    'K4JYAQHyB42Iv6e1ODVCYJ', 
    '8EjCJ9uQGDgvJHBYR9pvfd',
    'PJGVOgnyeVOi4ZiDVO1pAM',
    'NQMaWtavT7sIx02OAOQoXJ',
    'uQFdRlAij35DvdSAbpWq9G', 
    'O2TmS72ek5jlL4zCMn5GIz',
    'AR7Ah1fLybR4esJojPShou',
    'XfVhZwuv6bl2V5GiHrSjcr',
    'ttEJS3meKEh9wy7O1ugFLB',
    'tWoxxk7xxEdWT8anvUxM7V', ]

    props_req_list =[
    [ {'inner(d)': 'any'},  {'outer(D)': 'any'},  {'width(B)': 'any'}, {'sealing': ['metal', 'rubber', 'none']}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'},  {"cone":["Two way", "One Way", "none"]}, {"cage":["Polymide","brass","steel"]}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'},  {"taper":{"yes","no"}}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'},  {"angle":["15","25","45"]}, {"surface cage":["Polymide","brass","steel"]}, {"preload class":["light","normal","heavy"]},{"arrangment":["Single", "Double Face-To-Face", "Double Back-To-Back", "Double Tandem"]}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'},  {"taper":["yes","no"]}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'},  {"taper":["yes","no"]}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [  {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    [ {'inner': 'any'},   {'outer': 'any'},  {'width': 'any'}],
    ]

    try:

        idx = req_list.index(req)
        xid = props_req_list[idx]
        try:
            return jsonify(xid)
        except:
            return page_not_found(request)
    except:
        return page_not_found(request)   


#############################################################################################






########################### USING automotive.db ########################################


@app.route('/api/v1/<key>/resources/cars/all', methods=['GET'])
def api_cars_all(key):

    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 
    conn = sqlite3.connect(ASP_FOLDER+'/databases/automotive.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()
    results = cur.execute('SELECT * FROM main;').fetchall()
    conn.close()
    return jsonify(results)

@app.route('/api/v1/<key>/resources/cars', methods=['GET'])
def api_filter(key):

    g.key = key
    if not checkTokenValid(key):
        return page_not_found(request) 

    query_parameters = request.args
    idx = query_parameters.get('linkid')

    query = "SELECT * FROM main WHERE id=?"
    to_filter = []
    if idx:
        if (idx.isdigit()):
            to_filter.append(idx)
        else:
            return page_not_found(request)
    else:
        return page_not_found(request)
    query = query[:-4] + ';'

    conn = sqlite3.connect(ASP_FOLDER+'/databases/automotive.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    results = cur.execute(query, to_filter).fetchall()
    conn.close()
    return jsonify(results)

@app.route('/api/v1/<key>/resources/cars/subs', methods=['GET'])
def api_filter_subs(key):

    g.key = key
    if not checkTokenValid(key):
        return forbbid_any(request) 
    query_parameters = request.args

    temp_id = query_parameters.get('linkid')

    query = "SELECT * FROM sub WHERE linkid=?;"

    if (temp_id.isdigit()):
        to_filter = [temp_id]
    else:
        return page_not_found(request)
        

    conn = sqlite3.connect(ASP_FOLDER+'/databases/automotive.db')
    conn.row_factory = dict_factory
    cur = conn.cursor()

    results = cur.execute(query, to_filter).fetchall()
    conn.close()
    return jsonify(results)

#############################################################################################



##### admin@uba.com.jo --razan -ERP 
##### wewebit.. --PHP
##### careers@qbs.jo  --Dina   -MVC and FrontEND
##### rshihadeh@optimizasolutions.com --rana 
##### yazan.sbeih@teklabz.com -- JAVA class -> JIS expret 
##### mona.attieh@prema.consulting   -- IT SOULTIONS FOR BANKS
##### zeina 0775555991 -- SYS ADMIN -LINUX BASED  -- Zhanbali@e2abs.com




