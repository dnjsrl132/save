import tkinter

def f18(v):
    if(v=='c'):
        op.set('')
    elif(v=='='):
        op.set(op.get()+'='+str(eval(op.get())))
    else:
        op.set(op.get()+v)


win = tkinter.Tk()
win.geometry('300x300')
f1 = tkinter.Frame()
f2 = tkinter.Frame()
op = tkinter.StringVar()
op.set('')

b_list = ['1','2','3','+','=','c']
l1 = tkinter.Label(f1, textvariable = op)
l1.pack()

for i, bu in enumerate(b_list):
    tkinter.Button(f2,text = bu,command = lambda cc = bu:f18(cc)).grid(row=i//3, column = i%3)

f1.pack()
f2.pack()
win.mainloop()