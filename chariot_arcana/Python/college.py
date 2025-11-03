n,k=map(int,input().split())
v=sorted(int(input())for _ in range(n))[::-1]
print(sum(v[::k]))