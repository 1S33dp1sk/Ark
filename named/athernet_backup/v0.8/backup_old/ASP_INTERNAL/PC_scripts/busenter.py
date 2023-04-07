import sqlite3
import random
import string
from collections import Counter

def dict_factory(cursor, row):
	d = {}
	for idx, col in enumerate(cursor.description):
		d[col[0]] = row[idx]
	return d


def sxor(s1,s2):    
    # convert strings to a list of character pair tuples
    # go through each tuple, converting them to ASCII code (ord)
    # perform exclusive or on the ASCII code
    # then convert the result back to ASCII (chr)
    # merge the resulting array of characters as a string
    return ''.join(hex(ord(a) ^ ord(b)) for a,b in zip(s1,s2))


def id_generator(size=23, chars=string.ascii_lowercase + string.digits):
	return ''.join(random.choice(chars) for _ in range(size))    

def assign_pointguy():
	conn = sqlite3.connect('/home/kj/Desktop/.d/ASP_INTERNAL/databases/base.db')
	conn.row_factory = dict_factory
	cur = conn.cursor()
	res = []
	x1 = cur.execute('SELECT pointguyid FROM users').fetchall()
	x2 = cur.execute('SELECT pointguyid FROM businesses').fetchall()
	for i in x1:
		res.append(list(i.values())[0])
	for j in x2:
		res.append(list(j.values())[0])
	x = Counter(['1','2','3','4','5','6','7','14','15','16','17'])	
	res = Counter(res)
	
	x.subtract(res)
	conn.close()
	return x.most_common(1)[0][0]

def get_id_max():
	conn = sqlite3.connect('/home/kj/Desktop/.d/ASP_INTERNAL/databases/base.db')
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


def enter_bus_into_db(busname, buslat, buslng, phonenumber, password, contactperson):
	conn = sqlite3.connect('/home/kj/Desktop/.d/ASP_INTERNAL/databases/base.db')
	conn.row_factory = dict_factory
	newID = int(get_id_max()) + 1
	token = id_generator()
	pointguyid = assign_pointguy()
	passwordVal = sxor(password,'akmfasf11rsd!@daidm#')
	cur = conn.cursor()
	cond = cur.execute(""" INSERT INTO businesses VALUES(?,?,?,?,?,NULL,?,?,?,?,?,?,?)""", (busname, buslat,buslat,newID,newID,newID,phonenumber, passwordVal, token, 'false', contactperson, pointguyid ))
	cond2 = cur.execute(""" INSERT INTO tokenlinksbusinesses VALUES(?, ?)""", (token, busname))
	conn.commit()
	conn.close()
	return 1


	
if __name__ == '__main__':
	print('\n ############################################ ENTER BUSINESS INTO DATABASE ############################################### \n')
	busname = input('\n Business name? \n')
	buslat = input('\n Business location lattitude? \n')
	buslng = input('\n Business location longitude? \n')
	phonenumber = input('\n Phonenumber? \n')
	password = input('\n Password? \n')
	contactperson = input('\n contactperson name? \n')
	if(enter_bus_into_db(busname, buslat, buslng, phonenumber, password, contactperson)):
		print('Business Added successfully!')		
	else: 
		print('ERROR! please try again!')	
