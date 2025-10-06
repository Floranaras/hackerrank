from functools import reduce
d, q = map(int, input().rstrip().split())
denoms = sorted(map(int, input().rstrip().split()))
queries = [int(input().rstrip()) for _ in range(q)]
max_v = max(queries)
dp = [1] + [0] * max_v
[[dp.__setitem__(i, dp[i] + dp[i - coin]) for i in range(coin, max_v + 1)]
 for coin in denoms]
[print(dp[v]) for v in queries]
