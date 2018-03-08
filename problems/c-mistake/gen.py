import numpy as np
import os

os.makedirs("test", exist_ok=True)

# first few tests are manual
start_index = 2
num_tests = 50

for i in range(start_index, num_tests):
    N = np.random.randint(200, 201)

    guns = []
    for j in range(N):
        w = np.random.randint(50, 101)
        p = np.random.randint(1, 101)
        guns.append([w, p])

    K = np.random.randint(200, 201)
    load = [[0, np.random.rand() * 10]]

    curr_load = 0
    for j in range(K - 1):
        l = np.random.randint(50, 101)
        curr_load += l
        load.append([curr_load, np.random.rand() * 10])
    load[K - 1][1] = 0

    with open("test/" + str(i) + ".in", "w") as f:
        f.write(str(N) + "\n")
        for i in range(N):
            f.write(str(guns[i][0]) + " " + str(guns[i][1]) + "\n")
        f.write(str(K) + "\n")
        for i in range(K):
            f.write(str(load[i][0]) + " " + str(load[i][1]) + "\n")

