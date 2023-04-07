import json
from slack_sdk import WebClient



# Get messages from SLACK API via a web hook directly from blockchain explorer
def get_slack_msgs():
	SLACK_TOKEN = "xoxp-2398929559395-2395707662501-2399612871779-2d9a27354717578eea751735d9d75102"
	channel_id = "C02BWJ4HBPV"
	client = WebClient(token=SLACK_TOKEN)
	conversation_history = []
	try:
		# Call the conversations.history method using the WebClient
		# conversations.history returns the first 100 messages by default
		# These results are paginated, see: https://api.slack.com/methods/conversations.history$pagination
		result = client.conversations_history(channel=channel_id)
		txns = [ json.loads(i['text']) for i in result["messages"] ]
		# return results of all transactions
		return txns
	except:
		print('Transactions Cannot Be Retireved')