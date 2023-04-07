from telethon import TelegramClient, events, sync
from bs4 import BeautifulSoup
import pandas as pd
from binance.client import Client
from binance import BinanceSocketManager

import time


# def process_event(event_text,bt):
# 	event_pair = re.findall(r'(\w+)/(\w+)', event_text)
# 	if len(event_pair) < 1:
# 		pass
#     _pair = event_pair[0]
#     _entry_price = re.findall(r'ET[ \t]+(\d+\.\d+)[ \t]+-[ \t]+(\d+\.\d+)',event_text)[0]
#     target_prices = re.findall(r'TP[ \t]+(\d+\.\d+)',event_text)
#     _target_price = min([float(i) for i in target_prices])
#     return bt.tradeProcess(_pair, _entry_price, _target_price)


class BinanceTrader:
    def __init__(self, pair, entry, outry):
        api_key="BCcozJpcdjIECzMQpoVRhomnXcmBBOxWZQFswTnd3Fuw2R7AJHpvOjkUGyyb80wH"
        api_secret="ukStl0nULjUIQ6Ibg4uiv3Pv3xGpRyew8JPWujvs1PXvY3YMX4tABrRoaxwZYUTb"
        self.client = Client(api_key, api_secret)
        self.bsm = BinanceSocketManager(client)

        self.pair_name = pair
        self.pair_entry = self.getMinEntry(entry)
        self.pair_outry = self.getMinOutry(outry)

        self.pair_price = {'error':False}        
        self.socket = bsm.trade_socket(pair_name)
    





    def getMinOutry(self, outry):
        if type(outry) == tuple or type(outry) == list:
            return (float(outry[0]), float(outry[-1]))
        else:
            return (float(outry)*0.99, float(outry)*1.01) 

    def getMinEntry(self, entry):
        trade_entry = (0.0)
        if type(entry) == tuple or type(entry) == list:
            if len(entry) > 1:
                trade_entry = (min(entry)*0,96, max(entry)*1.04)
            else:
                entry = entry[0]
        if trade_entry == (0,0):
            trade_entry = (entry*0.96, entry*1.04)
        return trade_entry


    # ??
    while True:
        await socket.__aenter__()
        msg = await socket.recv()
        frame = create_frame(msg)
        ## trying to save this data in database
        print(msg)

    def create_frame(msg):
        df = pd.DataFrame([msg])
        df = df.loc[:,['s','E','p']]
        df.columns = ['symbol','Time','Price']
        df.Price = df.Price.astype(float)
        df.Time = pd.to_datetime(df,Time, unit='ms')
        return df



    def strategy(pair_name,curr_price,entry_price, loocback, amount, open_position=False):
        while True:
            # Requesting live data
            
            if not open_position:
                if curr_price > entry_price:
                    order = buy_spot(pair_name,amount)
                    print(order)
                    open_position = True
                    break

        if open_position:
            while True:
                 # Requesting live data
                 # condition = current Time > order Time
                 sincebuy = df.loc[df.Time > pd.to_datetime(order['transactTime'],unit='ms')]

                 if len(sincebuy) > 1:
                    if last_entry > 0.0015 or last_entry < -0.0015:
                        order = sell_spot(pair_name,amount)
                        print(order)
                        break
 


    def chooseSpotPair(self,pair_name=''):
        f_pair_name = '/'.join(i for i in pair_name)
        try:
            client.get_symbol_info(f_pair_name)
            # we can get all pairs in array then check desiered pair
            # client.get_all_tickers()
        except:
            pass


    def buy_spot(self, pair_name ,amount):
        self.client.order_market_buy(symbol=pair_name,quantity=amount)

    def sell_spot(self, pair_name ,amount):
        self.client.order_market_sell(symbol=pair_name,quantity=amount)
    

    def trade_price(msg):
        if msg['e'] != 'error':
        return msg['c']
        self.pair_price['last'] = msg['c']
        self.pair_price['bid'] = msg['b']
        self.pair_price['last'] = msg['a']
        self.pair_price['error'] = False
        else:
            self.pair_price['error'] = True

    def get_available_values(self,pair_name):
        self.bsm.start_symbol_ticker_socket(callback=trade_price, symbol=pair_name)



    def check_future(self, pair_name):
        try:
            self.client.futures_symbol_ticker(symbol=pair_name)
        except:
            pass


    # Create Isolated Order 
    

    def buy_future(self, pair_name, amount):
        self.client.futures_create_order(symbol=pair_name, side='BUY', type='MARKET', quantity=amount)

    def sell_future(self, pair_name, amount):
        self.client.futures_create_order(symbol=pair_name, side='SELL', type='MARKET', quantity=amount)

    def getMarkVal(self):

        return 

    def getSpotPrice(self):
        return 

    def tradeProcess(self,pair_name, trade_entry, trade_outry, amount):
                spot_price = float(self.getSpotPrice())
                while (spot_price >= trade_in):
                self.buy_spot(pair_name, amount)
                while (spot_price < trade_outry):
                   
                self.sell_spot(pair_name,amount)


            else:
                self.switchToIsolated()
                current_price = float(self.getMarkVal())
                trade_entry
                if type(trade_entry) == tuple:
                    trade_in = trade_entry[1]
                else:
                    trade_in = trade_entry
                while (current_price >= trade_in):
                    time.sleep(1)
                self.buyFuture(25)
                while (current_price < trade_outry):
                    time.sleep(1)
                self.sellFuture()




   



                   



# api_id = ''
# api_hash = ''
# client = TelegramClient('anon',api_id,api_hash)
# bt = BinanceTrader()

# @client.on(events.NewMessage(chats='channel_name'))
# async def event_handler(event):
# 	process_event(event.raw_text,bt)




# if __name__ == "__main__":
    
#     client.start()
#     client.run_untill_disconnected()




# template_trigger = '''
# HOT/USDT
# ET 0.0098 - 0.01
# TP 0.0107
# TP 0.0112
# TP 0.0116
# TP 0.013
# #SHORT-MID
# #DYOR         
# '''





