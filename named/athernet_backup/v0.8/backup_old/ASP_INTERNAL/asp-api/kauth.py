from tokandgen import generateNewUser, get_data_for_reg_users, checkTokenValidHandler, check_if_handler_exsits, check_if_bus_or_usr, get_data_for_reg_bus, generateTempBusiness
from pagerrors import forbbid_any, page_not_found
from misc import exchangePhonenumber, checkInput

def kauth(request):
    if not request.args:
        print(request.headers)
            # Super basic headers to try and prevent manipulation
        if (( request.headers.get('K1') == 'uAuPckSPmpWe</5|vwsa8X}**a_C*' ) and
           ( request.headers.get('Kk1') == 'alsndalsknf1241k2l4n12in4m1@$!@O$!@N$aslfkas' ) and 
           ( request.headers.get('Kkk1') == 'pbW@,DHA/e=Z?>IuBWCU%NBe!&ZUc>' ) and 
           ( request.headers.get('FromApp') == 'd2o3m2o32pmsfptmo')):


            # Auth based on a pre defined handler.
            if 'Handler' in request.headers:
                y1= (request.headers.get('PhoneNumber'))
                y2= (request.headers.get('AuthKey'))
                y3= (request.headers.get('Handler'))
                
                if ((y3 == 'T') and checkInput(y2) and checkInput(y3)):   

                    if y1.startswith('07'):
                        y1 = exchangePhonenumber(y1)
                        
                    if (checkTokenValidHandler(y1)):
                       
                        return check_if_handler_exsits(request,y1,y2)
                    else:
                        return page_not_found(request)                
                else:
                    return forbbid_any(request)
          
            # Generate a new user.
            elif 'vID' in request.headers:
                y1= (request.headers.get('Contactperson'))
                y2= (request.headers.get('Phonenumber'))
                y3= (request.headers.get('Password')) 
                y4= (request.headers.get('vID'))

                if (checkInput(y1) and checkInput(y2) and checkInput(y3) and checkInput(y4)):
                    if y2.startswith('07'):
                        y2 = exchangePhonenumber(y2)
                    return generateNewUser(request,y1,y2,y3,y4)
                else:
                    return forbbid_any(request)

            # Generate a new business after contact using PC_scripts/busenter.py
            elif 'TempUser' in request.headers:
                y1= (request.headers.get('Contactperson'))
                y2= (request.headers.get('Phonenumber'))
                y3= (request.headers.get('BusinessName')) 
                if (checkInput(y1) and checkInput(y2) and checkInput(y3) and checkInput(y4)):
                    if y2.startswith('07'):
                        y2 = exchangePhonenumber(y2)
                    return generateTempBusiness(y1,y2,y3)
                else:
                    return forbbid_any(request)  

            # Auth based on an already regesitered user or businesss.
            elif 'AlreadyAUser' in request.headers:
                y1= (request.headers.get('AlreadyAUser'))
                y2= (request.headers.get('Phonenumber'))
                y3= (request.headers.get('Password')) 
                if ( ( y1 == 'T' ) and checkInput(y2) and checkInput(y3)):
                    if y2.startswith('07'):
                        y2 = exchangePhonenumber(y2)
                    if check_if_bus_or_usr(request,y2) == "bus":
                        return get_data_for_reg_bus(request,y2,y3)
                    elif check_if_bus_or_usr(request,y2) == "usr":   
                        return get_data_for_reg_users(request,y2,y3)
                    else:
                        return forbbid_any(request)    
                else:
                    return forbbid_any(request)

            # Just deny the request.
            else:
                return forbbid_any(request)        
        else:
            return forbbid_any(request)      
    else:
        return page_not_found(request)     

