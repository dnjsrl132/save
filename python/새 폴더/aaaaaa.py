import tkinter as tk
import tkinter.ttk as tktk

def f1():
    la_str.set(com_str.get()+' '+str(check_i1.get())+' '+str(check_i2.get())+' '+ str(r_i.get()))

win = tk.Tk()
win.geometry('300x300')

la_str = tk.StringVar()
la_str.set('')
tk.Label(win,textvariable = la_str).pack()

com_str = tk.StringVar()
combo1 = tktk.Combobox(win, textvariable = com_str, state = 'readonly')
combo1['values'] = (1,2,3,4,5)
combo1.current(2)
combo1.pack()

check_i1 = tk.IntVar()
check_i2 = tk.IntVar()
check1 = tk.Checkbutton(win, text = 'checkbox1', variable = check_i1)
check2 = tk.Checkbutton(win, text = 'checkbox2', variable = check_i2)
check1.select()
check1.pack()
check2.pack()

r_i = tk.IntVar()
for i in range(5):
    tk.Radiobutton(win,text = str('rb '+str(i+1)), value = i+1, variable = r_i, command=f1).pack()



win.mainloop()