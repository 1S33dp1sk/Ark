from database import get_all_tokens, update_token, create_connection
from web3 import Web3
from helpers.constants import ps_factory_addr, ps_factory_abi, ps_pair_abi
from helpers import _connectToWeb3,_getContractDecimals
import time



# this class is an updatter class for all the token prices and triggers
class Oracle:
	def __init__(self):
		self.web3 = _connectToWeb3()
		self.psFactory = self.web3.eth.contract(address=ps_factory_addr,abi=ps_factory_abi)

	def _getPSpair(self,addr):
		addr = self.web3.toChecksumAddress(addr)
		pair = self.psFactory.caller().getPair('0xbb4CdB9CBd36B01bD1cBaEBF2De08d9173bc095c',addr)
		pair_contract = self.web3.eth.contract(address=pair,abi=ps_pair_abi)
		if pair_contract.caller().token0() == addr:
			bnb,token,ts = pair_contract.caller().getReserves()
		else:
			token,bnb,ts = pair_contract.caller().getReserves()
		bnb_liq = bnb*(1/10**18)
		decimals = _getContractDecimals(self.web3,addr)
		token_liq = token*(1/10**decimals)
		return (token_liq, token_liq/bnb_liq, decimals)

	def _calcTrigger(self,liq):
		return str('%.3f'%(0.0135*liq))

	def updateTriggers(self):
		conn = create_connection()
		tokens = get_all_tokens(conn)
		for i in tokens:
			t_l,t_p,t_d = self._getPSpair(i[-3])
			update_token(conn, i[0], {'price': str('%.7f'%t_p), 'trigger':str(self._calcTrigger(t_l)), 'decimals':str(t_d)})



