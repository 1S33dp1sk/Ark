import json
import requests
from database import get_all_tokens,create_connection
from helpers import _getContractDecimals,_connectToWeb3
from helpers.constants import ps_swap_addr,ps_abi
from web3 import Web3
from core.trader import _createBuyOrder
import time

def get_token_addr_and_trig():
	conn = create_connection()
	tokens = get_all_tokens(conn)
	token_addresses = []
	token_triggers = []
	token_decimals = []
	token_prices = []
	for i in tokens:
		token_decimals.append(i[-1])
		token_triggers.append(float(i[-2])/float(i[-4]))
		token_addresses.append(i[-3])
		token_prices.append(i[-4])
	return token_decimals,token_triggers,token_addresses,token_prices

def get_token_price_usd(token_address):
	'''
		Returns price as a string
	'''
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price']

def get_token_price_bnb(token_address):
	'''
		Returns price as a string
	'''
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price_BNB']

class Core:
	def __init__(self,web3QN,web3BSC,b_amnt,s_addr,p_key):
		self.web3QN = web3QN
		self.web3BSC = web3BSC
		self.b_amnt = b_amnt
		self.s_addr = s_addr
		self.p_key = p_key
		self.token_deci, self.token_trigs, self.token_addrs, self.token_prices = get_token_addr_and_trig()
		self.ps_contract = self.web3BSC.eth.contract(address=ps_swap_addr,abi=ps_abi)

	def get_new_oracle(self):
		print('getting new oracle prices')
		self.token_deci, self.token_trigs, self.token_addrs, self.token_prices = get_token_addr_and_trig()


	def scan_all_txns(self, txns_arr):
		for i in txns_arr:
			try:
				self.review_txn(self.web3QN.eth.getTransaction(i['transactionHash']))
			except:
				continue


	def review_txn(self, txn_hex):
		try:
			if txn_hex['to'] == '0x10ED43C718714eb63d5aA57B78B54704E256024E':
				self.check_txn(self.ps_contract.decode_function_input(txn_hex['input'])[1], txn_hex['hash'])
		except:
			pass


	def check_txn(self, txn_json, txn_hash):
		try:
			idx = self.token_addrs.index(txn_json['path'][-1])
			if 'amountOut' in txn_json:
				outmin = txn_json['amountOut']
			elif 'amountOutMin' in txn_json:
				outmin = txn_json['amountOutMin']
			else:
				print('This transaction is not a buy/sell. txn hash: %s'%str(txn_hash.hex()))
			if float(outmin*(1/10**int(self.token_deci[idx]))) > float(self.token_trigs[idx]):
				_createBuyOrder(self.web3BSC,self.token_addrs[idx],int(self.token_deci[idx]),float(self.token_prices[idx]),self.b_amnt,self.s_addr,self.p_key)
				print('following is the txn hash of the trigger: %s'%str(txn_hash.hex()))
			else:
				print('A Transaction from the token list, however not enough for a frontrun. txn hash: %s'%str(txn_hash.hex()))
		except Exception as ex:
			pass
