#include <iostream>
#include <vector>
#define LL long long
#define MOD 1000000007

using namespace std;

struct Matrix {
	int n, m;
	LL a[51][51];

	Matrix (int n, int m, LL init) {
		this->n = n;
		this->m = m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				a[i][j] = init;
			}
		}
	}
	Matrix (int n) {
		this->n = this->m = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				a[i][j] = (i == j);
			}
		}
	}

	Matrix operator* (const Matrix &b) const {
		Matrix ans(n, b.m, 0);
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < m; k++) {
				for (int j = 0; j < b.m; j++) {
					ans.a[i][j] = (ans.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
				}
			}
		}
		return ans;
	}
};

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector<pair<int,vector<int> > > forbid;
	Matrix trans(m+1, m+1, 1);
	for (int i = 0; i < m+1; i++) trans.a[0][i] = 0;
	while (k--) {
		char t; cin >> t;
		if (t == 'A') {
			int x, y; cin >> x >> y;
			trans.a[x][y] = trans.a[y][x] = 0;
		} else if (t == 'B') {
			int i, p; cin >> i >> p;
			vector<int> c(p);
			for (int j = 0; j < p; j++) cin >> c[j];
			forbid.push_back({i, c});
		}
	}
	sort(forbid.begin(), forbid.end());
	vector<Matrix> base{trans};
	for (int i = 1; i < 32; i++) {
		base.push_back(base.back() * base.back());
	}
	Matrix ans(m+1, 1, 0); ans.a[0][0] = 1;
	for (int i = 0; i <= forbid.size(); i++) {
		int start = i == 0 ? 0 : forbid[i-1].first;
		int end = i == forbid.size() ? n : forbid[i].first;
		int b = end - start;
		for (int j = 0; b; j++, b>>=1) {
			if (b & 1) ans = base[j] * ans;
		}
		if (i == forbid.size()) continue;
		for (int c : forbid[i].second) {
			ans.a[c][0] = 0;
		}
	}
	LL out = 0;
	for (int i = 1; i <= m; i++) out += ans.a[i][0];
	out %= MOD;
	cout << out << endl;

	return 0;
}

