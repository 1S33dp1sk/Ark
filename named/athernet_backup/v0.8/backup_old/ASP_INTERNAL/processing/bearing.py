import numpy as np
import pandas as pd
import re


excel_file = "tazweidServerStock.xlsx"
t_stock = pd.read_excel(excel_file, sheet_name='undone')
stock = t_stock.to_numpy()
mystock = stock.tolist()

def splitEQL(mystr):
	res = mystr.split('=')
	if len(res[1]) == 0:
		return None

	else:
		return(res[0],',='.join(i for i in res if i != res[0]))	


for i,n in enumerate(mystock):
	mystock[0] = n[2].replace(n[7],'')



# import xlsxwriter
# df = pd.DataFrame(mystock)
# writer = pd.ExcelWriter('mystock.xlsx',engine='xlsxwriter')
# df.to_excel(writer,sheet_name='undone',index=False)
# writer.save()