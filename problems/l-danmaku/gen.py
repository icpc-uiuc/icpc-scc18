import numpy as np
import os
import matplotlib.pyplot as plt

os.makedirs("test", exist_ok=True)

# first few tests are manual
start_index = 2
num_tests = 30

k = start_index

while k < num_tests:
    print("START GEN TEST CASE " + str(k))
    N = 2000
     
    W = 1000000
    H = 1000000
    R = 23000

    points = np.random.random((N, 3))
    points[:, 0] *= W
    points[:, 1] *= (H - R * 2)
    points[:, 1] += R
    points[:, 2] *= R

    good = True

    eps = 1e-3

    for i in range(N):
        # do not allow touching upper/lower boundaries
        if points[i, 1] - points[i, 2] <= 0:
            good = False
        if points[i, 1] + points[i, 2] >= H:
            good = False

        if not good:
            break

        # avoid almost tangent to boundaries. 
        if abs(points[i, 0] - points[i, 2]) < eps:
            good = False
        if abs(points[i, 0] + points[i, 2] - H) < eps:
            good = False
        if abs(points[i, 1] - points[i, 2]) < eps:
            good = False
        if abs(points[i, 1] + points[i, 2] - H) < eps:
            good = False

        # avoid two circles almost tangent
        for j in range(i + 1, N):
            dist = ((points[i, 0] - points[j, 0]) ** 2 + 
                (points[i, 1] - points[j, 1]) ** 2) ** 0.5
            if abs(dist - (points[i, 2] + points[j, 2])) < eps:
                good = False

        if not good:
            break

    if not good:
        continue

    #fig, ax = plt.subplots()
    #ax.set_xlim((0, W))
    #ax.set_ylim((0, H))
    #for i in range(N):
    #    c = plt.Circle((points[i, 0], points[i, 1]), points[i, 2], color='r')
    #    ax.add_artist(c)
    #plt.show()

    with open("test/" + str(k) + ".in", "w") as f:
        f.write(str(H) + " " + str(W) + "\n")
        f.write(str(N) + "\n")

        for i in range(N):
            f.write(str(points[i, 0]) + " " + str(points[i, 1]) + " " +
                str(points[i, 2]) + "\n")
    k += 1
