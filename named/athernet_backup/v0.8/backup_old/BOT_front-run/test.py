from tkinter import *
from PIL import ImageTk,Image


bg_color = '#e7eff6'
bg_text = '#adcbe3'
bg_card = '#4b86b4'
text_color = "#2a4d69"
font_style = ("Nanum Pen Script", 16, "bold")



root = Tk()
root.geometry('1000x650')
welcome_frame = Frame(root, bg=bg_text)
welcome_frame.pack(fill="both", expand=1)

save_img = PhotoImage(file="/home/raed_sh/Work/trail_bots/BOT_front-run/frontrun/gui/save.png")


def get_values(self):
	a = int(profitable_entry.get())
	p = str(private_entry.get())
	print(a)
	print(p)


def buile_welcome(self):

	Label(self.welcome_frame, text="Welcome", bg=self.bg_text, fg=self.text_color, font=('',32,'bold')).pack(pady=50)

	Label(self.welcome_frame,text="Wallet Address", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=175)
	self.profitable_entry =  Entry(self.welcome_frame, width=45, background=self.bg_color, fg=self.text_color, font=self.font_style)

	self.profitable_entry.place(x=110,y=225)

	Label(self.welcome_frame,text="Private Key", bg=self.bg_text, fg=self.text_color, font=self.font_style).place(x=110,y=325)
	self.private_entry =  Entry(self.welcome_frame, width=45, background=self.bg_color, fg=self.text_color, font=self.font_style)
	self.private_entry.place(x=110,y=375)

	save_data = Button(
				self.welcome_frame,
				image=self.save_img,
				bg=self.bg_text,
				activebackground=self.bg_card,
				bd=0,
				cursor="hand2",
				command=self.get_values
				).place(x=450, y=500)



root.mainloop()
