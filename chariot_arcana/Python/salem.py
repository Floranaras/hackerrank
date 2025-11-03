L,n=map(int,input().split())
c=sorted([*map(int,input().split())]for _ in range(n))
e=i=r=0
while e<L:
 t=e
 while i<n and c[i][0]<=e+1:t=max(t,c[i][1]);i+=1
 if t==e:print("'Salem's Lot is doomed.");exit()
 e=t;r+=1
print(n-r)