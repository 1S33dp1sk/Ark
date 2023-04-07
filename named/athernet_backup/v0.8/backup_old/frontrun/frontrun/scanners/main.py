import json
from database import get_all_tokens



def scan_for_tokens(tokens_trig,tokens_addresses,raw_txns):
	for i in raw_txns:
		try:
			idx = tokens_addresses.index(i['contractCall']['params']['path'][-1])
			if 'amountOut' in i['contractCall']['params']:
				outmin = i['contractCall']['params']['amountOutMin']
			elif 'amountOutMin' in i['contractCall']['params']:
				outmin = i['contractCall']['params']['amountOutMin']
			else:
				pass
			if float(outmin)*1e-18 > float(tokens_trig[idx]):
				_createBuyOrder(tokens_addresses[idx])
			else:
				continue 
		except:
			continue


