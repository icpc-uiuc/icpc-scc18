#include <iostream>
#include <vector>

using namespace std;

#define MAXN 1000000

vector<long long> primes;

void sieve() {
    vector<bool> is_prime(MAXN + 1, true);

    for (int i = 2; i <= MAXN; i++) {
        if (is_prime[i])
            primes.push_back(i);
        for (long long j = i * 2; j <= MAXN; j += i) 
            is_prime[j] = false;
    }
}

int main() {
    sieve();
    int q;

    scanf("%d", &q);
    vector<long long> ans(MAXN + 1, -1);
    for (int i = 0; i < q; i++) {
        int a;
        scanf("%d", &a);

        if (ans[a] != -1) {
            printf("%lld\n", ans[a]);
            continue;
        }

        ans[a] = 1; 
        int tmp = a;
        for (int j = 0; j < primes.size(); j++) {
            if (tmp == 1)
                break;

            if (primes[j] * primes[j] > tmp) {
                ans[a] *= (1 + tmp);
                break;
            }

            long long sum = 1;
            while (tmp % primes[j] == 0) {
                tmp /= primes[j];
                sum = sum * primes[j] + 1;
            }

            ans[a] *= sum;
        }

        ans[a] -= a;
        printf("%lld\n", ans[a]);
    }
}
