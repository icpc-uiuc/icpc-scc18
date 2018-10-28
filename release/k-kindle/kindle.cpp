#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    vector<vector<long long>> adjmat(N, vector<long long>(N, INT_MAX));

    for (int i = 0; i < N; i++)
        adjmat[i][i] = 0;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--, v--;
        adjmat[u][v] = adjmat[v][u] = min(adjmat[u][v], (long long)w);
    }

    int K, L;
    scanf("%d %d", &K, &L);

    vector<int> bonfire(K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &bonfire[i]);
        bonfire[i]--;
    }

    vector<int> state(K);
    for (int i = 0; i < L; i++)
        state[i] = 1;

    long long diam = INT_MAX;

    auto adjmat_orig = adjmat;
    do {
        for (int i = 0; i < K; i++)
            for (int j = i + 1; j < K; j++)
                // Two cities are connected by bonfires.
                if (state[i] == 1 && state[j] == 1) {
                    adjmat[bonfire[i]][bonfire[j]] = 0;
                    adjmat[bonfire[j]][bonfire[i]] = 0;
                }

        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++) {
                    adjmat[i][j] = min(adjmat[i][j], 
                                       adjmat[i][k] + adjmat[k][j]);
                }

        long long curr_diam = 0;
        
        for (int i = 0; i < N; i++)
            for (int j = i + 1; j < N; j++)
                curr_diam = max(curr_diam, adjmat[i][j]);

        diam = min(diam, curr_diam);
        adjmat = adjmat_orig;

    } while (prev_permutation(state.begin(), state.end()));

    printf("%lld\n", diam);
}
