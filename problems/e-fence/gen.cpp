#include <fstream>
#include <set>

using namespace std;

int main () {
	for (int c = 5; c < 10; c++) {
		ofstream fout("testcases/fence." + to_string(c) + ".in");
		srand(c * c * c);
		set<pair<int,int> > s;
		fout << "100 100\n";
		while (s.size() < 100) {
			int x = rand() % 2000000 - 1000000;
			int y = rand() % 2000000 - 1000000;
			if (s.find({x,y}) == s.end()) fout << x << ' ' << y << endl;
			s.insert({x,y});
		}
		while (s.size() < 200) {
			int x = rand() % 1200000 - 600000;
			int y = rand() % 1200000 - 600000;
			if (s.find({x,y}) == s.end()) fout << x << ' ' << y << endl;
			s.insert({x,y});
		}
	}

	return 0;
}

