#include <iostream>

using namespace std;

const int maxN = 1e5, modP = 1e9 + 7;

int a[maxN], m, n;

int power(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    int c = power(x, p / 2);
    c = (1ll * c * c) % modP;
    if (p % 2) c = (1ll * c * x) % modP;
    return c;
}

int get_max(int c, int& p) {
    int v = 0;
    for (int r = 1; r <= m; ++r) {
        int t = power(a[c], r);
        if (v < t)
            v = t, p = r;
    }
    return v;
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    
    int l = 1, r = n;
    int t = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int pos, posl, posr;
        int v = get_max(mid, pos);
        int vl = get_max(mid - 1, posl);
        int vr = get_max(mid + 1, posr);
        if (v >= vl && v >= vr) {
            cout << pos << " " << mid;
            return 0;
        }
        if (v < vl)
            r = mid - 1;
        else
            l = mid + 1;
    }
}
