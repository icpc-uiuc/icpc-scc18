n = int(input())
w = [[int(s) for s in input().split()] for i in range(n)]
k = int(input())
r = []
for i in range(k):
    s = input().split()
    r.append([int(s[0]), float(s[1])])
m = r[-1][0]

f = [[0 for j in range(m)] for i in range(n)]

if w[0][0] < m:
    f[0][w[0][0]] = w[0][1]

for i in range(1, n):
    for j in range(m):
        f[i][j] = f[i-1][j]
        if j >= w[i][0]:
            f[i][j] = max(f[i][j], f[i-1][j-w[i][0]] + w[i][1])

x = 0.0
i = 0
for j in range(m):
    while r[i][0] <= j:
        i += 1
    x = max(x, r[i-1][1] * f[n-1][j])

print('%.3f' % x)
