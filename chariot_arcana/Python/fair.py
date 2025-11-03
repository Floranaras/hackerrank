n,c=map(int,input().split())
v=sorted([(e,s)for s,e in[map(int,input().split())for _ in range(n)]])
l=-1; print(c*sum(1 for e,s in v if s>=l and(l:=e)))