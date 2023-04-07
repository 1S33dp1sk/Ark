from itertools import cycle
import base64
from termcolor import colored

##################################### functions mainly for security #################################################################################################################################################################

def xor_crypt_string(data, key = 'w?7>.[*d6p@!3$rYLXX^s#Vxry64ZnuzcsnEjLTp-2scu!@hqRH}-vN*/jm2^&$TW*@5?t+TmVj*cqmFW*9$J2FB_qgQJEUaRD5p=?Z#*yUDSVH=g8KK9G3qgC9$xgNWm?V$aZztF#9S=gD7;)FzFC%RaU"SbKS5',encode = False, decode = False):

  if decode:
    data = base64.decodestring(data).decode('utf-8').strip()

  xored = ''.join(chr(ord(x) ^ ord(y)) for (x,y) in zip(data, cycle(key)))
   
  if encode:
    return base64.encodestring(xored.encode('utf-8')).strip()
  return xored


    # xor_crypt_string('secret_data', encode = True)
    
    # xor_crypt_string(xor_crypt_string('secret_data', encode = True), decode = True)

def sxor(s1,s2):    
    # convert strings to a list of character pair tuples
    # go through each tuple, converting them to ASCII code (ord)
    # perform exclusive or on the ASCII code
    # then convert the result back to ASCII (chr)
    # merge the resulting array of characters as a string
    return ''.join(hex(ord(a) ^ ord(b)) for a,b in zip(s1,s2))

def pre_security(request):

  print('req headers are ', request.headers)
  print("\nThe Following is the Requested Header : "+ colored(str(request.headers), 'yellow')+"\n")
  try:
    x = request.headers.get('User-Agent')
    if not str(x) == 'okhttp/3.12.1':
        print("IP OF REQUEST : "+ colored(request.remote_addr, 'green') +" and it is "+colored('DENIED', 'red')+"\n")
        return False
    else:
        if 'FromApp' in request.headers:
          if 'd2o3m2o32pmsfptmo' == request.headers.get('FromApp'):
            print("IP OF REQUEST : "+ colored(request.remote_addr, 'green') +" and it is "+colored('GRANTED ACCESS', 'green')+"\n")
            return True
          else:    
            return False   
        else:
            return False
  except:
      return False


