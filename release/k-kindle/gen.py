import numpy as np
import os

def dfs(u, visited, adjmat):
    visited[u] = 1
    for v in range(len(visited)):
        if adjmat[u][v] == 1 and not visited[v]:
            dfs(v, visited, adjmat)

os.makedirs("test", exist_ok=True)

# first few tests are manual
start_index = 2
num_tests = 20

i = start_index
while i < num_tests:
    N = 20
    M = np.random.randint(19, 501)

    roads = []

    adjmat = np.zeros((N, N), dtype=np.int)

    for j in range(M):
        u = np.random.randint(N) + 1
        v = np.random.randint(N) + 1
        roads.append([u, v, np.random.randint(1000000) + 1])
        adjmat[u - 1, v - 1] = 1
        adjmat[v - 1, u - 1] = 1

    visited = np.zeros(N, dtype=np.int)

    dfs(0, visited, adjmat)

    # not connected, pass this one
    if np.sum(visited) != N:
        continue

    K = 10
    L = np.random.randint(0, K + 1)

    bonfires = []
    for j in range(K):
        while True:
            u = np.random.randint(N) + 1
            if not(u in bonfires):
                bonfires.append(u)
                break

    with open("test/" + str(i) + ".in", "w") as f:
        f.write(str(N) + " " + str(M) + "\n")
        for u, v, w in roads:
            f.write(str(u) + " " + str(v) + " " + str(w) + "\n")
        f.write(str(K) + " " + str(L) + "\n")

        if K != 0:
            f.write(str(bonfires[0]))
            for j in range(1, K):
                f.write(" " + str(bonfires[j]))
            f.write("\n")
    i += 1
