ll=[['1','2','3'],['4','5','6'],['7','8','9']]
x=[[0,0,0],[0,0,0],[0,0]]
o=[[0,0,0],[0,0,0],[0,0]]
c=0
def f(n,m):
    a=(m-1)//3
    b=(m-1)%3
    if ll[a][b]>'9':
        return
    ll[a][b]=n
    if n=='x':
        x[0][a]+=1
        x[1][b]+=1
        if a==b:
            x[2][0]+=1
        if a+b==2:
            x[2][1]+=1
    else:
        o[0][a]+=1
        o[1][b]+=1
        if a==b:
            o[2][0]+=1
        if a+b==2:
            o[2][1]+=1

print("Who is first?")
first=input()

if first == "com":
    f('x',5)

for i in range(3):
    for j in range(3):
        print("%3s" % (ll[i][j]), end='')
    print("\n")

y = int(input())
f('o',y)
if first == "com":
    if y%2:
        z=10-y
    elif y<5 :
        z=9
    else:
        z=1
else:
    if ll[1][1] != 'o':
        z=5
    else:
        z=7
f('x',z)
c=1
win=""
while True:
    z=0
    for i in range(3):
        for j in range(3):
            print("%3s"%(ll[i][j]),end='')
        print("\n")
    if c==9 or win!="":
        print('Gameover')
        print('winner:'+win)
        break
    y = int(input())
    if ll[(y-1)//3][(y-1)%3]>'9':
        print('try again')
        continue
    f('o',y)
    c+=1
    for i in range(3):
        if ll[i][0]==ll[i][1]:
            if ll[i][2]<='9':
                z=3*i+3
        elif ll[i][0]==ll[i][2]:
            if ll[i][1]<='9':
                z=3*i+2
        elif ll[i][1]==ll[i][2]:
            if ll[i][0]<='9':
                z=3*i+1
        if ll[0][i]==ll[1][i]:
            if ll[2][i]<='9':
                z=3*2+i+1
        elif ll[0][i]==ll[2][i]:
            if ll[1][i]<='9':
                z=3*1+i+1
        elif ll[1][i]==ll[2][i]:
            if ll[0][i]<='9':
                z=i+1
    if z==0:
        if ll[0][0] == ll[1][1]:
            if ll[2][2] <= '9':
                z = 3 * 2 + 3
        elif ll[0][0] == ll[2][2]:
            if ll[1][1] <= '9':
                z = 3 * 1 + 2
        elif ll[1][1] == ll[2][2]:
            if ll[0][0] <= '9':
                z = 1
        if ll[2][0]==ll[1][1]:
            if ll[0][2]<='9':
                z=3
        elif ll[2][0]==ll[0][2]:
            if ll[1][1]<='9':
                z=3*1+2
        elif ll[1][1]==ll[0][2]:
            if ll[2][0]<='9':
                z=3*2+1
    if z==0:
        print("I pass my turn")
    f('x',z)
    c+=1
    for i in range(3):
        for j in range(3):
            if i==2 and j==2:
                break
            if x[i][j]==3:
                win="computer"
            elif o[i][j]==3:
                win="user"