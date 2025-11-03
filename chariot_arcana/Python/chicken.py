n,k=map(int,input().split())
h=[int(input())for _ in range(n)]
if k>1:
 import heapq;heapq.heapify(h);s=0
 while len(h)>1:t=sum(heapq.heappop(h)for _ in range(min(k,len(h))));s+=t;heapq.heappush(h,t)
 print(s)
else:h.sort(reverse=1);print(sum(x*-~i for i,x in enumerate(h)))