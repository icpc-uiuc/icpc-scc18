#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Circle {
	double x, y, r;
};

int parent[2002];

double H, W;
int N;
vector<Circle> c;

bool intersect (int p, int q) {
	if (p == 0 && q == N+1) return false;
	if (p == 0) return c[q].x < c[q].r;
	if (q == N+1) return c[p].x + c[p].r > W;
	return pow(c[p].r + c[q].r, 2) > pow(c[p].x - c[q].x, 2) + pow(c[p].y - c[q].y, 2);
}

int finde (int u) {
	return parent[u] < 0 ? u : (parent[u] = finde(parent[u]));
}

void unione (int u, int v) {
	int uu = finde(u), vv = finde(v);
	if (parent[uu] < parent[vv]) {
		parent[uu] += parent[vv];
		parent[vv] = uu;
	} else {
		parent[vv] += parent[uu];
		parent[uu] = vv;
	}
}

int main () {
	cin >> H >> W >> N;
	Circle cc;
	c.push_back(cc);  // dummy circle
	for (int i = 0; i < N; i++) {
		Circle cc; cin >> cc.x >> cc.y >> cc.r;
		c.push_back(cc);
	}
	c.push_back(cc);  // dummy circle
	for (int i = 0; i <= N+1; i++) parent[i] = -1;
	for (int i = 0; i <= N+1; i++) {
		for (int j = i+1; j <= N+1; j++) {
			if (finde(i) != finde(j) && intersect(i, j)) {
				unione(i, j);
			}
		}
	}
	if (finde(0) == finde(N+1)) cout << "NO NO NO" << endl;
	else cout << "YES YES YES" << endl;

	return 0;
}

