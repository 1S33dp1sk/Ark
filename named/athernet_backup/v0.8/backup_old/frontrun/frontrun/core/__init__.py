import json
import requests
import os
from slack_sdk import WebClient



u_pancake_swap = 'https://api.pancakeswap.info/api/v2/tokens/' # concat token address 

# ID of the channel you want to send the message to

#client.chat_postMessage(channel=channel_id, text="New Message To Front Run")



def getSlackMsgs():
	SLACK_TOKEN = "xoxp-2398929559395-2395707662501-2399612871779-2d9a27354717578eea751735d9d75102"
	channel_id = "C02BWJ4HBPV"
	client = WebClient(token=SLACK_TOKEN)
	conversation_history = []
	try:
		# Call the conversations.history method using the WebClient
		# conversations.history returns the first 100 messages by default
		# These results are paginated, see: https://api.slack.com/methods/conversations.history$pagination
		result = client.conversations_history(channel=channel_id)

		conversation_history = result["messages"][0]
		# conversation_history = [ i['text'] for i in conversation_history ]
		# Print results
		print(conversation_history['text'])
	except:
		print('Your messages wouldnt be retrive')





# Returns price as a string
def get_token_price_usd(token_address):
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price']

# Returns price as a string
def get_token_price_bnb(token_address):
	return json.loads(requests.get(u_pancake_swap+token_address).text)['data']['price_BNB']



