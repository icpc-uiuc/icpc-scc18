n = int(input())

for i in range(n):
    total = int(input())
    held = total // 2
    owed = 0
    if total > 80000:
        owed += (total - 80000) * 4 // 5
        total = 80000
    if total > 40000:
        owed += (total - 40000) * 2 // 5
        total = 40000
    if total > 20000:
        owed += (total - 20000) // 5
        total = 20000
    if total > 10000:
        owed += (total - 10000) // 10
        total = 10000
    if owed == held:
        print('Clear')
    elif owed > held:
        print('Owe %d' % (owed - held))
    else:
        print('Refund %d' % (held - owed))
