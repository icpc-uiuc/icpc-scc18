#include <iostream>
#include <iomanip>

using namespace std;

int dp[20001];

int main () {
	int n; cin >> n;
	int w[201], p[201];
	for (int i = 1; i <= n; i++) cin >> w[i] >> p[i];
	int k; cin >> k;
	int l[200]; double m[200];
	for (int i = 0; i < k; i++) cin >> l[i] >> m[i];
	for (int j = 0; j <= 20000; j++) dp[j] = 0;
	for (int i = 1; i <= n; i++) {
		int dp2[20001];
		dp2[0] = 0;
		for (int j = 1; j <= 20000; j++) {
			if (j >= w[i]) dp2[j] = max(dp[j], dp[j-w[i]] + p[i]);
			else dp2[j] = dp[j];
		}
		for (int j = 0; j <= 20000; j++) dp[j] = dp2[j];
	}
	double ans = 0;
	for (int i = 1; i < k; i++) {
		ans = max(ans, m[i-1] * dp[l[i]-1]);
	}
	cout << setiosflags(ios::fixed) << setprecision(3) << ans << endl;

	return 0;
}

