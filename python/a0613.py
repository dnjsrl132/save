import tkinter

def add():
    lf.configure(text=int(el.get())+int(ee.get()))
def sub():
    lf.configure(text=int(el.get())-int(ee.get()))
def gub():
    lf.configure(text=int(el.get())*int(ee.get()))
def na():
    lf.configure(text=int(el.get())/int(ee.get()))

win = tkinter.Tk()                           #win제목
win.geometry('400x400')                     #win크기
li=tkinter.Label(win,text='Operand 1')      #라벨
li.grid(row=0,column=0)                      #라벨의 위치
el=tkinter.Entry(win)                        #입력받을 칸
el.grid(row=0,column=1)                      #위치
el.focus()
le=tkinter.Label(win,text='Operand 2')
le.grid(row=1,column=0)
ee=tkinter.Entry(win)
ee.grid(row=1,column=1)
ee.focus()
lc=tkinter.Label(win,text='Result')
lc.grid(row=0,column=2)
lf=tkinter.Label(win,text='')
lf.grid(row=0,column=3)
blist=[0,0,0,0]
blist[0]=tkinter.Button(win,text='+',command=add)
blist[1]=tkinter.Button(win,text='-',command=sub)
blist[2]=tkinter.Button(win,text='*',command=gub)
blist[3]=tkinter.Button(win,text='/',command=na)
for i in range(4):
    blist[i].grid(row=2,column=i)
win.mainloop()