#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int max_m[] = { 10, 1000, 10000, 100000, 1000000 };
int max_a[] = { 20, 5000, 1000000, 100000000, 1000000000 };
set < int > mset;

int main() {
    srand(23041997);
    for (int i = 0; i < 5; ++i) {
        for (int test = i * 10; test < (i + 1) * 10; ++test) {
            char input[100];
            sprintf(input, "%d.in", test);
            FILE* inp = fopen(input, "w");
            int m = (rand() % max_m[i]) + 1;
            int n = (rand() % max_m[i]) + 1;
            fprintf(inp, "%d %d\n", m, n);
            for (int j = 0; j < n; ++j) {
                int a = (rand() % max_a[i]) + 1;
                fprintf(inp, "%d ", a);
            }
            fclose(inp);
        }
    }
}
