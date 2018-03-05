from random import choice
from random import randint as rand
from numpy.random import normal
import os

lower = list(map(chr, range(97, 123)))
digits = list(map(chr, range(48, 58)))
alpha = lower + digits
inf = 1000000

def empty(i, j, n):
    return ''

def randstr(a, k = 0):
    def f(i, j, n):
        return ''.join(choice(a) for i in range(rand(min(k, n), n)))
    return f

def comb(*args):
    def g(i, j, n):
        f = choice(args)
        return f(i, j, n)
    return g

shapes = [
    (1, 1, 8, 3),
    (1, 2, 20, 6),
    (2, 1, 20, 6),
    (4, 4, 16, 5),
    (6, 6, 10, 5),
    (100, 8, 12, 4),
    (100, 16, 4, 2),
    (100, 32, 2.2, 1),
    (100, 100, 4, 1)
]

generators = [
    empty, 
    randstr(lower),
    randstr(digits),
    comb(empty, randstr(alpha, 1), 
         randstr(lower, 1), randstr(digits, 1)),
    comb(randstr(alpha, inf),
         randstr(lower, inf),
         randstr(digits, inf),
         randstr(alpha, inf),
         randstr(alpha, inf),
         randstr(alpha, inf),
         randstr(digits, 0))
]

def make_new_fn():
    n = 0
    def f():
        nonlocal n
        n += 1
        return '%d.in' % n
    return f
new_fn = make_new_fn()

try:
    os.mkdir('tests')
except:
    pass

d = set()
for n, m, mu, s in shapes:
    for f in generators:
        r = 99 - m + 1
        k = []
        for i in range(m):
            t = min(int(round(normal(mu, s))), r)
            r -= t
            k.append(t)
        v = [[f(i, j, k[j]) for j in range(m)] for i in range(n)]
        y = '%d\n%s' % (n, '\n'.join(','.join(x) for x in v))
        if y not in d:
            d.add(y)
            with open('tests/' + new_fn(), 'w') as fh:
                fh.write(y)
