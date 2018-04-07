import re

s = input()
n = int(input())
v = [input().strip() for i in range(n)]

def make_trie(v):
    f = {}
    t = set()
    n = 0

    def new():
        nonlocal n
        n += 1
        return n

    def add(s):
        i = 0
        for c in s:
            p = (i, c)
            if p in f:
                i = f[p]
            else:
                i = new()
                f[p] = i
        t.add(n)

    for s in v:
        add(s)
    
    def match(s, off):
        r, i, k = 0, 0, 0
        for j in range(len(s) - off):
            p = (i, s[off + j])
            if p in f:
                k += 1
                i = f[p]
                if i in t:
                    r = k
            else:
                break
        return r

    return match

f = make_trie(v)
i, n, r = 0, len(s), 0
while i < n:
    m = f(s, i)
    if m != 0:
        i += m
        r += m
    else:
        i += 1
print(r)
