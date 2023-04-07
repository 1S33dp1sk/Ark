import json
import requests

u_pancake_swap = 'https://api.pancakeswap.info/api/v2/tokens/' # concat token address 


# Returns price as a string
def get_token_price_usd(token_address):
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price']

# Returns price as a string
def get_token_price_bnb(token_address):
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price_BNB']



