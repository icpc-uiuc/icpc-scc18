#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<pair<int, int>> guns(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &guns[i].first, &guns[i].second);

    int K;
    scanf("%d", &K);
    vector<pair<int, double>> load(K);
    for (int i = 0; i < K; i++)
        scanf("%d %lf", &load[i].first, &load[i].second);

    vector<int> dp(5050);

    for (int i = 0; i < N; i++)
        for (int j = 5000; j >= guns[i].first; j--)
            dp[j] = max(dp[j], dp[j - guns[i].first] + guns[i].second);

    double eff = 0;

    int curr_load = 0;
    for (int i = 0; i <= 5000; i++) {
        if (load[curr_load + 1].first <= i) {
            curr_load++;
            if (curr_load == K - 1)
                break;
        }
        eff = max(eff, dp[i] * load[curr_load].second);
    }

    printf("%.3f\n", eff);
}
