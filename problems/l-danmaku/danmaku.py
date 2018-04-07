from math import sqrt

h, w = [float(s) for s in input().split()]
n = int(input())
r = [[float(s) for s in input().split()] for i in range(n)]
v = [[] for i in range(n + 2)]

for i in range(n):
    for j in range(i):
        dx = r[i][0] - r[j][0]
        dy = r[i][1] - r[j][1]
        if sqrt(dx*dx + dy*dy) < r[i][2] + r[j][2]:
            v[i].append(j)
            v[j].append(i)

for i in range(n):
    if abs(r[i][0]) < r[i][2]:
        v[n].append(i)
    if abs(r[i][0] - w) < r[i][2]:
        v[i].append(n+1)

b = [False for i in range(n + 2)]
b[n] = True
s = [n]

while len(s) > 0:
    i = s.pop()
    if i == n + 1:
        print('NO NO NO')
        exit(0)
    for j in v[i]:
        if not b[j]:
            b[j] = True
            s.append(j)

print('YES YES YES')
