from telethon import TelegramClient, events, sync
from binance.client import Client
import time
import re          
import threading



def process_event(event_text):
    event_pair = re.findall(r'(\w+)/(\w+)', event_text)
    _pair = event_pair[0]
    _entry_price = re.findall(r'ET[ \t]+(\d+\.\d+)[ \t]+-[ \t]+(\d+\.\d+)',event_text)[0]
    target_prices = re.findall(r'TP[ \t]+(\d+\.\d+)',event_text)
    _target_price = min([float(i) for i in target_prices])
    bt = BinanceTrader(_pair, _entry_price, _target_price)
    bt.mainStrategy()
    return None


def checkTrigger(new_message):
    if len(re.findall(r'(\w+)/(\w+)', new_message)) == 1:
        return True
    return False


class BinanceTrader:
    def __init__(self, pair, entry, outry):
        api_key="mLgY7AnDlwxkK1rmOJ03ua4c9lfWEs668A9LoIF8AzNFjamS8bYininoKktYI130"
        api_secret="1jC5Ci0mw8MMDRispxQSIXb9f9XfItB8OQaCDYyn6J7Wxx8NeGjNJp3fGhdloJXV"
        self.client = Client(api_key, api_secret)
        self.originalTrigger = {'pair':pair, 'entry':entry, 'TP-1':outry}
        self.pairName = ''.join(str(i).upper() for i in pair)
        self.pairEntry = self.getMinEntry(entry)
        self.pairOutry = self.getMinOutry(outry)
        self.tradeAmount = {'Spot':10, 'Futures':10} # prices are in USDT 
        self.startTime = time.time()
        self.orderIDs = []


    def formErrorTelegram(self, eType, error):
        print('\n')
        print('Error From %s:'%eType)
        print(str(error))

    def formTradeTelegram(self, eType, side, pair_name, qty, entry_price):
        print('\n')
        print('Trade From : %s'%eType)
        print('SIDE : %s'%side)
        print('PAIR NAME : %s'%pair_name)
        print('QUANTITY : %s'%qty)
        print('PRICE OF TXN : %s'%entry_price)

    def formGeneralTelegram(self, message):
        print('\n')
        print('---General Message---')
        print(str(message))

    def getMinOutry(self, outry):
        if type(outry) == tuple or type(outry) == list:
            return (float(outry[0]), float(outry[-1]))
        else:
            return (float(outry)*0.999, float(outry)*1.001) 

    def getMinEntry(self, entry):
        trade_entry = (0.0)
        if type(entry) == tuple or type(entry) == list:
            entry = [float(i) for i in entry]
            if len(entry) > 1:
                trade_entry = (min(entry)*0.995, max(entry)*1.005)
            else:
                trade_entry = (float(entry[0])*0.995, float(entry[0])*1.005)
        else:
            trade_entry = (float(entry)*0.995, float(entry)*1.005)
        return trade_entry

    def wait(self, time_to_wait):
        assert type(time_to_wait) == int
        time.sleep(time_to_wait)

    def getFutures(self):
        try:
            f_price = self.client.futures_symbol_ticker(symbol=self.pairName)['price']
            return float(f_price)
        except Exception as e:
            self.formErrorTelegram('Futures',e)

    def getSpot(self):
        try:
            s_price = self.client.get_symbol_ticker(symbol=self.pairName)['price']
            return float(s_price)
        except Exception as e:
            self.formErrorTelegram('Spot', e)

    def getBalanceSpot(self):
        try:
            myAcc = self.client.get_account()
            balances = myAcc['balances']
            for i in balances:
                if i['asset'] == self.originalTrigger['pair'][0].upper():
                    return i['free']
        except Exception as e:
            self.formErrorTelegram('Spot', e)

    def getTradingAmount(self, futures=False):
        if futures:
            current_price = self.getFutures()
            return self.formatFloat(float((self.tradeAmount['Futures']/current_price)* 0.99), current_price)
        else:
            current_price = self.getSpot()
            return self.formatFloat(float((self.tradeAmount['Spot']/current_price)* 0.98), current_price)

    def formatFloat(self, amount, price):
        main_precision = 5/price
        if 'e' in str(main_precision):
            precision = int(str(main_precision).split('e-')[-1])
            self.boughtAmount = float(str('%.'+str(precision)+'f')%amount)
            return float(str('%.'+str(precision)+'f')%amount)
        elif int(main_precision) == 0:
            precision = len(re.search('\d+\.(0*)', str(main_precision)).group(1))
            self.boughtAmount = float(str('%.'+str(precision)+'f')%amount)
            return float(str('%.'+str(precision)+'f')%amount)
        else:
            self.boughtAmount = int(amount)
            return int(amount)

    def tradeSpot(self, side_buy=False):
        if side_buy:
            # This is for buying spot
            qty = float('%.8f'%(float((self.tradeAmount['Spot']/self.getSpot()))* 0.98))
            try:
                res = self.client.order_market_buy(symbol=self.pairName, quantity=qty)

                return self.formTradeTelegram('Spot','BUY',self.pairName,qty, getSpot())
            except Exception as e:
                self.formErrorTelegram('Spot',e)
        else:
            # This is for selling spot
            qty = self.getBalanceSpot()
            try:
                res = self.client.order_market_sell(symbol=self.pairName, quantity=qty)
                return self.formTradeTelegram('Spot','SELL/Close Position', self.pairName, qty, getSpot())
            except Exception as e:
                self.formErrorTelegram('Spot', e)

    def tradeFutures(self, side_buy=False):
        if side_buy:
            # This is for buying futures
            self.client.futures_create_order(symbol=self.pairName, side=self.client.SIDE_BUY, type=self.client.FUTURE_ORDER_TYPE_MARKET, quantity=self.getTradingAmount(True))
            self.formTradeTelegram('Futures','BUY', self.pairName, self.getTradingAmount(True), getFutures())

        else:
            # This is for selling futures
            if self.boughtAmount:
                self.client.futures_create_order(symbol=self.pairName, side=self.client.SIDE_SELL, type=self.client.FUTURE_ORDER_TYPE_MARKET, quantity=self.boughtAmount)
                self.formTradeTelegram('Futures','SELL/Close Position', self.pairName, self.boughtAmount, getFutures())

    def checkPair(self, futures=False):
        if futures:
            try:
                self.client.futures_symbol_ticker(symbol=self.pairName)
                return True
            except:
                self.formGeneralTelegram('For pair: %s'%str(self.pairName)+' There is no Futures pair,\n reverting back to Spot trade.')
                return False
        else:
            try:
                self.client.get_symbol_ticker(symbol=self.pairName)
                return True
            except:
                self.formErrorTelegram('Spot','Cannot trade pair: %s'%str(self.pairName)+' as it does not exist on binance.\n You should imporve me for other trading platforms (:')
                return False

    def checkPrice(self, enter=False, futures=False):
        self.wait(1)
        if futures:
            current_price = self.getFutures()
        else:
            current_price = self.getSpot()
        if enter:
            if current_price < self.pairEntry[0] or current_price > self.pairEntry[1]:
                return True
            return False
        else:
            if current_price < self.pairOutry[0] or current_price < self.pairOutry[1]:
                return True
            return False

    def adjustLeverage(self, leverage):
        try:
            self.client.futures_change_leverage(symbol=self.pairName, leverage=leverage)
        except:
            pass
    def adjustMarginType(self):
        try:
            self.client.futures_change_margin_type(symbol=self.pairName, marginType='ISOLATED')
        except:
            pass
    def futuresAddMargin(self, amount):
        try:
            self.client.futures_change_position_margin(symbol=self.pairName, amount=amount, type=1)
        except:
            self.formErrorTelegram('Futures', 'Cannot add margin to futures position, please check it immediately.')

    def mainStrategy(self):
        #check if position is already open
        if self.checkPair(True):
            self.adjustMarginType()
            self.adjustLeverage(30)
            #CheckPair For Futures
            while self.checkPrice(enter=True, futures=True):
                pass
            self.tradeFutures(True)
            while self.checkPrice(enter=False, futures=True):
                pass
            self.tradeFutures(False)

        elif self.checkPair(False):
            #CheckPair For Spot
            while self.checkPrice(enter=True, futures=False):
                pass
            self.tradeSpot(True)
            while self.checkPrice(enter=False, futures=False):
                pass
            self.tradeSpot(False)
        else:
            return



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




api_id = '7516911'
api_hash = '39629a4c2ed17b6766c4831dfb423b48'
client = TelegramClient('anon',api_id,api_hash)


@client.on(events.NewMessage(chats='me'))
async def event_handler(event):
    if (checkTrigger(event.raw_text)):
        mythread = threading.Thread(target=process_event, args=(event.raw_text,))
        mythread.start()



client.start()
client.run_until_disconnected()