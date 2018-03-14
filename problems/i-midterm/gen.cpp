#include <iostream>

using namespace std;

int max_q[] = { 10, 1000, 10000, 100000 };
int max_n[] = { 20, 2000, 20000, 200000 };

int main() {
    setrand(time(NULL));
    for (int i = 0; i < 4; ++i) {
        for (int test = i * 10 + 1; test <= (i + 1) * 10; ++test) {
            q = rand() % max_q[i];
            n = rand() % max_n[i];
        }
    }
}
