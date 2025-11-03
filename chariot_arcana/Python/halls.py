p,n=map(int,input().split())
t=[int(input())for _ in range(n)]
l=1;r=max(t);exec("m=(l+r)//2;l,r=(l,m-1)if sum((x+m-1)//m for x in t)<=p else(m+1,r);"*50);print(l)