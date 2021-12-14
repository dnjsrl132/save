import tkinter as tk

def f1():
    print(str1.get())
    str1.set('DDDDDD')

win = tk.Tk()
win.geometry('200x200')
str1 = tk.StringVar()
str1.set('ZZZZZZ')

l1 = tk.Label(win,textvariable = str1)
l1.pack()

b1 = tk.Button(win, textvariable = str1, command = f1)
b1.pack()



win.mainloop()