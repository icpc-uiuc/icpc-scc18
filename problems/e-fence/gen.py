from math import sin, pi, cos, sqrt
from random import randint, shuffle, seed
from random import random as rand

seed(495)

pi2 = pi*2

v = []

N = 1000000

# sample 1
A = [(2, 0), (1, 2), (-1, 2), (-2, 1), (-1, 0), (0, -2)]
B = [(0, 0), (1, 1), (-1, 1), (0, -1)]
v.append((A, B))

# sample 2
A = [(0, 0), (1, 1), (-1, 1)]
B = [(0, 1)]
v.append((A, B))

# 1 + 1 RB
v.append(([(3, -4)], [(4, -3)]))

# colinear RBR
A = [(-4, -6), (4, 6)]
B = [(2, 3)]
v.append((A, B))

# not enclosed
A = [(-1, -1), (1, -1), (0, 1)]
B = [(0, 0), (2, 2)]
v.append((A, B))

# boundary
A = [(0, 0), (2, 0), (2, 2), (0, 2)]
B = [(1, 0), (2, 1), (1, 2), (0, 1)]
v.append((A, B))

# star
A = [(0, 3), (3, 0), (0, -3), (-3, 0), 
     (1, 1), (1, -1), (-1, 1), (-1, -1)]
B = [(0, 0)]
v.append((A, B))

# extreme 1
A = [(N, N), (-N, N), (N, -N), (-N, -N)]
B = [(0, 0)]
v.append((A, B))

# extreme 2
A = [(0, 0), (N, 0), (0, N)]
B = [(N//2, 1), (1, N//2)]
v.append((A, B))

# extreme 3
A = [(0, 0), (N, 0), (N//2, N)]
B = [(N//2, 0)]
v.append((A, B))

def polar(a, r, x = 0, y = 0):
    n = len(a)
    if callable(r):
        return [(int(x + r(t)*cos(t)), int(y + r(t)*sin(t))) for t in a]
    elif isinstance(r, (list, tuple)):
        assert(n == len(r))
        return [(int(x + r[i]*cos(a[i])), int(y + r[i]*sin(a[i])))
                for i in range(n)]
    else:
        return [(int(x + r*cos(t)), int(y + r*sin(t))) for t in a]

def rand_circle(n, R, x = 0, y = 0):
    v = []
    for i in range(n):
        r = sqrt(rand()*R*R)
        a = rand()*pi2
        
        v.append((int(x + r*cos(a)), int(y + r*sin(a))))
    return v


# concentric
alpha = [i/20*pi2 for i in range(20)]
d = 10
A = polar(alpha, d) + polar(alpha, d*3) + polar(alpha, d*5)
A += rand_circle(10, d*.4, 0, -d) + rand_circle(16, d*.4, 0, -d*3) + rand_circle(25, d*.4, 0, -d*5)
B = polar(alpha, d*2) + polar(alpha, d*4)
B += rand_circle(12, d*.4, 0, -d*2) + rand_circle(20, d*.4, 0, -d*4)
v.append((A, B))

# sin
alpha = [i/100*pi2 for i in range(100)]
A = polar(alpha, lambda a: sin(a*15.73)*4+20)
B = polar(alpha, lambda a: sin(a*7.9 + 1.24)*2+20)
v.append((A, B))

# circular
for i in range(4):
    A = rand_circle(100, 1000 if i < 2 else 1000000)
    B = rand_circle(100, 800 if i < 2 else 900000)
    v.append((A, B))

# rectangular
for d in [100, 10000, N]:
    for i in range(2):
        s = d if i == 0 else int(d*.85)
        A = [(randint(-d, d), randint(-d, d)) for j in range(100)]
        B = [(randint(-s, s), randint(-s, s)) for j in range(100)] 
        v.append((A, B))

# clusters
for i in range(6):
    A, B = [], []
    p = 1 if i < 3 else 3
    for j in range(10):
        A.extend(rand_circle(10, randint(500, 1000), randint(-10000, 10000), randint(-10000, 10000)))
    for j in range(3):
        B.extend(rand_circle(30, randint(800, 1200), 
                 p*randint(-3000, 3000), 
                 p*randint(-3000, 3000)))
    v.append((A, B))

i = 0
for A, B in v:
    a, b = set(A), set(B)
    b = [x for x in b if x not in a]
    a, b = list(a), list(b)
    shuffle(a)
    shuffle(b)
    a = a[:100]
    b = b[:100]
    if len(a) <= 0 or len(b) <= 0:
        continue
    with open('tests/%d.in' % i, 'w') as f:
        r = [(len(a), len(b))] + a + b
        f.write('\n'.join('%d %d' % (x, y) for x, y in r))
    i += 1
