import numpy as np
import pandas as pd
import re

excel_file = "tazweidServerStock.xlsx"
t_stock = pd.read_excel(excel_file, sheet_name='undone')
stock = t_stock.to_numpy()
mystock = stock.tolist()

def getCost(ref):
	for i in mystock:
		if i[0] == ref:
			return [i[6],i[7]]


excel_file = "belts.xlsx"
bearings = pd.read_excel(excel_file, sheet_name='BELT')
processed_bearings = bearings.to_numpy()
mylist = processed_bearings.tolist()

for i,n in enumerate(mylist):
	n[0] = str(n[0]).strip().replace('.0','')
	n[1] = str(n[1]).strip().upper()
	mylist[i] = n

#id,reference,partnumber,length,width,category,brand,suffix,
#prefix,cost,subcategory,special,quantity,noofteeth,pitch,profile


def getbrand(belt):
	brands =[
	"MITSUBA",
	"CONTITECH",
	"GOODYEAR",
	"SKF",
	"OPTIBELT",
	"GATES",
	"DYNA",
	"BLACK BELT",
	"ROFLEX",
	"DYNA",
	"DECO",
	"NADELLA",
	"PIX",
	"MEGADEN",
	"MITSOBOSHI",
	"FIRSTCAR",
	"SUPERBELT",
	"SANLUX",
	"POWER",
	"POWERSTAR",
	"MITSUBOUSHI",
	"HABASIT",
	"BARUM",
	"STRONGBELT",
	"DAYCO",
	"DONGIL",
	"KOREA",]
	for i in brands:
		if i in belt:
			return (i, belt.replace(i,'').strip())
	return ('NOBRAND',belt)		




pk_belts = []
rest_data = []


### OK ###
for i in mylist:
	if len(re.findall(r'(\d*)PK(\d*)', i[1])) > 0:
		pk_belts.append(i)
	else:
		rest_data.append(i)	



rest_data2 = []
sp_belts = []

for i in rest_data:
	if len(re.findall(r'(SP[A-Z]*)(\d*)', i[1])) > 0:
		sp_belts.append(i)
	else:	
		rest_data2.append(i)

rest_data = []
sp_cogged_belts = []

for i in rest_data2:
	if len(re.findall(r'(XP[A-Z]*)(\d*\.?\d)', i[1])) > 0:
		sp_cogged_belts.append(i)
	else:
		rest_data.append(i)	


rest_data2 = []
cogged_belts = []

for i in rest_data2:
	if len(re.findall(r'(^[A-Z]*)(\d*\.?\d)=(\d*\.?\d)X(\d*\.?\d)', i[1])) > 0:
		cogged_belts.append(i)
	else:
		rest_data.append(i)	



rest_data2 = []
vbelts = []

for i in rest_data:
	if len(re.findall(r'(^[A-Z]*)(\d*\.?\d)=(\d*\.?\d)X(\d*\.?\d)', i[1])) > 0:
		vbelts.append(i)
	else:
		rest_data2.append(i)

rest_data = []

for i in rest_data2:
	if len(re.findall(r'(^REC)(\d*\.?\d)X(\d*\.?\d)', i[1])) > 0:
		cogged_belts.append(i)
	else:
		rest_data.append(i)	




rest_data2 = []

for i in rest_data:
	if len(re.findall(r'(^\d*\.?\d)X(\d*\.?\d) ', i[1])) > 0:
		vbelts.append(i)
	else:
		rest_data2.append(i)

rest_data = []
wedge_belts = []

for i in rest_data2:
	if len(re.findall(r'(^\d*\.?\d)([VX]{2})(\d*\.?\d) ', i[1])) > 0:
		wedge_belts.append(i)
	else:
		rest_data.append(i)	

rest_data2 = []
timing_belts = []


for i in rest_data:
	if len(re.findall(r'(^\d*\.?\d)([a-zA-Z]+)(\d*\.?\d) ', i[1])) > 0:
		timing_belts.append(i)
	else:
		rest_data2.append(i)	

rest_data = []

for i in rest_data2:
	if len(re.findall(r'(^\D{1})(X)(\d*\.?\d)=(REC)(\d*\.?\d)X(\d*\.?\d)', i[1])) > 0:
		cogged_belts.append(i)
	else:
		rest_data.append(i)


