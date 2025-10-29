import heapq
n,t=map(int,input().split())
h=[x for x,_ in(map(int,input().split())for _ in range(n))if x!=-1 and x<=t]
if not h:print("This exam is impossible!");exit()
heapq.heapify(h)
s=c=0
while h and s+h[0]<=t:s+=heapq.heappop(h);c+=1
print(c)
