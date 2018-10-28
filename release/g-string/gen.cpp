#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <string>
using namespace std;

int main()
{
    srand(19910724);

    for (int testcase = 0; testcase < 10; ++ testcase) {
        char filename[100];
        sprintf(filename, "test/%d.in", testcase);
        FILE* out = fopen(filename, "w");
        int n = testcase < 5 ? 1000 : 100000;
        int vocab = testcase < 6 ? rand() % 26 + 1 : 10 - testcase;
        string s = "";
        for (int i = 0; i < n; ++ i) {
            char x = rand() % vocab + 'a';
            s += x;
        }
        fprintf(out, "%s\n", s.c_str());
        int m = 10000;
        fprintf(out, "%d\n", m);
        for (int i = 0; i < m; ++ i) {
            int length = rand() % 50 + 51;
            int start = rand() % (s.size() - length + 1);
            for (int j = 0; j < length; ++ j) {
                fprintf(out, "%c", s[start + j]);
            }
            fprintf(out, "\n");
        }
        fclose(out);

        char ansfilename[100];
        sprintf(ansfilename, "test/%d.ans", testcase);
        char command[200];
        sprintf(command, "./string < %s > %s", filename, ansfilename);
        system(command);
    }
    return 0;
}
