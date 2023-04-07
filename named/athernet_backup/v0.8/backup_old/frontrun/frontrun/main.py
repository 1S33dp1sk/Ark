#!/usr/bin/python3
import os
import err
from pathlib import Path
import re
import requests
import database
from gui import main

def getDefaultProfileFF():
	dirs_firefox = [i for i in os.listdir(str(Path.home())+'/.mozilla/firefox/')]
	for i in dirs_firefox:
		if '.default' in i:
			return i
	err.showError('No Default FireFox Profile Found.')

def checkInternet():
	try:
		requests.get('https://www.google.com')
		return True
	except:
		return False



class FrontRun:
	def __init__(self):
		self.MAIN_DIR = str(Path.home())+'/BOT_front-run/'
		main.main()
		if not os.path.isdir('/usr/lib/firefox'):
			err.showError('Please Install FireFox')
		if not os.path.isfile(str(Path.home())+'/.mozilla/firefox/'+getDefaultProfileFF()+'/extensions/webextension@metamask.io.xpi'):
			err.showError('Please Install MetaMask Extention For FireFox')
		if not checkInternet():
			err.showError('Please Check The Internet Connection.')
		if not os.path.isfile(self.MAIN_DIR+'database/main.db'):
			err.showError('No Database Found, Please Contact Developer.')
		else:
			self.conn = database.create_connection(self.MAIN_DIR+'database/main.db')

	def mainInit(self):
		self.general_info = database.get_general_info(self.conn)[0]
		self.tokens = database.get_all_tokens(self.conn)
		self.transactions = database.get_all_transactions(self.conn)
		self.uiux = UIUX('/home/kj/BOT_front-run/frontrun/',self.general_info, self.transactions, self.tokens)
		tokens_trig = []
		tokens_addresses = []
		for i in tokens:
			# check idx
			tokens_trig.append(tokens[-1])
			tokens_addresses.append(tokens[-2])


		return



if __name__ == '__main__':
	fr = FrontRun()
	fr.mainInit()