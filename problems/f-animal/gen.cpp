#include <fstream>
#include <vector>

using namespace std;

int main () {
	for (int c = 10; c < 20; c++) {
		srand(c * c * c);
		ofstream fout("tests/" + to_string(c) + ".in");
		int n = 100000000, m = 50, k = 1000;
		int k1, k2;
		if (c % 4 == 0) { k = 10; k1 = 5; }
		else if (c % 4 == 1) k1 = 0;
		else if (c % 4 == 2) k1 = k / 2;
		else k1 = k;
		k2 = k - k1;
		fout << n << ' ' << m << ' ' << k << endl;
		for (int i = 0; i < k1; i++) {
			int x = rand() % m + 1, y = rand() % m + 1;
			fout << 'A' << ' ' << x << ' ' << y << endl;
		}
		vector<int> arr(m); for (int i = 0; i < m; i++) arr[i] = i+1;
		for (int i = 0; i < k2; i++) {
			int range = n / k2;
			int ii = i * range + rand() % range + 1;
			int p = rand() % 10 + 1;
			random_shuffle(arr.begin(), arr.end());
			fout << 'B' << ' ' << ii << ' ' << p << ' ';
			for (int j = 0; j < p; j++) fout << arr[j] << ' ';
			fout << endl;
		}
	}

	return 0;
}

