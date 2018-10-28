#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct disjoint_sets {
    void add_elements(int num) {
        while (num--)
            s.push_back(-1);
    }

    int find(int elem) {
        return s[elem] < 0 ? elem : s[elem] = find(s[elem]);
    }

    void set_union(int a, int b) {
        int root1 = find(a), root2 = find(b);
        if (root1 == root2)
            return;
        int new_size = s[root1] + s[root2];
        if (s[root1] <= s[root2]) {
            s[root2] = root1;
            s[root1] = new_size;
        } else {
            s[root1] = root2;
            s[root2] = new_size;
        }
    }
    vector<int> s;
};

struct point {
    double x, y, r;
};

bool intersect(const point& a, const point &b) {
    return pow(a.x - b.x, 2) + pow(a.y - b.y, 2) < pow(a.r + b.r, 2);
}

int main() {
    double H, W;
    int N;
    scanf("%lf %lf %d", &H, &W, &N);
    vector<point> bullets(N);

    for (int i = 0; i < N; i++)
        scanf("%lf %lf %lf", &bullets[i].x, &bullets[i].y, &bullets[i].r);

    disjoint_sets dsets;

    // N is left boundary, N + 1 is right boundary.
    dsets.add_elements(N + 2);

    // Check bullets intersection
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++) {
            if (intersect(bullets[i], bullets[j])) {
                dsets.set_union(i, j);
            }
        }


    for (int i = 0; i < N; i++) {
        // Check left boundary
        if (bullets[i].x - bullets[i].r <= 0)
            dsets.set_union(i, N);
        // Check right boudnary
        if (bullets[i].x + bullets[i].r >= W)
            dsets.set_union(i, N + 1);
    }

    if (dsets.find(N) != dsets.find(N + 1))
        printf("YES YES YES\n");
    else
        printf("NO NO NO\n");
}