for i,n in enumerate(timing_belts):
	if re.findall(r'(^\d*\.?\d)([a-zA-Z]+)(\d*\.?\d) ', n[1])[0][1] == "V":
		wedge_belts.append(n)
	else:
		rest_data.append(n)	





len(pk_belts)+len(sp_belts)+len(sp_cogged_belts)+len(cogged_belts)+len(vbelts)+len(wedge_belts)+len(timing_belts)


######################################## PK BELTS ################################################

# import xlsxwriter
# df = pd.DataFrame(pk_belts_done)
# writer = pd.ExcelWriter('pk_belts_done.xlsx',engine='xlsxwriter')
# df.to_excel(writer,sheet_name='undone',index=False)
# writer.save()

# pk_belts_done = []
# for i,n in enumerate(pk_belts):
# 	regexRef = re.findall(r'(\d*)PK(\d*)', n[1])[0]
# 	stockRef = getCost(int(n[0]))
# 	someid = ""
# 	ref = n[0]
# 	partnumber = n[1]
# 	length = regexRef[1]
# 	if regexRef[0] != "":
# 		width = str(3.56*float(regexRef[0]))
# 		noofteeth = regexRef[0]
# 	else:
# 		width = 0	
# 		noofteeth = 0
# 	category = "V"
# 	brand = getbrand(n[1])[0]
# 	suffix = ""
# 	prefix = ""
# 	try:
# 		cost = stockRef[0]
# 		quantity = stockRef[1]
# 	except:
# 		cost = 0
# 		quantity = 0	
# 	subcategory = "RIBBED"
# 	special = getbrand(n[1])[1].replace('PK').replace(str(length),'').replace(str(regexRef[0]),'')
# 	pitch = 3.56
# 	profile = 4.60
# 	pk_belts_done.append([someid, ref, partnumber, length, width, category, brand, suffix, prefix, cost,subcategory,special,quantity,noofteeth,pitch,profile])



###################################### SP BELTS ##############################################


# import xlsxwriter
# df = pd.DataFrame(sp_belts_done)
# writer = pd.ExcelWriter('sp_belts_done.xlsx',engine='xlsxwriter')
# df.to_excel(writer,sheet_name='undone',index=False)
# writer.save()


# def getSP(belt):
# 	height = ['8','10','13','18']
# 	width = ['9.7','12.7','16.3','22']
# 	if 'SPZ' in belt:
# 		return(height[0],width[0])
# 	elif 'SPA' in belt:
# 		return(height[1],width[1])
# 	elif 'SPB' in belt:
# 		return(height[2],width[2])
# 	elif 'SPC' in belt:
# 		return(height[3],width[3])
# 	else:
# 		return("0","0")		

# sp_belts_done = []
# for i,n in enumerate(sp_belts):
# 	regexRef = re.findall(r'(SP[A-Z]*)(\d*)', n[1])[0]
# 	stockRef= getCost(int(n[0]))
# 	hw = getSP(regexRef[0])
# 	someid = ""
# 	ref = str(n[0])
# 	partnumber = str(n[1])
# 	length = regexRef[1]
# 	if regexRef[0] != "":
# 		width = str(getSP(regexRef[0])[1])
# 	else:
# 		width =str(0)
# 	noofteeth = str(0)
# 	category = "V"
# 	brand = getbrand(n[1])[0]
# 	suffix = ""
# 	prefix = ""
# 	try:
# 		cost = stockRef[0]
# 		quantity = stockRef[1]
# 	except:
# 		cost = str(0)
# 		quantity = str(0)
# 	subcategory = "WEDGE"
# 	special = getbrand(n[1])[1].replace(regexRef[0],"").replace(str(length),'').replace(str(regexRef[0]),'')
# 	pitch = "0"
# 	profile = getSP(regexRef[0])[0]
# 	sp_belts_done.append([someid, ref, partnumber, length, width, category, brand, suffix, prefix, cost,subcategory,special,quantity,noofteeth,pitch,profile])








################################## SP COGGED BELTS ##################################################

# import xlsxwriter
# df = pd.DataFrame(sp_cogged_belts_done)
# writer = pd.ExcelWriter('sp_cogged_belts_done.xlsx',engine='xlsxwriter')
# df.to_excel(writer,sheet_name='undone',index=False)
# writer.save()

