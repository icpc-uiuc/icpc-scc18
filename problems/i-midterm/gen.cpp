#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int max_q[] = { 10, 1000, 10000, 100000, 1000000 };
int max_n[] = { 20, 5000, 90000, 900000, 1000000 };
set < int > mset;

int main() {
    srand(23041997);
    for (int i = 0; i < 5; ++i) {
        for (int test = i * 10; test < (i + 1) * 10; ++test) {
            char input[100];
            sprintf(input, "test/%d.in", test);
            FILE* inp = fopen(input, "w");
            int q = (rand() % max_q[i]) + 1;
            if (test == 49) q = 1e6;
            mset.clear();
            mset.insert(0);

            fprintf(inp, "%d\n", q);
            for (int j = 0; j < 1; ++j) {
                int n = (test == 49) ? j + 1 : ((rand() % max_n[i]) + 1);
                while (mset.find(n) != mset.end())
                    n = (rand() % max_n[i]) + 1;
                fprintf(inp, "%d\n", n);
                mset.insert(n);
            }
            fclose(inp);

            char output[100];
            sprintf(output, "test/%d.ans", test);
            cout << input << " " << output << endl;
            char command[200];
            sprintf(command, "./midterm < %s > %s", input, output);
            system(command);
        }
    }
}
