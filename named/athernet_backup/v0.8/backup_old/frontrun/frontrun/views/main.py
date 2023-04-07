from tkinter import *
from tkinter import ttk
from PIL import ImageTk,Image



# Constants
bg_color = "#36454F"


# Original root of the window
root = Tk()
root.title("Front-Run Sniper Bot")
root.geometry('600x400')
root.config(bg=bg_color)


# Add some style
style = ttk.Style()
# pick a theme
style.theme_use('clam')


#configure our treeview
style.configure("Treeview",
	background="#707070",
	foreground="#707070",
	rowheight=25,
	borderwidth=0,
	fieldbackground="#707070"
	)

style.map('Treeview',
	background=[('selected','blue')])

font_style = ("Comic Sans MS", 12, "bold")


# Keep track of the button state on/off
global is_on
is_on = True



my_notebook = ttk.Notebook(root)
my_notebook.pack()



def select():
	return my_notebook.select(1)

transactions_frame = Frame(my_notebook, width=600, height=350, bg=bg_color)
tokens_frame = Frame(my_notebook, width=600, height=350, bg=bg_color)
wallet_frame = Frame(my_notebook, width=600, height=350, bg=bg_color)
params_frame = Frame(my_notebook, width=600, height=350, bg=bg_color)
info_frame = Frame(my_notebook, width=600, height=350, bg=bg_color)


transactions_frame.pack(fill="both", expand=1)
tokens_frame.pack(fill="both", expand=1)
wallet_frame.pack(fill="both", expand=1)
params_frame.pack(fill="both", expand=1)
info_frame.pack(fill="both", expand=1)

my_notebook.add(info_frame, text="Info")
my_notebook.add(transactions_frame, text="Transactions")
my_notebook.add(tokens_frame, text="Tokens")
my_notebook.add(wallet_frame, text="Connect Wallet")
my_notebook.add(params_frame, text="Parameters")

canvas = Canvas(params_frame,width=600,height=400,bg=bg_color)
canvas.pack(fill="both",expand=1)

def round_rectangle(x1, y1, x2, y2, r=25, **kwargs):    
    points = (x1+r, y1, x1+r, y1, x2-r, y1, x2-r, y1, x2, y1, x2, y1+r, x2, y1+r, x2, y2-r, x2, y2-r, x2, y2, x2-r, y2, x2-r, y2, x1+r, y2, x1+r, y2, x1, y2, x1, y2-r, x1, y2-r, x1, y1+r, x1, y1+r, x1, y1)
    return canvas.create_polygon(points, **kwargs, smooth=True)

sliders_canvas = round_rectangle(25,25,575,350,20, fill="#707070")

tole = Scale(canvas,
	from_=0, 
	to=100,
	label="Tolerance",
	orient = 'horizontal',
	tickinterval=100, 
	sliderrelief='flat', 
	highlightthickness=0, 
	background='grey', 
	fg='#fff', 
	troughcolor='#73B5FA', 
	activebackground='#1065BF')
tole.pack(ipadx='100',pady=40)
max_amt_trade = Scale(canvas,
	from_=0,
 	to=100,
 	orient = HORIZONTAL,
 	label="max trade amount",
 	tickinterval=100, 
 	sliderrelief='flat', 
 	highlightthickness=0, 
 	background='grey', 
 	fg='#fff', 
 	troughcolor='#73B5FA', 
 	activebackground='#1065BF')
max_amt_trade.pack(ipadx='100')
max_amt_per_tok = Scale(canvas,
	from_=0, 
	to=100, 
	orient = HORIZONTAL,
	label="max amount per token",
	tickinterval=100, 
	sliderrelief='flat', 
	highlightthickness=0, 
	background='grey', 
	fg='#fff', 
	troughcolor='#73B5FA', 
	activebackground='#1065BF')
max_amt_per_tok.pack(ipadx='100',pady=30)



# Create Treeview Frame
tokens_list_frame = Frame(tokens_frame)
tokens_list_frame.pack(fill="both",expand=1)

#Create Scrollbar
tokens_scroll = Scrollbar(tokens_list_frame)
tokens_scroll.pack(side=RIGHT, fill=Y)

#Create Treeview
my_tree = ttk.Treeview(transactions_frame, selectmode="none")
tokens = ttk.Treeview(tokens_list_frame, yscrollcommand = tokens_scroll.set, selectmode="browse")

#pack to the screen
my_tree.pack(pady=20)
tokens.pack()


# Configure the scrollbar
tokens_scroll.config(command = tokens.yview)


# Define Our Columns
my_tree['columns'] = ("Name","ID","Amount")
tokens['columns'] = ("ID","Name","Address","Did Add","Price","Slippage","Fees")


#Formate Our Columns
my_tree.column("#0",width=0, stretch=NO)
my_tree.column('Name',anchor=W, width=180)
my_tree.column('ID',anchor=CENTER, width=100)
my_tree.column('Amount',anchor=W, width=120)

# Create Headings
my_tree.heading("#0",text="", anchor=W)
my_tree.heading("Name",text="Token Name",anchor=W)
my_tree.heading("ID",text="ID",anchor=CENTER)
my_tree.heading("Amount",text="Amount",anchor=W)

