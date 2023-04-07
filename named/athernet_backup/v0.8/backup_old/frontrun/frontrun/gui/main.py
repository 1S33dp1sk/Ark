from tkinter import *
from tkinter import ttk
from tkinter.messagebox import showinfo
# from ttkbootstrap import Style
import time

bg_color = '#e7eff6'
bg_text = '#adcbe3'
bg_card = '#4b86b4'
text_color = "#2a4d69"
font_style = ("Nanum Pen Script", 16, "bold")

root = Tk()
root.title('Front Run')
root.geometry('1000x600')

style = Style()

root.config(background=bg_color)

def main():
    buildBar()
    root.mainloop()

def buildBar():

    progress_bar = ttk.Progressbar(root, orient=HORIZONTAL, length=400, mode='determinate', style = 'primary.Striped.Horizontal.TProgressbar',maximum=100)
    progress_bar.place(x=300,y=300)

    bar_val = Label(root,text="", font=font_style,bg=bg_color, fg=text_color)
    bar_val.place(x=720, y=300)

    bar_st = Label(root, text="",font=font_style, bg=bg_color, fg=text_color)
    bar_st.place(x=300, y=350)

    def task():

        bar_val.config(text=str(progress_bar['value'])+'%')
        if progress_bar['value'] < 15:
            bar_st.config(text='Checking Internet Connection...')
        elif progress_bar['value'] == 30:
            bar_st.config(text='Checking Mozilla Firefox...')
        elif progress_bar['value'] == 65:
            bar_st.config(text='Checking MetaMask...')
        elif progress_bar['value'] == 75:
            bar_st.config(text='Checking Database...')

        progress_bar['value'] += 1

        if progress_bar['value'] > 100:
            progress_bar.destroy()
            bar_val.destroy()
            bar_st.destroy()
            showinfo(message='The progress completed!')
            buildTabs()
            return
        else:
            root.after(100,task)

    root.after(100, task)

def buildTabs():
    notebook = ttk.Notebook(root)
    notebook.pack(fill=BOTH, expand=1)

    frame1 = ttk.Frame(notebook, width=800, height=600)
    frame2 = ttk.Frame(notebook,width=800,height=600)


    frame1.pack(fill=BOTH, expand=1)
    frame2.pack(fill=BOTH, expand=1)

    notebook.add(frame1, text='General Information')
    notebook.add(frame2, text="Profile")




