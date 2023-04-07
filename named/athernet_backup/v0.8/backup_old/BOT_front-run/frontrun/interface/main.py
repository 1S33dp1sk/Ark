from selenium import webdriver
import time
from selenium.webdriver.common.action_chains import ActionChains



class INTERFACE:
	def __init__(self):
		self.TEST_RECOV_PHRASE = 'file beauty close fox million rent cube bicycle rain hill alley obvious'
		self.ACT_RECOV_PHRASE = 'boil double viable decade general language pipe prison laundry lazy search asset'
		self.TEST_PASS = 'ilovefrontrunbot123'
		self.EXT_PATH = "/home/kj/.mozilla/firefox/ddje4fvz.default/extensions/webextension@metamask.io.xpi"
		self.FROM_SEL_XPATH = "/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/button[2]"
		self.TO_SEL_XPATH = "/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[3]/div/div[2]/button"
		self.driver = webdriver.Firefox()
		self.driver.install_addon(self.EXT_PATH,temporary=True)
		self.cnt = 0

	def agnDecorator( func ):
		def trail( self,*args, **kwargs ):
			self.cnt += 1
			try:
				print(self.cnt)
				func( self, *args, **kwargs )
			except:
				time.sleep(0.5)
				trail( self,*args, **kwargs )
		return trail

	@agnDecorator
	def switchTabs(self,kw,pg_idx,length=0):
		if len(self.driver.window_handles) > length:
			self.driver.switch_to_window(self.driver.window_handles[pg_idx])
			self.cnt = 0
		elif (kw in self.driver.page_source):
			self.driver.switch_to_window(self.driver.window_handles[pg_idx])
			self.cnt = 0
		else:
			print('Error')
			pass

	@agnDecorator
	def clickBtn(self,x_path):
		ActionChains(self.driver).move_to_element(self.driver.find_element_by_xpath(x_path)).click().perform()
		self.cnt = 0

	@agnDecorator
	def enterField(self,x_path,entry):
		self.driver.find_element_by_xpath(x_path).send_keys(entry)
		self.cnt = 0

	def startMetaOnRecov(self):
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/div/button')
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/div[2]/div/div[2]/div[1]/button')
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/div/div[5]/div[1]/footer/button[2]')


	def addRecovAndFinish(self):
		self.enterField('/html/body/div[1]/div/div[3]/div/div/form/div[4]/div[1]/div/input', self.TEST_RECOV_PHRASE)
		self.enterField('//*[@id="password"]', self.TEST_PASS)
		self.enterField('//*[@id="confirm-password"]', self.TEST_PASS)
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/form/div[7]/div')
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/form/button')
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div/button')
		self.clickBtn('/html/body/div[2]/div/div/section/header/div/button')


	def switchTabsGoPancake(self):
		self.switchTabs('button',0)
		self.driver.get('https://www.pancakeswap.finance')
		self.clickBtn('/html/body/div[1]/div[1]/nav/div[2]/button')
		self.clickBtn('//*[@id="wallet-connect-metamask"]')


	def accessMetaMaskExt(self):
		self.switchTabs('',2,2)
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div[2]/div[4]/div[2]/button[2]')
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div[2]/div[2]/div[2]/footer/button[2]')
		self.switchTabs('',2,2)
		self.clickBtn('/html/body/div[1]/div/div[3]/div/div[2]/div/button[2]')
		if 'Switch network' in self.driver.page_source:
			self.clickBtn('/html/body/div[1]/div/div[3]/div/div[2]/div/button[2]')

	def openTradesTab(self):
		self.driver.switch_to_window(self.driver.window_handles[0])
		self.clickBtn('/html/body/div[1]/div[1]/div/div[1]/div[1]/div[2]/div[1]')
		self.clickBtn('/html/body/div[1]/div[1]/div/div[1]/div[1]/div[2]/div[2]/div[1]/a')

	def mainFlow(self):
		self.switchTabs('button',1)
		self.startMetaOnRecov()
		self.addRecovAndFinish()
		self.switchTabsGoPancake()
		self.accessMetaMaskExt()
		self.openTradesTab()		

		################
	# Pure Trading Functions #
		################

	def checkOutput(self):
		out_val = self.driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[3]/div/div[2]/input').get_attribute('value')
		if out_val != '' and out_val != '0.0':
			return True
		return False 

	def fillFrom(self,amnt,t_name,allin=False):
		if not allin:
			self.enterField('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/input',amnt)
			self.clickBtn(self.FROM_SEL_XPATH)
			self.selectCurrency(t_name)
		else:
			self.clickBtn('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/button')
			self.selectCurrency(t_name)
			self.clickBtn('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/button[1]')

	def chooseToToken(self, t_name):
		self.clickBtn(self.TO_SEL_XPATH)
		return self.selectCurrency(t_name)

	def trade(self):

		self.clickBtn('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[2]/button')

	def tradeBuy(self, amnt, t_name,skip=False):
		if not skip:
			self.fillFrom(amnt)
			self.selectCurrency("WBNB")
			self.chooseToToken(t_name)
		time.sleep(0.5)
		if not self.checkOutput():
			self.tradeBuy(amnt,t_name,True)
		return self.trade()

	def tradeSell(self, amnt, t_name, skip=False, allin=True):
		if not skip:
			self.chooseToToken("WBNB")
			if allin:
				self.fillFrom(amnt,t_name,True)
			else:
				self.fillFrom(amnt,t_name,False)
		time.sleep(0.5)
		if not self.checkOutput():
			self.tradeSell(amnt,t_name,True)
		return self.trade()

	def selectCurrency(self,t_name):
		self.enterField('//*[@id="token-search-input"]',t_name)
		self.clickBtn('/html/body/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div/div/div[1]')
		

	def addTokenAddresses(self, addrs):
		for i in addrs:
			self.clickBtn('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/button[2]')
			self.enterField('//*[@id="token-search-input"]',i)
			time.sleep(1)
			clickBtn('/html/body/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div/button')
			clickBtn('/html/body/div[1]/div[1]/div[2]/div[2]/div/div[3]/div/input')
			clickBtn('/html/body/div[1]/div[1]/div[2]/div[2]/div/div[3]/button')
			



if __name__ == '__main__':
	interface = INTERFACE()
	interface.mainFlow()


