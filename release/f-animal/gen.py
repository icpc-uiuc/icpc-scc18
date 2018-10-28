from random import randint as rand
from random import shuffle, seed

seed(514)

N = 100000000
v = []

# sample 1
v.append((3, 4, [
    ['A', 1, 3], 
    ['B', 1, 2], 
    ['A', 2, 4], 
    ['B', 3, 1, 2, 4]
]))

# sample 2
v.append((10, 2, []))

v.extend([
    (1, 1, []),
    (1, 1, [['B', 1, 1]]),
    (1, 1, [['A', 1, 1]]),
    (N, 1, []),
    (N, 2, [['A', 1, 1]]),
    (1, 50, [['A', 30, 40], ['B', 1, 10, 20]]),
    (2, 50, [['A', 30, 40], ['B', 1, 10, 20]]),
])

# blocked: 111111111111111111x...........
v.append((514, 1, [['B', 114, 1]]))

# can't be adjacent to self: 1x........
v.append((2411, 1, [['A', 1, 1]]))

# either 1 or 2
#     111111...
#     222222...
v.append((404, 2, [['A', 1, 2]]))

# alternating sequence
#     121212...
#     212121...
v.append((495, 2, [['A', 1, 1], ['A', 2, 2]]))

# one alternating sequence
#     121212...
v.append((20001, 2, [
    ['B', 9982, 2],
    ['B', 10031, 1],
    ['B', 10032, 2],
    ['B', 10777, 1],
    ['B', 19090, 2],
    ['B', 20001, 1],
    ['A', 1, 1],
    ['A', 2, 2]
]))

# no trivial cases
v.append((1000, 10, [['B', i+1, rand(1, 10)] for i in range(1000)]))

# a bit more evil...
v.append((1000, 12, [['B', 2, rand(1, 10)]] + 
                    [['B', 4 + i*2, rand(1, 10)] for i in range(100)] +
                    [['B', 1000 - i, rand(1, 11)] for i in range(100)]))


def make_pairs(n):
    v = [(i + 1, j + 1) for i in range(n) for j in range(i + 1)]
    shuffle(v)
    def f():
        return v.pop()
    return f

def make_pool(n):
    v = [i + 1 for i in range(n)]
    shuffle(v)
    def f():
        return v.pop()
    return f

def make_pos_pool(n):
    f = set()
    def g():
        while True:
            x = rand(1, n)
            if x not in f:
                f.add(x)
                return x
    return g

def pick(v):
    return v[rand(0, len(v)-1)]

N = [53475, 5426578, 76433734, 100000000, 100000000]
M = [5, 25, 50, 50]
K = [10, 100, 1000, 1000]
P = [0, 50, 100]

for i in range(24):
    n = pick(N)
    m = pick(M)
    k = pick(K)
    k1 = pick(P)*k//100
    k1 = min(m*(m+1)//3, k1)
    k2 = k - k1
    t = min(rand(1, 10), m - 3)

    f = make_pairs(m)
    r = []
    for i in range(k1):
        a, b = f()
        if rand(0, 99) < 47:
            a, b = b, a
        r.append(['A', a, b])

    g = make_pos_pool(n)
    for i in range(k2):
        h = make_pool(m)
        r.append(['B', g()] + [h() for i in range(rand(1, t))])
    shuffle(r)
    v.append((n, m, r))

for i in range(len(v)):
    n, m, r = v[i]
    with open('tests/%d.in' % i, 'w') as f:
        f.write('%d %d %d\n' % (n, m, len(r)))
        for x in r:
            if x[0] == 'B':
                f.write('%s %d %d' % (x[0], x[1], len(x) - 2))
                for j in range(2, len(x)):
                    f.write(' %d' % x[j])
            else:
                f.write('%s' % x[0])
                for j in range(1, len(x)):
                    f.write(' %d' % x[j])
            f.write('\n')
