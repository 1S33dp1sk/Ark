from tkinter import *
from tkinter import ttk
from PIL import ImageTk,Image
import threading
import sys
import os
from web3 import Web3
from pathlib import Path
sys.path.append('..')
from database import create_connection,add_new_token,update_general_info,get_general_info,get_all_transactions,get_all_tokens
from helpers import _connectToWeb3,_getDefaultProfileFF,_checkInternet
from core.oracle import Oracle
from core import Core
import err





class UIUX:
	def __init__(self):
		self.base = Tk()
		self.path = str(Path.home())+'/BOT_front-run/frontrun/'
		self.web3QN = _connectToWeb3('https://misty-spring-shape.bsc.quiknode.pro/1868e88bab3092e7a96927c293d9241dd8282628/')
		self.web3BSC = _connectToWeb3()
		self.conn = create_connection()
		self.general_info = get_general_info(self.conn)[0]
		self.tokens = get_all_tokens(self.conn)
		self.token_addrses = [i[4] for i in self.tokens]
		self.transactions = get_all_transactions(self.conn)
		self.frontrunner = Core(self.web3QN, self.web3BSC, float(self.general_info[3]), self.general_info[-2], self.general_info[-1]) 
		self.txns_thread_cnt = 0
		self.height = 650
		self.width = 1000
		self.bg_color = '#e7eff6'
		self.bg_text = '#adcbe3'
		self.bg_card = '#4b86b4'
		self.text_color = "#2a4d69"
		self.font_style = ("Nanum Pen Script", 16, "bold")
		self.save_img = PhotoImage(file=self.path+'gui/'+"save.png")
		self.img_on = PhotoImage(file=self.path+'gui/'+"t_on.png")
		self.img_off = PhotoImage(file=self.path+'gui/'+"t_off.png")
		self.add_token_img = PhotoImage(file=self.path+'gui/'+"button_add_new_token.png")
		self.connect_wallet_img = PhotoImage(file=self.path+'gui/'+"button_connect_wallet.png")
		self.power = False
		if not os.path.isdir('/usr/lib/firefox'):
			err.showError('Please Install FireFox')
		if not os.path.isfile(str(Path.home())+'/.mozilla/firefox/'+_getDefaultProfileFF()+'/extensions/webextension@metamask.io.xpi'):
			err.showError('Please Install MetaMask Extention For FireFox')
		if not _checkInternet():
			err.showError('Please Check The Internet Connection.')
		if not os.path.isfile(self.path+'database/main.db'):
			err.showError('No Database Found, Please Contact Developer.')
		self._startLoading()


	def _buildNotebook(self):
		self.tabs = ttk.Notebook(self.base)
		self.tabs.pack(expand=True)
		return self._buildFrames()

	def _buildFrames(self):
		self.info_frame = Frame(self.tabs,width=self.width,height=self.height,bg=self.bg_color)
		self.info_frame.pack(fill="both",expand=1)
		self._buildFInfo()

		self.transactions_frame = Frame(self.tabs,width=self.width,height=self.height, bg=self.bg_color)
		self.transactions_frame.pack(fill="both",expand=1)
		self._buildFTransactions()

		self.tokens_frame = Frame(self.tabs,width=self.width,height=self.height,bg=self.bg_color)
		self.tokens_frame.pack(fill="both",expand=1)
		self._buildFTokens()

		self.wallet_frame = Frame(self.tabs, width=self.width, height=self.height,bg=self.bg_color)
		self.wallet_frame.pack(fill="both",expand=1)
		self._buildFWallet()

		self.params_frame = Canvas(self.tabs,width=self.width,height=self.height,bg=self.bg_color)
		self.params_frame.pack(fill="both",expand=1)
		self._buildFParams()


		return self._buildTabs()

	def _buildTabs(self):
		self.tabs.add(self.info_frame, text="Info")
		self.tabs.add(self.transactions_frame, text="Transactions")
		self.tabs.add(self.tokens_frame, text="Tokens")
		self.tabs.add(self.wallet_frame, text="Connect Wallet")
		self.tabs.add(self.params_frame, text="Parameters")

	def _buildFInfo(self):
		Label(self.info_frame,text=self.general_info[1],fg=self.text_color,bg=self.bg_color,font=('Nanum Pen Script',32,'bold')).pack(pady=20)

		Label(self.info_frame,text="Profit Address:",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=15,y=100)
		Label(self.info_frame,text=self.general_info[4],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=30).place(x=15,y=150)


		Label(self.info_frame,text="Total Investment",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=15,y=250)
		Label(self.info_frame,text=self.general_info[2]+' BNB',fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=50).place(x=15,y=300)

		Label(self.info_frame,text="Amount To Trade",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=350,y=250)
		Label(self.info_frame,text=self.general_info[3]+' BNB',fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=50).place(x=350,y=300)

		Label(self.info_frame,text="Profitable Trades",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=700,y=250)
		Label(self.info_frame,text=self.general_info[5]+' Trades',fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=50).place(x=700,y=300)

		
		Label(self.info_frame,text="Total Profits",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=15,y=400)
		Label(self.info_frame,text=self.general_info[7]+' BNB',fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=50).place(x=15,y=450)

		Label(self.info_frame,text="Tokens Count",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=350,y=400)
		Label(self.info_frame,text=self.general_info[8]+' Tokens',fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=50).place(x=350,y=450)

		self.switch_btn = Button(
		self.info_frame,
		image=self.img_off,
		width=155,
		height=60,
		bd=0,
		bg=self.bg_color,
		activebackground=self.bg_color,
		cursor='hand2',
		command=self.powerSwitch)
		self.switch_btn.place(x=700,y=425)

		return None

	def _buildFTransactions(self):

		transactions_list_frame = Frame(self.transactions_frame,bg=self.bg_color)
		transactions_list_frame.pack(fill="both",expand=1)
		transactions_scroll = Scrollbar(transactions_list_frame)
		transactions_scroll.pack(side=RIGHT, fill=Y)
		self.tv_transactions = ttk.Treeview(transactions_list_frame,yscrollcommand = transactions_scroll.set)
		self.tv_transactions.pack(fill="both", expand=1)
		transactions_scroll.config(command = self.tv_transactions.yview)
		self.tv_transactions['columns'] = ("ID","token_name","txn_in","txn_in_price","txn_out", "txn_out_price","qty_native","qty_bnb","profit","status")

		#Format Transactions Columns
		self.tv_transactions.column("#0",width=0, stretch=NO)
		self.tv_transactions.column('ID',anchor=CENTER, width=30)
		self.tv_transactions.column('token_name',anchor=W, width=90)
		self.tv_transactions.column('txn_in',anchor=W, width=190)
		self.tv_transactions.column('txn_in_price',anchor=CENTER, width=60)
		self.tv_transactions.column('txn_out',anchor=W, width=190)
		self.tv_transactions.column('txn_out_price',anchor=CENTER, width=60)
		self.tv_transactions.column('qty_native',anchor=CENTER, width=75)
		self.tv_transactions.column('qty_bnb',anchor=CENTER, width=75)
		self.tv_transactions.column('profit',anchor=CENTER, width=90)
		self.tv_transactions.column('status',anchor=CENTER, width=60)

		# Create Transactions Headings
		self.tv_transactions.heading("#0",text="", anchor=W)
		self.tv_transactions.heading("ID",text="ID",anchor=CENTER)
		self.tv_transactions.heading("token_name",text="Token Name",anchor=W)
		self.tv_transactions.heading("txn_in",text="Buy Hash",anchor=W)
		self.tv_transactions.heading("txn_in_price",text="Buy ($)",anchor=CENTER)
		self.tv_transactions.heading("txn_out",text="Sell Hash",anchor=W)
		self.tv_transactions.heading("txn_out_price",text="Sell ($)",anchor=CENTER)
		self.tv_transactions.heading("qty_native",text="Qty Native",anchor=CENTER)
		self.tv_transactions.heading("qty_bnb",text="Qty BNB",anchor=CENTER)
		self.tv_transactions.heading("profit",text="Profit/Token",anchor=CENTER)
		self.tv_transactions.heading("status",text="Status",anchor=CENTER)

		for c,r in enumerate(self.transactions):
			if c % 2 == 0:
				self.tv_transactions.insert(parent="", index='end', iid=c,text="", values=(r[0], r[-5], r[1], r[2], r[-4], r[-3], r[3], r[4], r[-2], r[-1]),tags=("even"))
			else:
				self.tv_transactions.insert(parent="", index='end', iid=c,text="", values=(r[0], r[-5], r[1], r[2], r[-4], r[-3], r[3], r[4], r[-2], r[-1]),tags=("odd"))

		self.tv_transactions.tag_configure("even",background=self.bg_text)

		return None

	def _updateFTransactions(self):
		for i, txn in enumerate(self.self.tv_transactions.get_children()):
			r = self.transactions[i]
			self.tv_transactions.item(txn,  values=(r[0], r[-5], r[1], r[2], r[-4], r[-3], r[3], r[4], r[-2], r[-1]))

	def _buildFTokens(self):
		tokens_list_frame = Frame(self.tokens_frame,bg=self.bg_color)
		tokens_list_frame.pack(fill="both",expand=1)
			#Create Scrollbar
		tokens_scroll = Scrollbar(tokens_list_frame)
		tokens_scroll.pack(side=RIGHT, fill=Y)
			#Create Treeview
		self.tv_tokens = ttk.Treeview(tokens_list_frame, yscrollcommand = tokens_scroll.set, selectmode="browse")
			#pack to the screen
		self.tv_tokens.pack(fill="both", expand=1)
			# Configure the scrollbar
		tokens_scroll.config(command = self.tv_tokens.yview)
			# Define Our Columns
		self.tv_tokens['columns'] = ("ID","Name","Address","Triggered","Price/BNB","Trigger(Native)","Fees")


			#Format Tokens List Columns
		self.tv_tokens.column("#0",width=0, stretch=NO)
		self.tv_tokens.column('ID',anchor=CENTER, width=40)
		self.tv_tokens.column('Name',anchor=W, width=100)
		self.tv_tokens.column('Address',anchor=W, width=400)
		self.tv_tokens.column('Triggered',anchor=CENTER, width=80)
		self.tv_tokens.column('Price/BNB',anchor=CENTER, width=125)
		self.tv_tokens.column('Trigger(Native)',anchor=CENTER, width=100)
		self.tv_tokens.column('Fees',anchor=CENTER, width=125)

			# Create Tokens List Headings
		self.tv_tokens.heading("#0",text="")
		self.tv_tokens.heading("ID",text="ID",anchor=CENTER)
		self.tv_tokens.heading("Name",text="Name",anchor=W)
		self.tv_tokens.heading("Address",text="Address",anchor=W)
		self.tv_tokens.heading("Triggered",text="Triggered",anchor=CENTER)
		self.tv_tokens.heading("Price/BNB",text="Price/BNB",anchor=CENTER)
		self.tv_tokens.heading("Trigger(Native)",text="Trigger(Native)",anchor=CENTER)
		self.tv_tokens.heading("Fees",text="Fees",anchor=CENTER)

		# id , name, didadd, price, slip, contract

		for c,r in enumerate(self.tokens):
			if c % 2 == 0:
				self.tv_tokens.insert(parent="", index='end', iid=c,text="", values=(r[0], r[1], r[-3], r[2], r[3], r[-2], 'Instant(7GEWI)'),tags=("even"))
			else:
				self.tv_tokens.insert(parent="", index='end', iid=c,text="", values=(r[0], r[1], r[-3], r[2], r[3], r[-2], 'Instant(7GEWI)'),tags=("odd"))

		self.tv_tokens.tag_configure("even",background=self.bg_text)


		add_token = Button(self.tokens_frame,
			image = self.add_token_img,
			width=160,
			height=41,
			bg=self.bg_color,
			activebackground=self.bg_color,
			borderwidth=0,
			cursor="hand2",
			command=self.openNewWindow).pack(pady=10)

		return None

	def _updateFTokens(self):
		for i, tkn in enumerate(self.tv_tokens.get_children()):
			r = self.tokens[i]
			self.tv_tokens.item(tkn, values=(r[0], r[1], r[-3], r[2], r[3], r[-2], 'Instant(7GEWI)'))

	def _buildFWallet(self):

		connect_button = Button(self.wallet_frame,image=self.connect_wallet_img,bg=self.bg_color,activebackground=self.bg_color,bd=0,cursor="hand2",).place(x=400,y=275)

	def _buildFParams(self):
		
		self.round_rectangle(100,25,900,575,20, fill=self.bg_text)

		Label(self.params_frame, text="Edit Bot Parameters", bg=self.bg_text, fg=self.text_color, font=('',20,'bold')).pack(pady=50)

		Label(self.params_frame,text="Change Address", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=125)
		self.address_entry =  Entry(self.params_frame, width=45, background=self.bg_color, fg=self.text_color, font=self.font_style)
		self.address_entry.place(x=110,y=175)

		Label(self.params_frame,text="Max to trade", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=400, y=250)
		self.amt_entry = Entry(self.params_frame, width=15, background=self.bg_color, fg=self.text_color, font=self.font_style)
		self.amt_entry.place(x=400,y=300)

		Label(self.params_frame, text="Max Amount/Token", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=350)
		self.max_amt_per_tok = Scale(self.params_frame,
			from_=0, 
			to=100, 
			orient = HORIZONTAL,
			length = 225,
			width=25,
			tickinterval=100, 
			sliderrelief='flat', 
			highlightthickness=0, 
			background=self.bg_text,
			fg=self.text_color, 
			cursor="hand2", 
			troughcolor='#fff', 
			activebackground='#1065BF')
		self.max_amt_per_tok.place(x=110,y=400)

		Label(self.params_frame, text="Slippage", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=600,y=350)
		self.slip = Scale(self.params_frame,
			from_=0, 
			to=100,
			orient = 'horizontal',
			length=225,
			width=25,
			tickinterval=100, 
			sliderrelief='flat', 
			highlightthickness=0, 
			background=self.bg_text, 
			fg=self.text_color,
			cursor="hand2",
			troughcolor='#fff', 
			activebackground='#1065BF',
			)
		self.slip.place(x=600,y=400)

		save_edit = Button(
				self.params_frame,
				image=self.save_img, 
				bg=self.bg_text,
				activebackground=self.bg_card,
				bd=0,
				cursor="hand2",
				command=self.changeParams).place(x=450, y=500)
		return self.setParams()

	def _startUIUX(self):
		self.base.title(self.general_info[1])
		self.base.geometry(str(self.width)+'x'+str(self.height))
		self.base.config(bg=self.bg_color)
		self.style = ttk.Style()
		self.style.theme_use('clam')
		self.style.configure('.',relief='flat',borderwidth=10)
		self.style.configure("Treeview",background=self.bg_color,foreground=self.text_color,rowheight=30,borderwidth=0,fieldbackground=self.bg_color)
		self.style.map('Treeview',background=[('selected','green')])
	
	def buildBar(self):
		progress_bar = ttk.Progressbar(self.base, orient=HORIZONTAL, length=400, mode='determinate', style = 'primary.Striped.Horizontal.TProgressbar',maximum=100)
		progress_bar.place(x=300,y=300)

		bar_val = Label(self.base,text="", font=self.font_style,bg=self.bg_color, fg=self.text_color)
		bar_val.place(x=720, y=300)

		bar_st = Label(self.base, text="",font=self.font_style, bg=self.bg_color, fg=self.text_color)
		bar_st.place(x=300, y=350)

		def updateBar():
			bar_val.config(text=str(progress_bar['value'])+'%')
			progress_bar['value'] += 1
			if progress_bar['value'] <= 10 and progress_bar['value'] > 0:
				bar_st.config(text='Checking Internet Connection...')
			elif progress_bar['value'] <= 20 and progress_bar['value'] > 10:
				bar_st.config(text='Checking Mozilla Firefox...')
			elif progress_bar['value'] <= 30 and progress_bar['value'] > 20:
				bar_st.config(text='Checking Plugins...')
			elif progress_bar['value'] <= 40 and progress_bar['value'] > 30:
				bar_st.config(text='Checking MetaMask...')
			elif progress_bar['value'] <= 50 and progress_bar['value'] > 40:
				bar_st.config(text='Checking Database...')
			elif progress_bar['value'] <= 65 and progress_bar['value'] > 50:
				bar_st.config(text='Auditing Contract Addresses(Tokens)...')
			elif progress_bar['value'] <= 75 and progress_bar['value'] > 65:
				bar_st.config(text='Generating Current Price Oracle...')
			elif progress_bar['value'] <= 90 and progress_bar['value'] > 75:
				bar_st.config(text='Connecting To Fetching Mechanism...')	
			elif progress_bar['value'] < 100 and progress_bar['value'] > 90:
				bar_st.config(text='Setting Up FrontRun and Finalizing...')
			else:
				progress_bar['value'] += 1

			if progress_bar['value'] > 100:
				progress_bar.destroy()
				bar_val.destroy()
				bar_st.destroy()
				return self._runUIUX()
			else:
				self.base.after(100,updateBar)

		self.base.after(100,updateBar)

	def _startLoading(self):
		self._startUIUX()
		self.buildBar()
		self.base.mainloop()

	def _runUIUX(self):
		self._buildNotebook()
		self._startUIUX()
		self.base.mainloop()

	def updateUIUX(self,ginfo=False,txns=False,tkns=False):
		if ginfo:
			self.general_info = get_general_info(self.conn)[0]
			# self._updateFInfo()
		if txns:
			self.transactions = get_all_transactions(self.conn)
			self._updateFTransactions()
		if tkns:
			self.tokens = get_all_tokens(self.conn)
			self._updateFTokens()

	def addToken(self):
		token_name = self.new_name.get()
		token_addr = self.new_address.get()
		if str(token_name) and str(token_addr):
			conn = create_connection(self.path+'database/main.db')
			add_new_token(conn,(token_name,token_addr,"False","NaN"))

	def powerSwitch(self):
		self.power = not self.power
		self.switch_btn.config(image=self.img_off) if self.power else self.switch_btn.config(image=self.img_on)
		if not self.power:
			self.switch_btn.after(1000,self.realLoop)
		print('frontrunner is %s'%str('on' if not self.power else 'off'))

	def openNewWindow(self):
		newWindow = Toplevel(self.base)
		# sets the title of the
		# Toplevel widget
		newWindow.title("Create New Token")
		# sets the geometry of toplevel
		newWindow.geometry("400x400")
		newWindow.config(bg=self.bg_color)

		# A Label widget to show in toplevel
		Label(newWindow,text ="Token Name", bg=self.bg_color,fg=self.text_color, font=(self.font_style)).pack(pady=20)
		self.new_name = Entry(newWindow)
		self.new_name.pack(padx=10)
		
		Label(newWindow,text ="Contract Address", bg=self.bg_color, fg=self.text_color, font=(self.font_style)).pack(pady=20)
		self.new_address = Entry(newWindow,width=300)
		self.new_address.pack(padx=10)
		
		save_btn = Button(
			newWindow,
			image=self.save_img, 
			bg=self.bg_color,
			activebackground=self.bg_color,
			bd=0,
			cursor="hand2",
			command=lambda:[self.addToken(),newWindow.destroy()]).pack(pady=30)

	def round_rectangle(self,x1, y1, x2, y2, r=25, **kwargs):
		points = (x1+r, y1, x1+r, y1, x2-r, y1, x2-r, y1, x2, y1, x2, y1+r, x2, y1+r, x2, y2-r, x2, y2-r, x2, y2, x2-r, y2, x2-r, y2, x1+r, y2, x1+r, y2, x1, y2, x1, y2-r, x1, y2-r, x1, y1+r, x1, y1+r, x1, y1)
		return self.params_frame.create_polygon(points, **kwargs, smooth=True)

	def changeParams(self):
		max_amnt_tok = str(self.max_amt_per_tok.get())
		max_slip = str(self.slip.get())
		prft_addr = str(self.address_entry.get())
		max_total = str(self.amt_entry.get())
		conn = create_connection()
		update_general_info(conn, {'profit_address':prft_addr,'slippage':max_slip,'total_investment':max_total, 'amount_to_trade':max_amnt_tok})

	def setParams(self):
		self.max_amt_per_tok.set(self.general_info[3])
		self.slip.set(self.general_info[-3])
		self.address_entry.insert(0,self.general_info[4])
		self.amt_entry.insert(0,self.general_info[2])

	def databaseLoop(self):
		pass


	def _createNewFilter(self):
		self.n_txn_filter = self.web3QN.eth.filter({'fromBlock':'earliest','toBlock':'pending','address':self.token_addrses})
		return self._getTransactions()

	def _getTransactions(self):
		try:
			txns = self.n_txn_filter.get_new_entries()
			if len(txns) > 2:
				return txns
			else:
				return None
		except:
			self._createNewFilter()


	def transactionLoop(self):
		if (self.txns_thread_cnt%25) == 0:
			self.frontrunner.get_new_oracle()
		else:
			txns = self._getTransactions()
			if txns:
				print('Current Transactions Count From Node = %s'%str(len(txns)))
				self.frontrunner.scan_all_txns(txns)
		self.txns_thread_cnt += 1


	def oracleLoop(self):
		Oracle().updateTriggers()
		self.updateUIUX(tkns=True)
		# self.schedule.enter(15, 1, self.oracleLoop, ())

	def _thread_oracle(self):
		if not self.power:
			self.thread_oracle = threading.Thread(target=self.oracleLoop)
			self.thread_oracle.start()
			self.switch_btn.after(10000, self._thread_oracle)
		pass

	def _thread_transactions(self):
		if not self.power:
			self.thread_transactions = threading.Thread(target=self.transactionLoop)
			self.thread_transactions.start()
			self.switch_btn.after(3500, self._thread_transactions)

	def realLoop(self):
		if not self.power:
			self.switch_btn.after(10000, self._thread_oracle)
			self.switch_btn.after(3500, self._thread_transactions)
		else:
			self.switch_btn.after(1000, self.realLoop)
		# # we need a process to trade 
		# self.schedule.enter(4, 1, self.transactionLoop, ())
		# # we need a process (every 30 seconds) to check prices
		# self.schedule.enter(15, 1, self.oracleLoop, ())
		# # we need a process for UIUX && Database
		# self.schedule.enter(30, 1, self.databaseLoop, ())

if __name__ == '__main__':
	frontrun = UIUX()