from tkinter import *
from tkinter import ttk
from PIL import ImageTk,Image
sys.path.append('..')
from database import create_connection,add_new_token,update_general_info,get_general_info




class UIUX:
	def __init__(self,path,general_info,txns,tkns):
		self.base = Tk()
		self.path = path
		self.general_info = general_info
		self.txns = txns
		self.tkns = tkns
		self.height = 650
		self.width = 1000
		self.bg_color = '#e7eff6'
		self.bg_text = '#adcbe3'
		self.bg_card = '#4b86b4'
		self.text_color = "#2a4d69"
		self.font_style = ("Nanum Pen Script", 14, "bold")
		self.save_img = PhotoImage(file=self.path+'gui/'+"save.png")
		self.img_on = PhotoImage(file=self.path+'gui/'+"t_on.png")
		self.img_off = PhotoImage(file=self.path+'gui/'+"t_off.png")
		self.add_token_img = PhotoImage(file=self.path+'gui/'+"button_add_new_token.png")
		self.connect_wallet_img = PhotoImage(file=self.path+'gui/'+"button_connect_wallet.png")
		self.power = False

	def addToken(self):
		token_name = self.new_name.get()
		token_addr = self.new_address.get()
		if str(token_name) and str(token_addr):
			conn = create_connection(self.path+'database/main.db')
			add_new_token(conn,(token_name,token_addr,"False","NaN"))

	def powerSwitch(self):
		self.power = not self.power
		self.switch_btn.config(image=self.img_off) if self.power else self.switch_btn.config(image=self.img_on)

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
		conn = create_connection(self.path+'database/main.db')
		update_general_info(conn, {'profit_address':prft_addr,'slippage':max_slip,'total_investment':max_total, 'amount_to_trade':max_amnt_tok})

	def setParams(self):
		self.max_amt_per_tok.set(self.general_info[3])
		self.slip.set(self.general_info[-1])
		self.address_entry.insert(0,self.general_info[4])
		self.amt_entry.insert(0,self.general_info[2])


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
		Label(self.info_frame,text=self.general_info[1],fg=self.text_color,bg=self.bg_color,font=('Nanum Pen Script',20,'bold')).pack(pady=10)

		Label(self.info_frame,text="Total Investment",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=10,y=70)
		Label(self.info_frame,text=self.general_info[2],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=20).place(x=15,y=110)

		Label(self.info_frame,text="Amount To Trade",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=10,y=160)
		Label(self.info_frame,text=self.general_info[3],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=20).place(x=15,y=200)

		Label(self.info_frame,text="Profitable Trades",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=10,y=340)
		Label(self.info_frame,text=self.general_info[5],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=20).place(x=15,y=380)

		Label(self.info_frame,text="Profit Address:",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=250,y=70)
		Label(self.info_frame,text=self.general_info[4],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=10).place(x=250,y=110)

		Label(self.info_frame,text="Total Profits",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=250,y=250)
		Label(self.info_frame,text=self.general_info[7],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=20).place(x=15,y=290)

		Label(self.info_frame,text="Tokens Count",fg=self.text_color,bg=self.bg_color,font=self.font_style).place(x=250,y=250)
		Label(self.info_frame,text=self.general_info[8],fg=self.text_color,bg=self.bg_text,font=self.font_style, padx=20).place(x=250,y=290)

		self.switch_btn = Button(
		self.info_frame,
		image=self.img_on,
		width=155,
		height=60,
		bd=0,
		bg=self.bg_color,
		activebackground=self.bg_color,
		cursor='hand2',
		command=self.powerSwitch)
		self.switch_btn.place(x=600,y=350)

		return None

	def _buildFTransactions(self):

		transactions_list_frame = Frame(self.transactions_frame,bg=self.bg_color)
		transactions_list_frame.pack(fill="both",expand=1)
		transactions_scroll = Scrollbar(transactions_list_frame)
		transactions_scroll.pack(side=RIGHT, fill=Y)
		transactions = ttk.Treeview(transactions_list_frame,yscrollcommand = transactions_scroll.set, selectmode="none")
		transactions.pack(fill="both", expand=1)
		transactions_scroll.config(command = transactions.yview)
		transactions['columns'] = ("ID","token_name","txn_in","txn_in_price","txn_out", "txn_out_price","qty_native","qty_bnb","profit","status")

		#Format Transactions Columns
		transactions.column("#0",width=0, stretch=NO)
		transactions.column('ID',anchor=CENTER, width=25)
		transactions.column('token_name',anchor=W, width=50)
		transactions.column('txn_in',anchor=W, width=300)
		transactions.column('txn_in_price',anchor=CENTER, width=50)
		transactions.column('txn_out',anchor=W, width=300)
		transactions.column('txn_out_price',anchor=CENTER, width=50)
		transactions.column('qty_native',anchor=CENTER, width=50)
		transactions.column('qty_bnb',anchor=CENTER, width=50)
		transactions.column('profit',anchor=CENTER, width=50)
		transactions.column('status',anchor=CENTER, width=75)

		# Create Transactions Headings
		transactions.heading("#0",text="", anchor=W)
		transactions.heading("ID",text="ID",anchor=CENTER)
		transactions.heading("token_name",text="Token Name",anchor=W)
		transactions.heading("txn_in",text="Buy Hash",anchor=W)
		transactions.heading("txn_in_price",text="Buy Price",anchor=CENTER)
		transactions.heading("txn_out",text="Sell Hash",anchor=W)
		transactions.heading("txn_out_price",text="Sell Price",anchor=CENTER)
		transactions.heading("qty_native",text="Quantity Native",anchor=CENTER)
		transactions.heading("qty_bnb",text="Quantity BNB",anchor=CENTER)
		transactions.heading("profit",text="Profit Per Token",anchor=CENTER)
		transactions.heading("status",text="Status",anchor=CENTER)

		for c,r in enumerate(self.txns):
			if c % 2 == 0:
				transactions.insert(parent="", index='end', iid=c,text="", values=(r[0], r[-5], r[1], r[2], r[-4], r[-3], r[3], r[4], r[-2], r[-1]),tags=("even"))
			else:
				transactions.insert(parent="", index='end', iid=c,text="", values=(r[0], r[-5], r[1], r[2], r[-4], r[-3], r[3], r[4], r[-2], r[-1]),tags=("odd"))

		transactions.tag_configure("even",background=self.bg_text)

		return None

	def _buildFTokens(self):
		tokens_list_frame = Frame(self.tokens_frame,bg=self.bg_color)
		tokens_list_frame.pack(fill="both",expand=1)
			#Create Scrollbar
		tokens_scroll = Scrollbar(tokens_list_frame)
		tokens_scroll.pack(side=RIGHT, fill=Y)
			#Create Treeview
		tokens = ttk.Treeview(tokens_list_frame, yscrollcommand = tokens_scroll.set, selectmode="browse")
			#pack to the screen
		tokens.pack(fill="both", expand=1)
			# Configure the scrollbar
		tokens_scroll.config(command = tokens.yview)
			# Define Our Columns
		tokens['columns'] = ("ID","Name","Address","Did_Add","Price","Slippage","Fees")


			#Format Tokens List Columns
		tokens.column("#0",width=0, stretch=NO)
		tokens.column('ID',anchor=CENTER, width=40)
		tokens.column('Name',anchor=W, width=100)
		tokens.column('Address',anchor=W, width=400)
		tokens.column('Did_Add',anchor=CENTER, width=80)
		tokens.column('Price',anchor=CENTER, width=125)
		tokens.column('Slippage',anchor=CENTER, width=100)
		tokens.column('Fees',anchor=CENTER, width=125)

			# Create Tokens List Headings
		tokens.heading("#0",text="")
		tokens.heading("ID",text="ID",anchor=CENTER)
		tokens.heading("Name",text="Name",anchor=W)
		tokens.heading("Address",text="Address",anchor=W)
		tokens.heading("Did_Add",text="Did Add?",anchor=CENTER)
		tokens.heading("Price",text="Price",anchor=CENTER)
		tokens.heading("Slippage",text="Slippage",anchor=CENTER)
		tokens.heading("Fees",text="Fees",anchor=CENTER)

		# id , name, didadd, price, slip, contract

		for c,r in enumerate(self.tkns):
			if c % 2 == 0:
				tokens.insert(parent="", index='end', iid=c,text="", values=(r[0], r[1], r[-1], r[2], r[3], r[4], 'Instant(7GEWI)'),tags=("even"))
			else:
				tokens.insert(parent="", index='end', iid=c,text="", values=(r[0], r[1], r[-1], r[2], r[3], r[4], 'Instant(7GEWI)'),tags=("odd"))

		tokens.tag_configure("even",background=self.bg_text)


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

	def _buildFWallet(self):

		connect_button = Button(self.wallet_frame,image=self.connect_wallet_img,bg=self.bg_color,activebackground=self.bg_color,bd=0,cursor="hand2",).place(x=300,y=200)

	def _buildFParams(self):
		
		self.round_rectangle(100,25,700,450,20, fill=self.bg_text)

		Label(self.params_frame, text="Edit Bot Parameters", bg=self.bg_text, fg=self.text_color, font=('',20,'bold')).pack(pady=25)

		Label(self.params_frame, text="Max Amount/Token", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=200)
		self.max_amt_per_tok = Scale(self.params_frame,
			from_=0, 
			to=100, 
			orient = HORIZONTAL,
			length = 225,
			tickinterval=100, 
			sliderrelief='flat', 
			highlightthickness=0, 
			background=self.bg_text,
			fg=self.text_color, 
			cursor="hand2", 
			troughcolor='#fff', 
			activebackground='#1065BF')
		self.max_amt_per_tok.place(x=110,y=250)

		Label(self.params_frame, text="Slippage", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=500,y=200)
		self.slip = Scale(self.params_frame,
			from_=0, 
			to=100,
			orient = 'horizontal',
			length=225,
			tickinterval=100, 
			sliderrelief='flat', 
			highlightthickness=0, 
			background=self.bg_text, 
			fg=self.text_color,
			cursor="hand2",
			troughcolor='#fff', 
			activebackground='#1065BF',
			)
		self.slip.place(x=450,y=250)

		Label(self.params_frame,text="Change Address", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=100)
		self.address_entry =  Entry(self.params_frame, width=50, background=self.bg_color, fg='#fff')
		self.address_entry.place(x=110,y=150)

		Label(self.params_frame,text="Max to trade", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=500, y=100)
		self.amt_entry = Entry(self.params_frame, width=25, background=self.bg_color, fg='#fff')
		self.amt_entry.place(x=500,y=150)

		save_edit = Button(
				self.params_frame,
				image=self.save_img, 
				bg=self.bg_text,
				activebackground=self.bg_card,
				bd=0,
				cursor="hand2",
				command=self.changeParams).place(x=350, y=375)
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

	def _runUIUX(self):
		self._buildNotebook()
		self._startUIUX()
		self.base.mainloop()



if __name__ == '__main__':
	u = UIUX('/home/kj/BOT_front-run/frontrun/',(1, 'Front Run', '10', '7', '0x1a0119e9268915Fb085387A4d0bf9C57E696D282', '0', '0', '0', '2'),[(1, '0x81823', '2.1', '294', '1', 'ref_1', 'MBOX', '0x81824', '2.6', '0.5', 'False')],[(1, 'WBNB', 'True', '404.23', '0xbb4CdB9CBd36B01bD1cBaEBF2De08d9173bc095c'), (3, 'MBOX', 'True', '4.9', '0xasd4f021fd')])
	u._runUIUX()