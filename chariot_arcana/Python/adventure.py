n,t=map(int,input().split())
d=[(input(),*map(int,input().split()))for _ in range(n)]
t*=60;u=c=0
for x in sorted(w+c for _,w,c in d):u+=x;c+=u<=t and 1
print(str(c)if c else"I need to find friends.")