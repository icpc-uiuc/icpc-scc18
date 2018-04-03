#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e6 + 10;

int f[maxN], p[maxN], q, n;
vector < int > factor;

void sieve() {
    for (int i = 2; i <= 1e6; ++i)
        if (p[i] == 0)
            for (int s = 2 * i; s <= 1e6; s += i)
                p[s] = i;
}

void factorize(int x) {
    factor.clear();
    while (p[x]) {
        factor.push_back(p[x]);
        x /= p[x];
    }
    if (x > 1) factor.push_back(x);
}

int main() {
    sieve();

    // Compute sum of factors for all n
    f[1] = 0;
    for (int i = 2; i <= 1e6; ++i) {
        f[i] = 1;
        factorize(i);
        int sum = 1;
        int prod = 1;
        for (int j = 0; j < factor.size(); ++j) {
            if (j == 0 || factor[j] != factor[j - 1]) {
                f[i] = f[i] * sum;
                sum = 1;
                prod = 1;
            }
            prod *= factor[j];
            sum += prod;
        }
        f[i] *= sum;
        f[i] -= i;
    }

    cin >> q >> n;
	long long ans = 0;
    for (int i = 0; i < q; ++i) {
        ans += f[n];
		n = ((long long)n * n) % 999983 + 1;
    }
	cout << ans << endl;
}
