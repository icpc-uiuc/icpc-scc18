#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

int main()
{
    srand(19910724);
    puts("100\n");
    for (int i = 0; i < 100; ++ i) {
        printf("%.2f %.2f %.2f\n", rand() % 20001 / 100.0 - 100, rand() % 20001 / 100.0 - 100, rand() % 36001 / 100.0);
    }
    return 0;
}