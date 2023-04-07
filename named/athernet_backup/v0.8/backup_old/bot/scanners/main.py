import json
from database import get_all_tokens


blocknative_key = 'aba9ed1b-268a-4615-9243-686fe2a8e8d2'

def scan_for_tokens(raw_txns):
	# we should implement this outside this function for faster processing
	tokens = get_all_tokens()
	tokens_trig = []
	tokens_addresses = []
	for i in tokens:
		tokens_trig.append(tokens[-1])
		tokens_addresses.append(tokens[-2])

	for i in raw_txns:
		try:
			idx = tokens_addresses.index(i['contractCall']['params']['path'][1])
			if float(i['contractCall']['params']['amountOutMin'])*1e-18 > float(tokens_trig[idx]):
				_createBuyOrder(tokens_addresses[idx])
			else:
				continue 
		except:
			continue


curl -X POST -H "Content-Type: application/json" -d '{"apiKey":"aba9ed1b-268a-4615-9243-686fe2a8e8d2","address":"0x05ff2b0db69458a0750badebc4f9e13add608c7f","blockchain":"ethereum","networks":["bsc-main"]}' https://api.blocknative.com/address 
curl -X POST -H "Content-Type: application/json" -d '{"apiKey":"aba9ed1b-268a-4615-9243-686fe2a8e8d2","address":"0x10ed43c718714eb63d5aa57b78b54704e256024e","blockchain":"ethereum","networks":["bsc-main"]}' https://api.blocknative.com/address 


https://api.blocknative.com/transaction/aba9ed1b-268a-4615-9243-686fe2a8e8d2/ethereum/bsc-main/