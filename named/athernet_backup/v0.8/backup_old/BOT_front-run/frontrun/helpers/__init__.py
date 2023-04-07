import time
from web3 import Web3
import requests
import os
from pathlib import Path


def _getDefaultProfileFF():
    '''
        Check for firefox profile
    '''
    dirs_firefox = [i for i in os.listdir(str(Path.home())+'/.mozilla/firefox/')]
    for i in dirs_firefox:
        if '.default' in i:
            return i
    err.showError('No Default FireFox Profile Found.')

def _checkInternet():
    '''
        Check internet connection
    '''
    try:
        r = requests.get('https://www.google.com')
        if r.status_code == 200:
            return True
        else:
            return False
    except:
        return False

def _connectToWeb3(http_prov="https://bsc-dataseed.binance.org/"):
    '''
        Connect to any web3 provide *Binance *QuickNode *Localhost (FOR LOCALNODE) *ETC..
    '''
    return Web3(Web3.HTTPProvider(http_prov))

def _divideBasedOnDecimals(amount, decimals):
    ''' 
        Get the token value in token native amount
    '''
    return float(amount)*(1/10**decimals)

def _multiplyBasedOnDecimals(amount, decimals):
    ''' 
        Get the token value in smart contract native amount
    '''
    return float(amount)*(10**decimals)

def _deadline():
    '''
        Get a predefined deadline. 10min by default (same as the Uniswap SDK)
    '''
    return int(time.time()) + 30 * 60

def _getContractDecimals(web3,chksum_contract_address):
    '''
        This function will call a simple smart contract generic ABI to get the decimals count.
    '''
    generic_abi = """[{"constant": true,"inputs": [],"name": "name","outputs": [ {"name": "", "type": "string"}],"payable": false,"type": "function"},{"constant": true,"inputs": [],"name": "decimals","outputs": [{"name": "","type": "uint8"}],"payable": false,"type": "function"},{"constant": true,"inputs": [{"name": "_owner","type": "address"}],"name": "balanceOf","outputs": [{"name": "balance","type": "uint256"}],"payable": false,"type": "function" },{"constant": true, "inputs": [],"name": "symbol","outputs": [{"name": "","type": "string"}],"payable": false,"type": "function"}]"""
    side_contract = web3.eth.contract(address=web3.toChecksumAddress(chksum_contract_address), abi=generic_abi)
    token_decimals = side_contract.caller().decimals()
    return token_decimals