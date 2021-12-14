def f(x):
    i=2
    d=[]
    while x>1:
        if(x%i==0):
            x/=i
            d.append(i)
            i-=1
        i+=1
    return d

if __name__ == '__main__':
    x=int(input())
    print(f(x))
