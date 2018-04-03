#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

struct segment_tree {
    vector<long long> st, lazy;
    const vector<long long> &A;
    size_t n;

    inline int left(int p) { return p << 1;}
    inline int right(int p) { return (p << 1) + 1; }

    void propagate(int p, int L, int R) {
        if (lazy[p] != INT_MAX) {
            if (L != R) {
                lazy[left(p)] = min(lazy[left(p)], lazy[p]);
                lazy[right(p)] = min(lazy[right(p)], lazy[p]);
            }
            st[p] = min(st[p], lazy[p]);
            lazy[p] = INT_MAX;
        }
    }
        
    void build(int p, int L, int R) {
        if (L == R)
            st[p] = A[L];
        else {
            build(left(p), L, (L + R) / 2);
            build(right(p), (L + R) / 2 + 1, R);
            st[p] = max(st[left(p)], st[right(p)]);
        }
    }

    long long update(int p, int L, int R, int i, int j, long long val) {
        propagate(p, L, R);
        if (L > j || R < i)
            return st[p];
        if (L >= i && R <= j) {
            lazy[p] = val;
            propagate(p, L, R);
            return st[p];
        }

        return st[p] = max(update(left(p), L, (L + R) / 2, i, j, val),
            update(right(p), (L + R) / 2 + 1, R, i, j, val));
    }

    long long query(int p, int L, int R, int i, int j) {
        if (L > j || R < i)
            return 0;
        propagate(p, L, R);
        if (L >= i && R <= j)
            return st[p];
        return max(query(left(p), L, (L + R) / 2, i, j),
            query(right(p), (L + R) / 2 + 1, R, i, j));
    }

    segment_tree(const vector<long long> &_A): A(_A) {
        n = A.size();
        st.assign(n * 4, 0);
        lazy.assign(n * 4, INT_MAX);
        build(1, 0, n - 1);
    }

    void update(int i, int j, long long val) {
        update(1, 0, n - 1, i, j, val);
    }

    long long query(int i, int j) {
        return query(1, 0, n - 1, i, j);
    }};

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    vector<long long> A(n + 1, m);
    segment_tree st(A);
    while (q--) {
        int x1, x2, y;
        scanf("%d %d %d", &x1, &x2, &y);
        st.update(x1, x2, y);
        printf("%lld\n", max(0LL, st.query(0, n)));
    }
}
