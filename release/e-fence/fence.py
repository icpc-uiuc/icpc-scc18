from math import sqrt
from pprint import pprint

def add(a, b):
    return (a[0] + b[0], a[1] + b[1])
    
def sub(a, b):
    return (a[0] - b[0], a[1] - b[1])
    
def dot(a, b):
    return a[0]*b[0] + a[1]*b[1]
    
def cross(a, b):
    return a[0]*b[1] - a[1]*b[0]
    
def dist(a, b):
    x = a[0] - b[0]
    y = a[1] - b[1]
    return sqrt(x*x + y*y)
    
eps = 1e-5    
inf = 1000000000000.

def read():
    return [int(s) for s in input().split()]

# c is on the right of a -> b
def left(a, b, c):
    return cross(sub(b, a), sub(c, a)) > 1e-6

n, m = read()
A = [read() for i in range(n)]
B = [read() for i in range(m)]

def left_to_all(a, b):
    for c in B:
        if not left(a, b, c):
            return False
    return True

f = [[inf for j in range(n)] for i in range(n)]
for i in range(n):
    for j in range(n):
        if i != j and left_to_all(A[i], A[j]):
            f[i][j] = dist(A[i], A[j])
           
def F(x):
    return '----' if x >= inf - eps else '%.2f' % x
            
def debug():
    return [[F(f[i-1][j-1]) if i > 0 and j > 0 else 
             str(A[i-1])    if i > 0           else 
             str(A[j-1])    if j > 0           else 
             ''                                     for j in range(n + 1)] for i in range(n + 1)]
            
def mat2str(v):
    n, m = len(v), len(v[0])
    w = [max(len(v[i][j]) for i in range(n)) for j in range(m)]
    v = [[v[i][j] + ' '*(w[j] - len(v[i][j])) for j in range(m)] for i in range(n)]
    return '\n'.join('|'.join(r) for r in v)

#print(mat2str(debug()))

for k in range(n):
    for i in range(n):
        for j in range(n):
            f[i][j] = min(f[i][k] + f[k][j], f[i][j])

#print(mat2str(debug()))
r = min(f[i][i] for i in range(n))
print('%.2f' % r if r < inf - eps else -1)