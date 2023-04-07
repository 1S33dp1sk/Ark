##########################################################################################################
#                                          You need HTTP2 TO CREATE This                                 #
#                                     ..Reconsider flask and everything else..                           #
#                      ...Quart and others are vaiable options, for now lets stick with expo...          # 
##########################################################################################################




# from flask import jsonify
# import json
# import requests
# import jwt
# import time


# FCM_SERVER_KEY = "AAAAOFFivlQ:APA91bHU1gST49q-0nwzzjT3XUSAuG6EIsQoOYAgRi2T6kuLjbRPv8QadL8iFRsX67Xdsz7c3XcllHJIM3X-RTl_kzltsH0BL3LyhIClox2kzD3HRuShFsQX0Yf1Ofw_cBsHNm1QqEPs"
# EXPERIENCE_ID = "@karammarrie/projectSlug"
# APPLE_P_EIGHT_KEY_ID = "82JCGF6X3X"
# APPLE_TEAM_ID = "98DKY73WW9"
# APPLE_CLIENT_ID = "com.djoure.tazweid"


# def getKeyFromFile():
#     with open('AuthKey_82JCGF6X3X.p8', 'r') as fin:
#         APPLE_P_EIGHT_KEY = fin.read().strip()
#     return APPLE_P_EIGHT_KEY

# def sendQorPoNotification(request, pointidToken, noti_sound, noti_title, noti_body, noti_data):

#     return page_not_found(request)

# def sendToGoogleFCM(devicePT, notiTitle, notiMessage):
#     URL = "https://fcm.googleapis.com/fcm/send"
#     PARAMS = {'method':'POST', 'headers':{'Content-Type': 'application/json', 'Authorization' : 'key=%s'%FCM_SERVER_KEY },
#     'body': json.dumps({'body': {'to' : '%s'%devicePT, 'priority': 'normal', 'data':{'experienceId':'%s'%EXPERIENCE_ID,
#     'title':"%s"%notiTitle,'message': '%s'%notiMessage, }}})}
#     r = requests.post(url=URL, params=PARAMS)
#     return print(r.json())





# def authWithAppleAPN():
#   APPLE_P_EIGHT_KEY = getKeyFromFile()
#   headers = {
#     'kid': "%s"%APPLE_P_EIGHT_KEY_ID
#   }

#   payload = {
#     'iss': "%s"%APPLE_TEAM_ID,
#     'iat': time.time(), 
#     'exp': time.time()+8000000,
#     'aud': 'https://appleid.apple.com',
#     'sub': "%s"%APPLE_CLIENT_ID
#   }
#   authorizationToken = jwt.encode(
#     payload,

#     algorithm='ES256', 
#     headers=headers
#     ).decode("utf-8")


  



# def sendToAppleAPN(devicePT, jsonWebTokenAPN, notiTitle, notiMessage):
#     APPLE_P_EIGHT_KEY = getKeyFromFile()

# const http2 = require('http2');

# const client = http2.connect(
#   IS_PRODUCTION ? 'https://api.push.apple.com' : 'https://api.sandbox.push.apple.com'
# );

# const request = client.request({
#   ':method': 'POST',
#   ':scheme': 'https',
#   'apns-topic': '%s'%APPLE_CLIENT_ID,
#   ':path': '/3/device/' + devicePT, # This is the native device token you grabbed client-side
#   authorization: `bearer ${jsonWebTokenAPN}`, # This is the JSON web token we generated in the "Authorization" step above
# });
# request.setEncoding('utf8');

# request.write(
#   JSON.stringify({
#     aps: {
#       alert: {
#         title: "%s"%notiTitle,
#         body: '%s'%notiMessage,
#       },
#     },
#     experienceId: '%s'%EXPERIENCE_ID, # Required when testing in the Expo client app
#   })
# );
# request.end();





# # Android : 
# # {
# #   "token": native device token string,
# #   "collapse_key": string that identifies notification as collapsable,
# #   "priority": "normal" || "high",
# #   "data": {
# #     "experienceId": "@yourExpoUsername/yourProjectSlug",
# #     "title": title of your message,
# #     "message": body of your message,
# #     "channelId": the android channel ID associated with this notification,
# #     "categoryId": the category associated with this notification,
# #     "icon": the icon to show with this notification,
# #     "link": the link this notification should open,
# #     "body": { object of key-value pairs }
# #   }
# # }



# # iOS :
# # {
# #   "aps": {
# #     "alert": {
# #       "title": title of your message,
# #       "subtitle": subtitle of your message (shown below title, above body),
# #       "body": body of your message,
# #       "launch-image": the name of the launch image file to display,
# #     },
# #     "category": the category associated with this notification,
# #     "badge": number to set badge count to upon notification's arrival,
# #     "sound": the sound to play when the notification is received,
# #     "thread-id": app-specific identifier for grouping related notifications
# #   },
# #   "body": { object of key-value pairs },
# #   "experienceId": "@yourExpoUsername/yourProjectSlug",
# # }



##################################################################################################################
#python functions for aspapi.py


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





# @app.route('/api/v1/<key>/submit/notify', methods=['GET'])
# def api_set_notification_token(key):
#     g.key = key
#     if not checkTokenValid(key):
#         return page_not_found(request)
#     uorb = request.args.get('uorb').strip()
#     if  uorb == "user":
#         query = """UPDATE users SET notificationtoken=? WHERE token=?;"""
#     elif uorb == "business":
#         query = """UPDATE businesses SET notificationtoken=? WHERE token=?;"""
#     else:
#         return page_not_found(request)  
#     try:      
#         possible_token = request.headers.get('notify')
#         token = possible_token.replace('uAuPckSPmpWe</5|vwsa8X}**a_C','').replace('2l4n12in4m1@$!@O$!@N$aslfkas','')
        
#         conn = sqlite3.connect(ASP_FOLDER+'/databases/base.db')
#         conn.row_factory = dict_factory
#         cur = conn.cursor()
#         cur.execute(query, [possible_token, key])
#         conn.commit()
#         cur.close()
#         conn.close()
#         return '''{}'''.format('notification token added successfully'), 200
#     except:
#         return page_not_found(request)     
