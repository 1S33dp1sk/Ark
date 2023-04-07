from web3 import Web3
import time

def _connectToWeb3(http_prov="https://bsc-dataseed.binance.org/"):
    return Web3(Web3.HTTPProvider(http_prov))

def getFromBSC():
	web3 = _connectToWeb3('https://bsc-dataseed.binance.org/')
	new_transaction_filter = web3.eth.filter('pending')
	new_transaction_filter.get_new_entries()

def getFromQuickNode():
	web3 = _connectToWeb3('https://misty-spring-shape.bsc.quiknode.pro/1868e88bab3092e7a96927c293d9241dd8282628/')
	new_transaction_filter = web3.eth.filter('pending')
	new_transaction_filter.get_new_entries()


def compare():
	start_time1 = time.time()
	getFromBSC()
	end_time1 = time.time()
	print(end_time1 - start_time1)
	start_time2 = time.time()
	getFromQuickNode()
	end_time2 = time.time()
	print(end_time2 - start_time2)
	if ((end_time2 - start_time2) > (end_time1 - start_time1)):
		return True
	else:
		return False

if __name__ == '__main__':
	t_val = 0
	f_val = 0
	for i in range(50):
		if compare():
			t_val += 1
		else:
			f_val += 1

	if t_val > f_val:
		print('Binance is Faster')
	else:
		print('QuickNode is Faster')
