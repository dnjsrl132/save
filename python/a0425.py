a=int(input())
for i in range(a):
    for j in range(0,i+a):
        if j<a-i-1: print(' ',end='')
        else: print(abs(a-j-1)+1,end='')
    print()
