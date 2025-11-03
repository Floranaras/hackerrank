l,w,d=map(int,input().split())
c=sorted([(int(input()),i)for i in range(3)for _ in [0]*[l,w,d][i]])[::-1]
a=b=e=t=0
for i,x in c:
 if x<1:t+=i*(b+1)*(e+1);a+=1
 elif x<2:t+=i*(a+1)*(e+1);b+=1
 else:t+=i*(a+1)*(b+1);e+=1
print(t%1000000007)