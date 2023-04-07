Main task description: 

	Unmined/Unprocessed transcations scanning on pre-defined tokens addresses on a smart chain
	to detect large buy orders (Liqudity injection) with medium to low fees and execute a BUY transcation on said tokens with higher fees for instant processing, so that the bot buy orders gets executed before the large buy order. Then, execute a SELL transaction with a higher Ask/Bid price.

Specific task parameters:
	
	Exchanges: Pancakeswap and Uniswap
	Smart Chain: Binance Smart Chain (BEP20 tokens)

Standard bot parameters:

	Tab 1. Dashboard displaying currently ongoing transactions and tokens held.

	Tab 2. Historical transactions with dates and timestamp and their PNL(%)

	Tab 3. Parameters editing

Variable bot parameters:
	
	1. Tokens list
	*Tokens can be added and removed from a pre-defined list via contact address*

	2. Minimum/Maximum overall trading amount
	*Total trading amount in BNB*

	3. Slippage tolerance based on token
	*Every token can have its own slippage tolerance*

	4. Trading range based on token
	*Every token can have its own max/min trading amount pre-set*

	5. General fees (Gas price)

	6. Profit wallet address


Extra Notes:
	
	1. Connection to Metamask wallet

	2. After every 4 successful trades or a certain BNB amount. send profits to an external wallet address.

	3. Email notifications when a transcation executes and its PNL && when profits are sent to an external wallet address.