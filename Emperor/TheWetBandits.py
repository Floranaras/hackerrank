from functools import reduce
def solve(n, k, values):
    return 0 if n == 0 else values[0] if n == 1 else reduce(lambda dp, i: [dp[j] if j != i % len(dp) else max(dp[(i-1) % len(dp)], values[i] + (dp[(i-k-1) % len(dp)] if i > k else 0)) for j in range(len(dp))], range(1, n), [values[0]] + [0] * (min(n, k+2)-1))[(n-1) % min(n, k+2)]
if __name__ == "__main__":
    n, k = map(int, input().split())
    values = [int(input()) for _ in range(n)]
    print(solve(n, k, values))
