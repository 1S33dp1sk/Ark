import pandas as pd
import numpy as np


excel_file = "seals.xlsx"
bearings = pd.read_excel(excel_file, sheet_name='SEALS')
processed_bearings = bearings.to_numpy()
mylist = processed_bearings.tolist()


# Remove whitespaces
for i,n in enumerate(mylist):
	n[0] = str(n[0]).strip()
	n[1] = str(n[1]).strip()
	mylist[i] = n

# Start by getting the regex

regexed = []
rest_data = []


for i in mylist:
	if len(re.findall(r'(\d*\.?\d*)X(\d*\.?\d*)X(\d*\.?\d*)', i[1])) == 1:
		regexed.append(i)
	else:
		rest_data.append(i)	
		

def getDims(oilseal):
	dims = re.findall(r'(\d*\.?\d*)X(\d*\.?\d*)X(\d*\.?\d*)', oilseal)[0]
	for i in dims:
		oilseal = oilseal.replace(i,'')
	oilseal = oilseal.replace('X','')	
	return oilseal

def getBrand(oilseal):
	brands = [
	"SOG",
	"TIMKEN",
	"SKF", 
	"TTO",
	"NATIONAL",
	"MG", 
	"SUPTEX",
	]
	for i in brands:
		oilseal = oilseal.replace(i,'')
	return oilseal

def getType(oilseal):
	keywords = [
	"TC",
	"SC",
	"TA", 
	"TB", 
	]	
	for i in keywords:
		oilseal = oilseal.replace(i,'')
	return oilseal
					


for i,n in enumerate(regexed):






