from functools import reduce
n = int(input())
catalan = reduce(lambda c, i: c + [sum(c[j] * c[i-j-1] for j in range(i)) % (10**9+7)], range(1, n+1), [1])
print(catalan[n])
