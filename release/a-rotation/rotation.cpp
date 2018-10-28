#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>

const double PI = acos(-1.0);

int main()
{
    int tests;
    for (assert(scanf("%d", &tests) == 1 && 1 <= tests && tests <= 100); tests --; ) {
        double x, y, a;
        assert(scanf("%lf%lf%lf", &x, &y, &a) == 3);
        assert(abs(x) <= 100);
        assert(abs(y) <= 100);
        assert(0 <= a && a <= 360);
        a = a / 180 * PI;
        double tx = x * cos(a) - y * sin(a);
        double ty = x * sin(a) + y * cos(a);
        printf("%.2f %.2f\n", tx, ty);
    }
    return 0;
}