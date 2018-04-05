#include <iostream>
#include <cstdio>
#include <regex>

using namespace std;

const int maxN = 1000000 + 10, modP = 1000000000 + 7;

string input, answer, feed_back_file, s;
int m, n, x, y, a[maxN];

void parse(int argc, char* argv[]) {
    input = string(argv[1]);
    answer = string(argv[2]);
    feed_back_file = string(argv[3]) + "/judgemessage.txt";
}

int power(int x, int k) {
    if (k == 0) return 1;
    if (k == 1) return x % modP;
    int c = power(x, k / 2);
    c = (1ll * c * c) % modP;
    if (k % 2) c = (1ll * c * x) % modP;
    return c;
}

int get_height(int x, int y) {
    return power(a[y], x);
}

int main(int argc, char* argv[]) {
    parse(argc, argv);
printf("123\n");
    // Read input
    FILE* finp = fopen(input.c_str(), "r");
    fscanf(finp, "%d%d", &m, &n);
    for (int i = 1; i <= n; ++i)
        fscanf(finp, "%d", &a[i]);

    // Read user's output
    getline(cin, s);

    // Judging
    FILE* fverdict = fopen(feed_back_file.c_str(), "w");
    bool correct = true;
    
    // Check output's format
    regex pattern("([0-9]+)( +)([0-9]+)( *)");
    if (!regex_match(s, pattern))
        correct = false;

    sscanf(s.c_str(), "%d%d", &x, &y);
    // Check valid coordinate
    if (x < 1 || y < 1 || x > m || y > n)
        correct = false;

    // Check correct peak
    int h = get_height(x, y);
    if ((x > 1 && get_height(x - 1, y) > h) ||
        (y > 1 && get_height(x, y - 1) > h) ||
        (x < m && get_height(x + 1, y) > h) ||
        (x < n && get_height(x, y + 1) > h))
        correct = false;

    if (correct) {
        fprintf(fverdict, "Correct\n");
        return 42;
    }
    else {
        fprintf(fverdict, "Wrong answer\n");
        return 43;
    }
}
