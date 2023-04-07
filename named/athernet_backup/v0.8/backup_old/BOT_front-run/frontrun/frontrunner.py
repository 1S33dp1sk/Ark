#!/usr/bin/python3

import os
import err
from pathlib import Path
import re
import requests
import database
from gui import UIUX
from web3 import Web3
from helpers import _connectToWeb3,_getDefaultProfileFF,_checkInternet
import sched, time
from core.oracle import Oracle
from core import Core

class FrontRun:
	def __init__(self):
		self.schedule = sched.scheduler(time.time, time.sleep)
		self.MAIN_DIR = str(Path.home())+'/BOT_front-run/frontrun/'
		self.web3QN = _connectToWeb3('https://misty-spring-shape.bsc.quiknode.pro/1868e88bab3092e7a96927c293d9241dd8282628/')
		self.web3BSC = _connectToWeb3()
		self.conn = database.create_connection()
		self.general_info = database.get_general_info(self.conn)[0]
		self.tokens = database.get_all_tokens(self.conn)
		self.token_addrses = [i[4] for i in self.tokens]
		self.transactions = database.get_all_transactions(self.conn)
		self.frontrunner = Core(self.web3QN, self.web3BSC, self.general_info[3], self.general_info[-2], self.general_info[-1]) 
		if not os.path.isdir('/usr/lib/firefox'):
			err.showError('Please Install FireFox')
		if not os.path.isfile(str(Path.home())+'/.mozilla/firefox/'+_getDefaultProfileFF()+'/extensions/webextension@metamask.io.xpi'):
			err.showError('Please Install MetaMask Extention For FireFox')
		if not _checkInternet():
			err.showError('Please Check The Internet Connection.')
		if not os.path.isfile(self.MAIN_DIR+'database/main.db'):
			err.showError('No Database Found, Please Contact Developer.')
		# self.uiux._runUIUX()

	def uiUX(self):

		self.uiux = UIUX(self.MAIN_DIR,self.general_info, self.transactions, self.tokens)

	def _createNewFilter(self):
		self.n_txn_filter = self.web3QN.eth.filter({'fromBlock':'earliest','toBlock':'pending','address':self.token_addrses})
		return self._getTransactions()

	def _getTransactions(self):
		try:
			txns = self.n_txn_filter.get_new_entries()
			return txns
		except:
			self._createNewFilter()

	def databaseLoop(self):

		self.schedule.enter(30, 1, self.databaseLoop, ())

	def transactionLoop(self):
		self.frontrunner.scan_all_txns(self._getTransactions())
		self.schedule.enter(7, 1, self.transactionLoop, ())

	def oracleLoop(self):
		Oracle().updateTriggers()
		self.schedule.enter(15, 1, self.oracleLoop, ())


	def mainLoop(self):
		# we need a process to trade 
		self.schedule.enter(4, 1, self.transactionLoop, ())
		# we need a process (every 30 seconds) to check prices
		self.schedule.enter(15, 1, self.oracleLoop, ())
		# we need a process for UIUX && Database
		self.schedule.enter(30, 1, self.databaseLoop, ())




if __name__ == '__main__':
	fr = FrontRun()
	fr.uiUX()