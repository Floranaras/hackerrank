n = int(input()); a = [int(input()) for _ in range(n)]
p = [x for x in a if x > 0]
print(len(p) or 1, sum(p) if p else max(a))