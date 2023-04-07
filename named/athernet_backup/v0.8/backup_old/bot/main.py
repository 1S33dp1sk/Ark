#!/usr/bin/python3
import os
import err
from pathlib import Path
import re
import requests
import database


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
		

		return



