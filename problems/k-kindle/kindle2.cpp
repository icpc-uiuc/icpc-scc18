#include <iostream>
#define INF 0x3f3f3f3f

using namespace std;

int ham (int z) {
	int ans = 0;
	while (z) { ans += z & 1; z >>= 1; }
	return ans;
}
/*
pair<int,int> bfs (int n, int b[][21], int s) {
	int dist[21];
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[s] = 0;
	bool vis[21];
	for (int i = 1; i <= n; i++) vis[i] = false;
	while (1) {
		int u = -1, mind = INF;
		for (int i = 1; i <= n; i++) {
			if (!vis[i] && dist[i] < mind) { u = i; mind = dist[i]; }
		}
		if (u == -1) break;
		vis[u] = true;
		for (int i = 1; i <= n; i++) if (b[u][i] != INF) dist[i] = min(dist[i], dist[u] + b[u][i]);
	}
//	for (int i = 1; i <= n; i++) cout << dist[i] << ' '; cout << endl;
	int u = -1, maxd = -1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > maxd) { u = i; maxd = dist[i]; }
	}
	return {u, maxd};
}
*/
int main () {
	int n, m; cin >> n >> m;
	int a[21][21];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = i == j ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w; cin >> u >> v >> w;
		a[u][v] = min(a[u][v], w);
		a[v][u] = min(a[v][u], w);
	}
	int k, l; cin >> k >> l;
	int f[10];
	for (int i = 0; i < k; i++) cin >> f[i];

	int ans = INF;
	for (int z = 0; z < (1 << k); z++) {
		if (ham(z) != l) continue;
		int b[21][21];
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				b[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < k; i++) {
			for (int j = 0; j < k; j++) {
				if ((z & (1 << i)) && (z & (1 << j))) {
					b[f[i]][f[j]] = 0;
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = 1; k <= n; k++) {
					b[j][k] = min(b[j][k], b[j][i] + b[i][k]);
				}
			}
		}
		int maxd = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				maxd = max(maxd, b[i][j]);
			}
		}
		ans = min(ans, maxd);
	}
	cout << ans << endl;

	return 0;
}

