#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int max_q[] = { 20, 1000, 10000, 100000 };
int max_n[] = { 10, 100, 1000, 10000 };

int main() {
    srand(23041997);
    for (int i = 0; i < 4; ++i) {
        for (int test = i * 10; test < (i + 1) * 10; ++test) {
            char input[100];
            sprintf(input, "game.%d.in", test);
            FILE* inp = fopen(input, "w");
            int m = (rand() % max_n[i]) + 1;
            int n = (rand() % max_n[i]) + 1;
            int q = (rand() % max_q[i]) + 1;
            if (i == 4) q = 1000000;
            fprintf(inp, "%d %d\n", n, m);
            fprintf(inp, "%d\n", q);
            for (int j = 0; j < q; ++j) {
                int x1 = rand() % (n + 1);
                int x2 = rand() % (n + 1);
                if (x1 > x2) swap(x1, x2);
                int y = rand() % (m + 1);
                fprintf(inp, "%d %d %d\n", x1, x2, y);
            }
            fclose(inp);

            char output[100];
            sprintf(output, "game.%d.out", test);
            cout << input << " " << output << endl;
            char command[200];
            sprintf(command, "../a.out < %s > %s", input, output);
            system(command);
        }
    }
}