#Formate Our Tokens List Columns
tokens.column("#0",width=0, stretch=NO)
tokens.column('ID',anchor=W, width=50)
tokens.column('Name',anchor=CENTER, width=100)
tokens.column('Address',anchor=W, width=150)
tokens.column('Did Add',anchor=CENTER, width=70)
tokens.column('Price',anchor=CENTER, width=50)
tokens.column('Slippage',anchor=CENTER, width=50)
tokens.column('Fees',anchor=CENTER, width=100)

# Create Tokens List Headings
tokens.heading("#0",text="", anchor=W)
tokens.heading("ID",text="ID",anchor=W)
tokens.heading("Name",text="Name",anchor=CENTER)
tokens.heading("Address",text="Address",anchor=W)
tokens.heading("Did Add",text="Did Add?",anchor=CENTER)
tokens.heading("Price",text="Price",anchor=CENTER)
tokens.heading("Slippage",text="Slippage",anchor=CENTER)
tokens.heading("Fees",text="Fees",anchor=CENTER)


#Add Data
bnb_logo = ImageTk.PhotoImage(Image.open("bnb.png"))

#Label(wallet_frame,image=bnb_logo).pack()

data = [
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
	["Raed",1,"bnb.png",bnb_logo],
	["Karam",2,"ETH",bnb_logo],
	["Raed",3,"BNB",bnb_logo],
	["Raed",4,"BNB",bnb_logo],
	["Raed",5,"BNB",bnb_logo],
]

count = 0
for record in data:
	my_tree.insert(parent="", index='end', iid=count,text="", values=(record[0], record[1], record[2]))
	tokens.insert(parent="", index='end', iid=count,text="", values=(record[3], count, record[2]))
	count += 1




def openNewWindow():
     
    # Toplevel object which will
    # be treated as a new window
    newWindow = Toplevel(root)
 
    # sets the title of the
    # Toplevel widget
    newWindow.title("New Window")
 
    # sets the geometry of toplevel
    newWindow.geometry("200x200")
 
    # A Label widget to show in toplevel
    Label(newWindow,text ="This is a new window").pack()
    Label(newWindow,text ="Your Name").pack()
    new_name = Entry(newWindow,width=50).pack(pady=10,padx=5)
    Label(newWindow,text ="Your Address").pack()
    new_address= Entry(newWindow,width=50).pack(pady=10,padx=5)

    save_btn = Button(newWindow, text="Save",width=25,bg="green",command=newWindow.quit).pack(pady=10)


new_token = PhotoImage(file="button_add_new_token.png")
add_new_token = Button(
	tokens_frame,image = new_token,
	width=160,
	height=41,
	bg=bg_color,
	activebackground=bg_color,
	borderwidth=0,
	cursor="hand2",
	command=openNewWindow).pack(pady=10)

# Frame Of Tokens 
tokens_have = Label(transactions_frame,text="Tokens We Have: ",width=20,anchor=W,font=("Verdana",20)).place(x=10,y=360)

bnb = Label(transactions_frame,text="10 BNB",width=10,bg="silver", borderwidth=2, relief="groove").place(x=20,y=410)
eth = Label(transactions_frame,text="35 ETH",width=10,bg="silver", borderwidth=2, relief="groove").place(x=100,y=410)
dog = Label(transactions_frame,text="75 DOGE",width=10,bg="silver", borderwidth=2, relief="groove").place(x=180,y=410)
cat = Label(transactions_frame,text="150 CAT",width=10,bg="silver", borderwidth=2, relief="groove").place(x=260,y=410)




#------------ Information Frame--------------

BNB = "100 BNB"

def switch():
	global is_on
	if is_on:
		switch_btn.config(image=off)
		is_on = False
	else:
		switch_btn.config(image=on)
		is_on = True

on = PhotoImage(file="on.gif")
off = PhotoImage(file="off.gif")


bot_name = Label(info_frame,text="BOT NAME",fg="#fff",bg=bg_color,font=font_style).pack(pady=10)
bot_id = Label(info_frame,text="ID: 2021DRS",fg="#fff",bg=bg_color,font=font_style).pack(pady=5)
total_investment = Label(info_frame,text="Total Investment ="+BNB,fg="#fff",bg=bg_color,font=font_style).place(x=10,y=100)
amount_to_trade = Label(info_frame,text="Amount To Trade ="+BNB,fg="#fff",bg=bg_color,font=font_style).place(x=10,y=140)
total_profits = Label(info_frame,text="Total Profits ="+BNB,fg="#fff",bg=bg_color,font=font_style).place(x=10,y=180)
profit_address = Label(info_frame,text="Profit Address:",fg="#fff",bg=bg_color,font=font_style).place(x=320,y=100)
profitable_trades = Label(info_frame,text="Profitable Trades: ",fg="#fff",bg=bg_color,font=font_style).place(x=320,y=140)
transfer_profits_count = Label(info_frame,text="Transfer Profits Count: ",fg="#fff",bg=bg_color,font=font_style).place(x=320,y=180)
tokens_count: Label(info_frame,text="Tokens Count: ",fg="#fff",bg=bg_color,font=font_style).place(x=320,y=220)

switch_btn = Button(info_frame,image=on,width=60,height=60,bd=0,command=switch)
switch_btn.place(x=250,y=250)
#---------------- End--------------------------





root.mainloop()