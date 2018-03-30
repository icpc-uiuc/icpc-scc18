def read():
    return [int(s) for s in input().split()]

N = 1000000

n, m = read()
assert(1 <= n and n <= 100)
assert(1 <= m and m <= 100)

f = set()
for i in range(n + m):
    x, y = read()
    assert(-N <= x and x <= N)
    assert(-N <= y and y <= N)
    assert((x, y) not in f)
    f.add((x, y))
