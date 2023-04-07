from selenium import webdriver
import time
from selenium.webdriver.common.action_chains import ActionChains


firefox_profile = '/home/kj/.mozilla/firefox/ddje4fvz.default'

ac.move_to_element(elem).move_by_offset(x_offset, y_offset).click().perform()



def _initFF(firefox_profile):
	# ff_profile = webdriver.FirefoxProfile(firefox_profile)
	firefox = webdriver.Firefox()
	return firefox


def gotoMOBOX(ff):
	return ff.get('https://www.mobox.io')

def gotoTokenMasters(ff):
	return ff.find_element_by_xpath('/html/body/div[1]/header/ul[1]/li[2]').click()


def addLoginInfo(ff,un,pw):
	ff.find_element_by_xpath("/html/body/div[1]/header/div[8]/div[2]/div/div/div[2]/div[2]/input").send_keys(un)
	ff.find_element_by_xpath("/html/body/div[1]/header/div[8]/div[2]/div/div/div[3]/div[2]/input").send_keys(pw)


def detectLogin(ff):
	time.sleep(15) # wait for loading...
	ff.find_element_by_xpath("/html/body/div[1]/header/div[8]/div[2]/div/div")
	mobox_user = input("Please input your MOBOX e-mail or mobile\n")
	mobox_pass = input("Please input your MOBOX password *Carefull this input is not hidden\n")
	addLoginInfo(ff,mobox_user,mobox_pass)
	time.sleep(2)
	ff.find_element_by_xpath("/html/body/div[1]/header/div[8]/div[2]/div/div/div[4]/button").click()

def flow():
	ff = _initFF(firefox_profile)
	gotoMOBOX(ff)
	gotoTokenMasters(ff)
	detectLogin(ff)
	return ff



def findIFrame(ff, ac):
	iframe = ff.find_element_by_xpath("/html/body/div[1]/div[2]/div[4]/iframe")
	return iframe


frame_width = iframe.size['width']
frame_height = iframe.size['height']


ac_real.move_to_element_with_offset(iframe,iframe.size['width']/2,iframe.size['height']/2).click().perform()


width = 322
height = 596


def clickByCor(ac_real,iframe,x,y):
	factor_x = iframe.size['width']/x
	factor_y = iframe.size['height']/y
	ac_real.move_to_element_with_offset(iframe,factor_x,factor_y).click().perform()
	time.sleep(10)




160
488





# plunder_search, plunder_popup_confirm, plunder_battle_confirm, plunder_finish, plunder_finish_confirm

gameplay_constants = {

	'address':[2,2], 'ui_momo':[10.73,1.04] , 'ui_momopoly':[2.93,1.05], 'ui_plunder':[1.88,1.05],

	'ui_arena':[1.4,1.05],'ui_board':[1.1,1.05], 'plunder_search':[2,1.39], 'plunder_popup_confirm': [1.61,1.49],

	 'plunder_battle_confirm':[2,1.05], 'plunder_finish':[1.09,1.33], 'plunder_finish_confirm':[2,1.39], 

	 'plunder_popup_cancel':[2,1.23],'plunder_task':[2.27,1.32], 'plunder_claim':[1.27,3.39],'plunder_exit':[2,1.02] 

	 'momo_claim_coin':[1.15,1.19], 'momo_one':[7.16,3.85], 'momo_two':[2.68,3.85],

	 'momo_three':[1.65,3.85], 'momo_skill_refine':[2.48,1.4],'momo_skill_upgrade':[3.93,1.4],

	 'momo_skill_unlock':[3.01,1.4], 'momo_skill_x_off':,'momo_skill_y_off':,'momo_skill_cancel':[2,1.05],

	 'momopoly_x1':[5.37,1.59],'momopoly_x2':[2.01,1.59],'momopoly_2rolls':[1.24,1.59],'momopoly_x5':[5.37,1.37],

	 'momopoly_x10':[2.01,1.37], 'momopoly_4rolls':[1.25,1.37], 'momopoly_spin':[2,1.2],
 }


