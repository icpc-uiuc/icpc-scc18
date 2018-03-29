n, m, k = [int(s) for s in input().split()]
assert(1 <= n)
assert(n <= 100000000)
assert(1 <= m)
assert(m <= 50)
assert(0 <= k)
assert(k <= 1000)

f = set()
for i in range(k):
    s = input().split()
    assert(s[0] == 'A' or s[0] == 'B')
    if s[0] == 'A':
        a, b = int(s[1]), int(s[2])
        if a > b:
            a, b = b, a
        assert((a, b) not in f)
        f.add((a, b))
        assert(1 <= a and a <= m)
        assert(1 <= b and b <= m)
    else:
        p, r, g = int(s[1]), int(s[2]), set()
        assert(1 <= p and p <= n)
        assert(r < 20 and r == len(s) - 3)
        for i in range(3, len(s)):
            x = int(s[i])
            assert(1 <= x and x <= m)
            assert(x not in g)
            g.add(x)

print('OK')
