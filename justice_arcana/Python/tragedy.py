import sys,heapq
d=sys.stdin.read().strip().split()
if len(d)<3:sys.exit()
n,f,k=map(int,d[:3]);a=list(map(int,d[3:3+n]))
print("YES" if sum(heapq.nsmallest(k,a))<=f else "NO")