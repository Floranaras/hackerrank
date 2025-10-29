import math
n,r=map(int,input().split())
e=sorted(abs(p-t)for t,p in(map(int,input().split())for _ in range(n))if p+1)
req=math.ceil(n*r/100)
print("It's impossible!"if req>len(e)else e[req-1])
