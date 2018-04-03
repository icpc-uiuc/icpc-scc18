import numpy as np
import matplotlib.pyplot as pt

def read():
    return [int(s) for s in input().split()]

n, m = read()
A = [read() for i in range(n)]
B = [read() for i in range(m)]

pt.plot([p[0] for p in A], [p[1] for p in A], 'or')
pt.plot([p[0] for p in B], [p[1] for p in B], 'ob')

pt.show()
