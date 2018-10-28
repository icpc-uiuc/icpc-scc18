from random import randint as rand

v = []

# boundary values
v.extend([[0], [1], [99], [100], [101], [199], 
          [200, 201], [400, 399, 401], 
          [799, 800, 801], [9999], [10000]])

# almost clear
v.append([14300, 14400])

# random tests
for i in range(4):
    v.append([rand(0, 10000) 
              for j in range(100 if i == 3 else rand(10, 100))])

# full coverage tests
for i in range(10):
    v.append([i*100 + j for j in range(100)])

for i in range(len(v)):
    with open('tests/%d.in' % i, 'w') as f:
        f.write('\n'.join(str(x) for x in ([len(v[i])] + [y*100 for y in v[i]])))
