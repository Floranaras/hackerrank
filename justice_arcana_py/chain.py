c=[*map(int,input().split())][:10]
if len(c)<10:exit()
best=max((k-1+sum(min(x,k)for x in c[1:]) for k in range(1,c[0]+2)),default=0)
print(best)