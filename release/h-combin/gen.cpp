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
        fprintf(out, "%d\n", n);
        for (int i = 0; i < n; ++ i) {
            fprintf(out, "%d %d %d %d\n", rand() % 1000 + 1, rand() % 1000 + 1, rand() % 1000 + 1, rand() % 1000 + 1);
        }
        fclose(out);

        char ansfilename[100];
        sprintf(ansfilename, "test/%d.ans", testcase);
        char command[200];
        sprintf(command, "./combin < %s > %s", filename, ansfilename);
        system(command);
    }
    return 0;
}
