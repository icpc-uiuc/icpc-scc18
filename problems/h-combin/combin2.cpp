#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxN = 1000, modP = 1e9 + 7;

int n, f[2 * maxN + 10][2 * maxN + 10], res;
vector < pair < int, int > > arr;

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++f[maxN - a][maxN - c];
        arr.push_back({b + maxN, d + maxN});
    }
    for (int i = 0; i <= 2 * maxN; ++i)
        for (int j = 0; j <= 2 * maxN; ++j) {
            f[i + 1][j] = (f[i + 1][j] + f[i][j]) % modP;
            f[i][j + 1] = (f[i][j + 1] + f[i][j]) % modP;
        }
    for (auto p : arr)
        res = (res + f[p.first][p.second]) % modP;
    cout << res << endl;
}
