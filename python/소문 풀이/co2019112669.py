fl=open('input_alice.txt','r')
s='compression'
fc=open('%s.cmp'%(s),'w')
fe=open('%s.dat'%(s),'w')
from collections import Counter
wordDict = Counter()
text=fl.readlines()
d={}
i=0
for ts in text:
    for wo in ts.split():
        wordDict[wo] += 1
for wo, nu in wordDict.most_common():
    if len(wo)>len(str(i)):
        d[wo]=i
        fe.write("%s %d\n"%(wo,i))
        i+=1
    else :
        d[wo]=-1
for ts in text:
    for wo in ts.split():
        if d[wo]==-1:
            fc.write("%s"%(wo))
        else :
            fc.write("%d"%(d[wo]))
        fc.write(" ")
    fc.write("\n")
fl.close()
fe.close()
fc.close()
