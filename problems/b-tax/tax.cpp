#include <iostream>

using namespace std;

int main () {
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		int withheld = x * 0.5;
		int finale = 0;
		if (x > 10000) finale += (x - 10000) * (0.1 - 0.0);
		if (x > 20000) finale += (x - 20000) * (0.2 - 0.1);
		if (x > 40000) finale += (x - 40000) * (0.4 - 0.2);
		if (x > 80000) finale += (x - 80000) * (0.8 - 0.4);
		int balance = finale - withheld;
		if (balance < 0) cout << "Refund " << -balance << endl;
		else if (balance > 0) cout << "Owe " << balance << endl;
		else cout << "Clear" << endl;
	}
	return 0;
}

