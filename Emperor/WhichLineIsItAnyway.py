from functools import reduce
solve = lambda n, k, vals: min(reduce(lambda dp, i: (min(dp[0] + vals[i][0], dp[1] + k + vals[i][0]), min(dp[1] + vals[i][1], dp[0] + k + vals[i][1])), range(1, n), (vals[0][0], vals[0][1])))
n, k = map(int, input().rstrip().split())
print(solve(n, k, [list(map(int, input().rstrip().split())) for _ in range(n)]))
