#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const double PI = acos(-1);

double theta, x, y;
int test;

int main() {
    cin >> test;
    while (test--) {
        cin >> x >> y >> theta;
        double cos_theta = cos(theta * PI / 180.0);
        double sin_theta = sin(theta * PI / 180.0);
        printf("%.2f %.2f\n", x * cos_theta - y * sin_theta, x * sin_theta + y * cos_theta);
    }
}
