n = int(input())
v = [input().rstrip().split(',') for i in range(n)]
m = len(v[0])
k = [max(len(v[i][j]) for i in range(n)) for j in range(m)]
h = '+' + (''.join(('-'*x + '+') for x in k))

print(h)
for i in range(n):
    print('|', end = '')
    for j in range(m):
        s = v[i][j]
        t = ' '*(k[j] - len(s))
        print(t + s if s.isdigit() else s + t, end = '')
        print('|', end = '')
    print()
    print(h)

