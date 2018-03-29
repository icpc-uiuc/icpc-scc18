from __future__ import division
from __future__ import print_function
from pprint import pprint

import sys

if sys.version_info < (3, 0):
    input = raw_input

n, m, k = [int(s) for s in input().split()]

M = 1000000007

def mat(n, m, val = 0):
    return [[val for j in range(m)] for i in range(n)]

def eye(n):
    return [[1 if i == j else 0 for j in range(n)] for i in range(n)]

def shape(v):
    return (len(v), len(v[0]))

v = mat(m, 1, 1)

A = mat(m, m, 1)
b = []

for i in range(k):
    r = input().split()
    t, x = r[0], [int(s) - 1 for s in r[1:]]
    if t == 'B':
        b.append((x[0], set(x[2:])))
    else:
        A[x[0]][x[1]] = 0
        A[x[1]][x[0]] = 0

b.sort(key = lambda x: x[0])

# base case
if len(b) > 0 and b[0][0] == 0:
    for i in range(m):
        if i in b[0][1]:
            v[i][0] = 0

mm = 0
mmops = 0
def mat_mul(A, B):
    global mmops, mm
    mm += 1
    n, m, r = len(A), len(A[0]), len(B[0])
    C = mat(n, r)
    for i in range(n):
        for j in range(r):
            for k in range(m):
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] % M) % M
    return C

def make_2_pow(A):
    v = [A]
    def f(i):
        while len(v) <= i:
            v.append(mat_mul(v[-1], v[-1]))
        return v[i]
    return f

A_2_pow = make_2_pow(A)

def A_pow(p, r):
    i = 0
    while p != 0:
        if p % 2 == 1:
            r = mat_mul(A_2_pow(i), r)
        i += 1
        p //= 2
    return r

b.append((n - 1, []))

i = 0
for j, f in b:
    if j > i:
        v = A_pow(j - i, v)
    for k in f:
        v[k][0] = 0
    i = j

s = 0
for x in v:
    for y in x:
        s = (s + y) % M
print(s)
