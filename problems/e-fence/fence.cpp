#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#define EPS 1e-8
#define INF 100000000

using namespace std;

struct Graph {
	int n;
	double a[100][100];
	double d[100][100];
//	int m[100][100];

	double shortest_cycle () {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				d[i][j] = a[i][j] ? a[i][j] : INF;
//				m[i][j] = -1;
			}
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (d[i][j] > d[i][k] + d[k][j]) {
						d[i][j] = d[i][k] + d[k][j];
//						m[i][j] = k;
					}
				}
			}
		}
		double ans = INF;
		for (int i = 0; i < n; i++) {
			ans = min(ans, d[i][i]);
		}
		return ans;
	}
};

struct Point {
	double x, y;

	Point operator- (const Point &p) const {
		Point ans;
		ans.x = p.x - x;
		ans.y = p.y - y;
		return ans;
	}

	// cross product
	double operator* (const Point &p) const {
		return x * p.y - y * p.x;
	}
};
double norm (Point p, Point q) {
	return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int n, m;
Point p[100], c[100];
Graph g;

int main () {
	cin >> n >> m;
	g.n = n;
	for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	for (int i = 0; i < m; i++) cin >> c[i].x >> c[i].y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) g.a[i][j] = 0;
			int flag = 1;
			for (int k = 0; k < m; k++) {
				if ((p[j] - p[i]) * (c[k] - p[i]) <= EPS) flag = 0;
			}
			if (flag) g.a[i][j] = norm(p[i], p[j]);
			else g.a[i][j] = 0;
		}
	}
	double ans = g.shortest_cycle();
	if (ans == INF) cout << -1 << endl;
	else cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;

	return 0;
}

