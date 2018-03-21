#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5 + 10;

int m, n, q, t[4 * maxN], g[4 * maxN];

void lazy_update(int k, int l, int r) {
    if (l == r) return;
    g[k * 2] = min(g[k * 2], g[k]);
    g[k * 2 + 1] = min(g[k * 2 + 1], g[k]);
    g[k] = m;
    t[k] = max(
        min(t[k * 2], g[k * 2]),
        min(t[k * 2 + 1], g[k * 2 + 1]));
}

void update(int k, int l, int r, int i, int j, int v) {
    if (j < l || r < i) return;
    lazy_update(k, l, r);
    if (i <= l && r <= j) {
        g[k] = v;
        return;
    }
    int mid = (l + r) >> 1;
    update(k * 2, l, mid, i, j, v);
    update(k * 2 + 1, mid + 1, r, i, j, v);
    t[k] = max(
        min(t[k * 2], g[k * 2]),
        min(t[k * 2 + 1], g[k * 2 + 1]));
}

void build(int k, int l, int r) {
    t[k] = g[k] = m;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(k * 2, l, mid);
    build(k * 2 + 1, mid + 1, r);
}

int main() {
    cin >> n >> m >> q;
    build(1, 1, n + 1);
    for (int i = 0; i < q; ++i) {
        int l, r, v;
        scanf("%d %d %d", &l, &r, &v);
        update(1, 1, n + 1, l + 1, r + 1, v);
        cout << min(t[1], g[1]) << endl;
    }
}
