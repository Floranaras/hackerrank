import sys
from functools import reduce

input = sys.stdin.readline
MOD = 10**9 + 7
power = lambda base, exp, mod: 1 if not exp else (power((base * base) % mod, exp >> 1, mod) if not exp & 1 else (base * power(base, exp - 1, mod)) % mod)
solve = lambda n, r: 0 if r > n or r < 0 else 1 if r == 0 or r == n else (lambda r: (lambda num, den: num * power(den, MOD - 2, MOD) % MOD)(*reduce(lambda acc, i: (acc[0] * (n - i) % MOD, acc[1] * (i + 1) % MOD), range(r), (1, 1))))(min(r, n - r))

if __name__ == "__main__":
    q = int(input())
    [print(solve(*map(int, input().split()))) for _ in range(q)]
