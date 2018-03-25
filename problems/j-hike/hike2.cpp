#include <iostream>

#define MOD 1000000007;

using namespace std;

int main() {
    long long m, n;
    scanf("%lld %lld", &m, &n);
    long long h[n];
    for (int i = 0; i < n; i++)
        scanf("%lld", &h[i]);

    long long left_bound = 0, right_bound = n - 1;

    long long peak_r = -1, peak_c = -1;

    while (left_bound <= right_bound && peak_r == -1) {
        long long mid = (left_bound + right_bound) >> 1;
        long long next = -1, prev = -1, curr = -1, left = 1, right = 1;
        long long high = 0, high_index = -1;
        bool go_left = true;

        for (long long i = 0; i < m; i++) {
            prev = curr;
            curr = next;
            if (curr == -1) {
                curr = h[mid];
            }

            next = curr * h[mid] % MOD;
            bool peak = true;

            if (mid > 0) {
                left = left * h[mid - 1] % MOD; 
                if (left > curr)
                    peak = false;
            }

            if (mid < n - 1) {
                right = right * h[mid + 1] % MOD;
                if (right > curr)
                    peak = false;
            }

            if (i > 0 && prev > curr)
                peak = false;

            if (i < m - 1 && next > curr)
                peak = false;

            if (peak) {
                peak_r = i + 1;
                peak_c = mid + 1;
                break;
            }

            if (curr > high) {
                high = curr;
                if (mid > 0 && left > curr)
                    go_left = true;
                else
                    go_left =false;
            }
            
        }

        if (go_left)
            right_bound = mid - 1;
        else
            left_bound = mid + 1;
    }

    printf("%lld %lld\n", peak_r, peak_c);
}