# def getXP(belt):
# 	height = ['8.5','10','13','18']
# 	width = ['9.7','12.7','16.3','22']
# 	if 'XPZ' in belt:
# 		return(height[0],width[0])
# 	elif 'XPA' in belt:
# 		return(height[1],width[1])
# 	elif 'XPB' in belt:
# 		return(height[2],width[2])
# 	elif 'XPC' in belt:
# 		return(height[3],width[3])
# 	else:
# 		return("0","0")		

# sp_cogged_belts_done = []
# for i,n in enumerate(sp_cogged_belts):
# 	regexRef = re.findall(r'(XP[A-Z]*)(\d*\.?\d)', n[1])[0]
# 	stockRef= getCost(int(n[0]))
# 	hw = getXP(regexRef[0])
# 	someid = ""
# 	ref = str(n[0])
# 	partnumber = str(n[1])
# 	length = regexRef[1]
# 	if regexRef[0] != "":
# 		width = str(getXP(regexRef[0])[1])
# 	else:
# 		width =str(0)
# 	noofteeth = str(0)
# 	category = "V"
# 	brand = getbrand(n[1])[0]
# 	suffix = ""
# 	prefix = ""
# 	try:
# 		cost = stockRef[0]
# 		quantity = stockRef[1]
# 	except:
# 		cost = str(0)
# 		quantity = str(0)
# 	subcategory = "COGGED-WEDGE"
# 	special = getbrand(n[1])[1].replace(regexRef[0],"").replace(str(length),'').replace(str(regexRef[0]),'')
# 	pitch = "0"
# 	profile = getXP(regexRef[0])[0]
# 	sp_cogged_belts_done.append([someid, ref, partnumber, length, width, category, brand, suffix, prefix, cost,subcategory,special,quantity,noofteeth,pitch,profile])






########################################### V BELTS ##########################################






import xlsxwriter
df = pd.DataFrame(mystock)
writer = pd.ExcelWriter('mystock.xlsx',engine='xlsxwriter')
df.to_excel(writer,sheet_name='undone',index=False)
writer.save()


# def getV(belt):
# 	height = ['6','8','11','14','20','23']
# 	width = ['10','13','17','22','32','38']
# 	if 'Z' in belt or '9.5' in belt:
# 		return(height[0],width[0])
# 	elif 'A' in belt or '13' in belt or '12.5' in belt:
# 		return(height[1],width[1])
# 	elif 'B' in belt or '17' in belt:
# 		return(height[2],width[2])
# 	elif 'C' in belt or '22' in belt:
# 		return(height[3],width[3])
# 	elif 'D' in belt or '32' in belt:
# 		return(height[4], width[4])	
# 	elif 'E' in belt or '38' in belt or '40' in belt:
# 		return(height[5],width[5])	
# 	else:
# 		return("0","0")		

# vbelts_done = []
# for i,n in enumerate(vbelts):
# 	if len(re.findall(r'(^[A-Z]*)(\d*\.?\d)=(\d*\.?\d)X(\d*\.?\d)', n[1])) > 0:
# 		regexRef = re.findall(r'(^[A-Z]*)(\d*\.?\d)=(\d*\.?\d)X(\d*\.?\d)', n[1])[0]
# 		first = True
# 	else:
# 		regexRef = re.findall(r'(^\d*\.?\d)X(\d*\.?\d) ', n[1])[0]
# 		first = False
# 	stockRef= getCost(int(n[0]))
# 	hw = getV(regexRef[0])
# 	someid = ""
# 	ref = str(n[0])
# 	partnumber = str(n[1])
# 	if first:
# 		length = regexRef[3]
# 	else:
# 		length = regexRef[1]
# 	if regexRef[0] != "":
# 		width = str(getV(regexRef[0])[1])
# 	else:
# 		width =str(0)
# 	noofteeth = str(0)
# 	category = "V"
# 	brand = getbrand(n[1])[0]
# 	suffix = ""
# 	prefix = ""
# 	try:
# 		cost = stockRef[0]
# 		quantity = stockRef[1]
# 	except:
# 		cost = str(0)
# 		quantity = str(0)
# 	subcategory = "CLASSICAL"
# 	special = getbrand(n[1])[1]
# 	pitch = "0"
# 	profile = getV(regexRef[0])[0]
# 	vbelts_done.append([someid, ref, partnumber, length, width, category, brand, suffix, prefix, cost,subcategory,special,quantity,noofteeth,pitch,profile])



################################## WEDGE BELTS ###########################################



