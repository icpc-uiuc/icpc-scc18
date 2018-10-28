#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

const int MOD = 1000000007;

void add(int &a, int b)
{
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

const int MAXM = 1000;

int f[MAXM * 2 + 2][MAXM * 2 + 2];

int main()
{
    int n;
    assert(scanf("%d", &n) == 1);
    assert(1 <= n && n <= 100000);

    memset(f, 0, sizeof(f));
    #define f(x, y) f[x + MAXM][y + MAXM]

    vector<pair<int, int>> destinations;
    for (int i = 0; i < n; ++ i) {
        int Ai, Bi, Ci, Di;
        assert(scanf("%d%d%d%d", &Ai, &Bi, &Ci, &Di) == 4);
        assert(1 <= Ai && Ai <= MAXM);
        assert(1 <= Bi && Bi <= MAXM);
        assert(1 <= Ci && Ci <= MAXM);
        assert(1 <= Di && Di <= MAXM);
        // (-Ai, -Ci) --> (Bj, Dj)
        // {Ai + Bj + Ci + Dj} \choose {Ai + Bj}
        f(-Ai, -Ci) += 1;
        destinations.push_back({Bi, Di});
    }
    for (int x = -MAXM; x <= MAXM; ++ x) {
        for (int y = -MAXM; y <= MAXM; ++ y) {
            add(f(x + 1, y), f(x, y));
            add(f(x, y + 1), f(x, y));
        }
    }
    int answer = 0;
    for (const pair<int, int>& dest : destinations) {
        add(answer, f(dest.first, dest.second));
    }
    printf("%d\n", answer);

    return 0;
}
