from itertools import accumulate
n,k=map(int,input().split())
c=[input().split()for _ in range(n)]
r=sorted((int(p)for x,p in c if x=='red'),reverse=True)
b=sorted((int(p)for x,p in c if x=='blue'),reverse=True)
pr,pb=[0]+[*accumulate(r)],[0]+[*accumulate(b)]
print(*max(((i,pr[i]+pb[k-i])for i in range(min(k,len(r)),-1,-1)if k-i<=len(b)),
           default=(0,0),key=lambda x:(x[0],x[1])))
