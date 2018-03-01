#include <iostream>

using namespace std;

int main () {
	int T = 100;
	cout << T << endl;
	while (T--) {
		cout << (rand() % 10000) * 100 << endl;
	}
	return 0;
}

