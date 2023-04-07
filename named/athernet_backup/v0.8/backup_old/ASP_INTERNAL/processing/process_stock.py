import pandas as pd
import numpy as np

## Sample
## ref	     item     dimentions  ..  ..     category        brand ...
## 0           1          2       3    4        5             6     7
##[6178, '1202. KSM', '15X35X11', nan, nan, 'Self Aligning', 'KSM', nan]

#Get files
excel_file = "seals.xlsx"
bearings = pd.read_excel(excel_file, sheet_name='SEALS')
processed_bearings = bearings.to_numpy()
mylist = processed_bearings.tolist()

rest_data =[]
no_brand = []
no_category = []
no_regex = []
all_data = []


for i in mylist:
	all_data.append(i)

for i, n in enumerate(mylist):
	#Remove excel whitespaces
	n[1] = str(n[1]).strip()
	mylist[i] = n

for i in mylist:
	#Remove no brand bearigns
	if str(i[6]) == 'nan':
		no_brand.append(i)
	else:
		rest_data.append(i)

mylist = []
for i in rest_data:
	#Remove no category bearings
	if str(i[5]) == 'nan':
		no_category.append(i)
	else:
		mylist.append(i)

for i, n in enumerate(mylist):
	#Get Regex ready!
	n[2] = str(n[2]).upper().replace(' ','')
	n[5] = str(n[5]).upper().stip()
	mylist[i] = n

for i, n in enumerate(mylist):
	n[2] = n[2].replace(',','.')
	mylist[i] = n




rest_data = []
for i in mylist:
	#Regex for INNERXOUTERXWIDTH
	if len(re.findall(r'(\d*\.?\d*)X(\d*\.?\d*)X(\d*\.?\d*)', i[2])) == 1:
		rest_data.append(i)
	else:
		no_regex.append(i)

mylist = []

for i,n in enumerate(rest_data):
	n[5] = n[5].replace('BEARING','').strip()
	rest_data[i] = n



for i,n in enumerate(rest_data):
	if str(n[5]) == 'CARB TOROIDAL ROLLER':
		n[5] = 'CARB TOROIDAL'
		rest_data[i] = n
	elif str(n[5]) == 'TAPERD':
		n[5] = 'TAPERED'
		rest_data[i] = n
	elif str(n[5]) == 'CYLINDRECAL':
		n[5] = 'CYLINDRICAL'
		rest_data[i] = n
	elif str(n[5]) == 'BUSHINGS':
		n[5] = 'BUSHING'
		rest_data[i] = n
	elif str(n[5]) == 'SPHERICAL PAIN':
		n[5] = 'SPHERICAL PLAIN'
		rest_data[i] = n
	elif str(n[5]) == 'TRACK ROLLERS':
		n[5] = 'TRACK ROLLER'
		rest_data[i] = n
	elif str(n[5]) == 'FOR KLIFT':
		n[5] = 'FORKLIFT'
		rest_data[i] = n
	else:
		rest_data[i] = n	


