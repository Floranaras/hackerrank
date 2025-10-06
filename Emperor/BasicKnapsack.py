from functools import reduce
n, c = map(int, input().split())
w = [int(input()) for _ in range(n)]
dp = reduce(lambda d, wt: [(d[i] + (d[i-wt] if i >= wt else 0)) % (10**9+7) for i in range(c+1)], w, [1] + [0]*c)
print(sum(dp) % (10**9+7))
