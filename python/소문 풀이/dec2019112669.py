s='compression'
fc=open('%s.cmp'%(s),'r')
fe=open('%s.dat'%(s),'r')
fl=open('de%s.txt'%(s),'w')
text=fe.readlines()
d={}
i=0
for ts in text:
    ts=ts.split()
    d[ts[1]]=ts[0]

text=fc.readlines()
for ts in text:
    for wo in ts.split():
        if '0'<=wo<'A':
            fl.write("%s "%(d[wo]))
        else:
            fl.write("%s "%(wo))
    fl.write("\n")
fl.close()
fc.close()
fe.close()