for i,n in enumerate(rest_data):
	if str(n[5]) == 'INDEXING ROLLER UNITS':
		n[5] = 'CYLINDRICAL'
		n[7] = 'INDEXING ROLLER UNITS'
		rest_data[i] = n
	elif str(n[5]) == 'MAGNETO BALL':
		n[5] = 'MAGNETO'	
		n[7] = 'MAGNETO BALL BEARING'
		rest_data[i] = n
	elif str(n[5]) == 'SPHERICAL ROLLER THRUST':
		n[5] = 'THRUST'
		n[7] = 'SPHERICAL ROLLER THRUST'
		rest_data[i] = n
	elif str(n[5]) == 'CLUTCH ONE WAY':
		n[5] = 'CLUTCH'
		n[7] = 'CLUTCH ONE WAY'
		rest_data[i] = n
	elif str(n[5]) == 'CROSS ROLLER':
		n[5] = 'LINEAR'
		n[7] = 'CROSS ROLLER'
		rest_data[i] = n
	elif str(n[5]) == 'THRUST TAPERED':
		n[5] = 'THRUST'
		n[7] = 'THRUST TAPERED'
		rest_data[i] = n
	elif str(n[5]) == 'CAM ROLLER':
		n[5] = 'CAM'
		n[7] = 'CAM ROLLER'
		rest_data[i] = n
	elif str(n[5]) == 'CAM FOLLOWER':
		n[5] = 'CAM'
		n[7] = 'CAM FOLLOWER'
		rest_data[i] = n
	elif str(n[5]) == 'THRUST NEEDLE':
		n[5] = 'THRUST'
		n[7] = 'THRUST NEEDLE'
		rest_data[i] = n
	elif str(n[5]) == 'SPHERICAL PLAIN':
		n[5] = 'PLAIN'
		n[7] = 'SPHERICAL PLAIN'
		rest_data[i] = n
	elif str(n[5]) == 'INNER RING':
		n[5] = 'NEEDLE'
		n[7] = 'INNER RING'
		rest_data[i] = n
	elif str(n[5]) == 'LINEAR GUIDE RAIL':
		n[5] = 'LINEAR'
		n[7] = 'LINEAR GUIDE RAIL'
		rest_data[i] = n
	elif str(n[5]) == 'THRUST WASHER':
		n[5] = 'THRUST'
		n[7] = 'THRUST WASHER'
		rest_data[i] = n
	elif str(n[5]) == 'MINIATURE FLANGED BALL':
		n[5] = 'BALL'
		n[7] = 'MINIATURE FLANGED BALL'
		rest_data[i] = n
	elif str(n[5]) == 'CLUTCH RELEASE':
		n[5] = 'CLUTCH'
		n[7] = 'CLUTCH RELEASE'
		rest_data[i] = n
	else:
		rest_data[i] = n




import pandas as pd
import numpy as np


excel_file = "Tazweid_Original.xlsx"
t_stock = pd.read_excel(excel_file, sheet_name='Sheet1')
stock = t_stock.to_numpy()
mystock = stock.tolist()

def getCost(ref):
	for i in mystock:
		if i[0] == ref:
			return [i[6],i[7]]

def getDimentions(dims):
	return (re.findall(r'(\d*\.?\d*)X(\d*\.?\d*)X(\d*\.?\d*)', dims[2])[0])


#print(['', H[0],H[1],getDimentions(H)[0], getDimentions(H)[1], getDimentions(H)[2], H[5], H[6], '','',getCost(H[0])[0],'',H[7], getCost(H[0])[1]])

tazweidServerStock = []

for i in mylist:
	tazweidServerStock.append(['',str(i[0]),str(i[1]).replace(str(i[7]),'').strip(),str(getDimentions(i)[0]), str(getDimentions(i)[1]), str(getDimentions(i)[2]), str(i[5]), str(i[6]), '','',str(getCost(i[0])[0]), '', str('' if str(i[7]) == 'nan' else i[7]), str(getCost(i[0])[1])])








##[6178, '1202. KSM', '15X35X11', nan, nan, 'Self Aligning', 'KSM', nan]
to_stock = []

for i,n in enumerate(mylist):

	to_stock.append([])






#Categories
categories = []
for i in rest_data:
	if str(i[5]) != 'nan':
		categories.append(i[5])

categories = set(categories)
			





for i in mylist:
	if (str(i[2]) != 'nan' and str(i[5]) != 'nan'):
		data.append(i)
	else:
		undata.append(i)


mylist = []
dependents = []
not_bearings = []

for n in rest_data:
	if str(n[5]) == 'FORKLIFT' or str(n[5]) == 'SPINDLE S' or str(n[5]) == 'ROLLER  PREMIUM' or str(n[5]) == 'CNC' or str(n[5]) == 'AUTOMOTIVE':
		dependents.append(n)
	elif str(n[5]) == 'LAGER' or str(n[5]) == 'SIDE SEAL' or str(n[5]) == 'WASHER' or str(n[5]) == 'BUSHING':
		not_bearings.append(n)
	else:
		mylist.append(n)	

#Save to excel

import xlsxwriter
df = pd.DataFrame(rest_data)
writer = pd.ExcelWriter('rest_data.xlsx',engine='xlsxwriter')
df.to_excel(writer,sheet_name='undone',index=False)
writer.save()