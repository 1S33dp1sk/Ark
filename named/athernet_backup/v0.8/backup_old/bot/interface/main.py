from selenium import webdriver
import time
from selenium.webdriver.common.action_chains import ActionChains

test_recovery_phase = 'file beauty close fox million rent cube bicycle rain hill alley obvious'

test_password = 'ilovefrontrunbot123'

extension_path = "/home/kj/.mozilla/firefox/ddje4fvz.default/extensions/webextension@metamask.io.xpi"


def initDriver():
	driver = webdriver.Firefox()
	driver.install_addon(extension_path, temporary=True)
	return driver

def checkTabs(driver):
	if ('button' not in driver.page_source):
		driver.switch_to_window(driver.window_handles[1])
	time.sleep(2)

def startMetaOnRecov(driver):
	get_started_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/div/button')
	get_started_btn.click()
	import_wallet_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/div[2]/div/div[2]/div[1]/button')
	import_wallet_btn.click()
	import_wallet_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/div/div[5]/div[1]/footer/button[2]')
	import_wallet_btn.click()
	time.sleep(1)

def addRecovAndFinish(driver):
	secret_recovery_phrase = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/form/div[4]/div[1]/div/input')
	secret_recovery_phrase.send_keys(test_recovery_phase)
	new_password = driver.find_element_by_xpath('//*[@id="password"]')
	new_password.send_keys(test_password)
	confirm_password = driver.find_element_by_xpath('//*[@id="confirm-password"]')
	confirm_password.send_keys(test_password)
	terms_of_use = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/form/div[7]/div')
	terms_of_use.click()
	accept_continue = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/form/button')
	accept_continue.click()
	time.sleep(2)
	all_done = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div/button')
	all_done.click()
	time.sleep(1)
	cancel_secret = driver.find_element_by_xpath('/html/body/div[2]/div/div/section/header/div/button')
	cancel_secret.click()

def switchTabsGoPancake(driver):
	if ('button' in driver.page_source):
		driver.switch_to_window(driver.window_handles[0])
	driver.get('https://www.pancakeswap.finance')
	connect_wallet = driver.find_element_by_xpath('/html/body/div[1]/div[1]/nav/div[2]/button')
	connect_wallet.click()
	metamask_btn = driver.find_element_by_xpath('//*[@id="wallet-connect-metamask"]')
	metamask_btn.click()
	time.sleep(2)

def accessMetaMaskExt(driver):
	tabs = driver.window_handles
	if len(tabs) > 1:
		driver.switch_to_window(tabs[2])
	time.sleep(1)
	nxt_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div[2]/div[4]/div[2]/button[2]')
	nxt_btn.click()
	connect_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div[2]/div[2]/div[2]/footer/button[2]')
	connect_btn.click()
	time.sleep(2)
	driver.switch_to_window(driver.window_handles[2])
	time.sleep(2)
	approve_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div[2]/div/button[2]')
	approve_btn.click()
	if 'Switch network' in driver.page_source:
		approve_btn = driver.find_element_by_xpath('/html/body/div[1]/div/div[3]/div/div[2]/div/button[2]')
		approve_btn.click()

def openTradesTab(driver):
	driver.switch_to_window(driver.window_handles[0])
	driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div[1]/div[2]/div[1]').click()
	driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[1]/div[1]/div[2]/div[2]/div[1]/a').click()

def AddFromAmount(driver,amnt):
	from_input = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/input')
	from_input.send_keys(amnt)
	time.sleep(2)

def selectFromCurrency(driver, address, aganist_address):
	selector_btn = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/button[2]')
	selector_btn.click()
	time.sleep(2)
	search_address = driver.find_element_by_xpath('//*[@id="token-search-input"]')
	search_address.send_keys(address)
	ActionChains(driver).move_to_element(driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div/div/div[1]')).click().perform()
	driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[1]/div/div[2]/input').send_keys('3')
	selector_against_btn = driver.find_element_by_xpath('/html/body/div[1]/div[1]/div/div[2]/div/div[1]/div/div[2]/div[1]/div[3]/div/div[2]/button')
	selector_against_btn.click()
	driver.find_element_by_xpath('//*[@id="token-search-input"]').send_keys(aganist_address)
	time.sleep(1)
	ActionChains(driver).move_to_element(driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[2]/div[2]/div[1]/div[2]/div/button')).click().perform()
	driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[2]/div[2]/div/div[3]/div/input').click()
	driver.find_element_by_xpath('/html/body/div[1]/div[1]/div[2]/div[2]/div/div[3]/button').click()


if __name__ == '__main__':
	driver = initDriver()
	checkTabs(driver)
	startMetaOnRecov(driver)
	addRecovAndFinish(driver)
	switchTabsGoPancake(driver)
	accessMetaMaskExt(driver)
	openTradesTab(driver)
	AddFromAmount(driver, '2')
	selectFromCurrency(driver, 'WBNB', '0x4c97c901b5147f8c1c7ce3c5cf3eb83b44f244fe')



