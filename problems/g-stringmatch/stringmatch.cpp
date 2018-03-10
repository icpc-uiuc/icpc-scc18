#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>

struct Node
{
    int child[26];
    bool isWord;

    Node() {
        memset(child, -1, sizeof(child));
        isWord = false;
    }
};

char s[100000 + 1];
Node trie[10000 * 100 + 1];
int cnt;

int main()
{
    assert(scanf("%s", s) == 1);
    int n = strlen(s);
    assert(1 <= n && n <= 100000);
    for (int i = 0; i < n; ++ i) {
        assert('a' <= s[i] && s[i] <= 'z');
    }
    int m;
    assert(scanf("%d", &m) == 1);
    assert(1 <= m && m <= 10000);
    cnt = 0;
    for (int i = 0; i < m; ++ i) {
        char t[101];
        assert(scanf("%s", t) == 1);
        int length = strlen(t);
        assert(1 <= length && length <= 100);
        int u = 0;
        for (int j = 0; j < length; ++ j) {
            char c = t[j];
            assert('a' <= c && c <= 'z');
            c -= 'a';
            if (trie[u].child[c] == -1) {
                trie[u].child[c] = cnt ++;
            }
            u = trie[u].child[c];
        }
        trie[u].isWord = true;
    }

    int answer = 0;
    for (int i = 0; i < n; ++ i) {
        int u = 0, lastJ = -1;
        for (int j = i; j < n; ++ j) {
            u = trie[u].child[s[j] - 'a'];
            if (u == -1) {
                break;
            }
            if (trie[u].isWord) {
                lastJ = j;
            }
        }
        if (lastJ != -1) {
            answer += lastJ - i + 1;
            i = lastJ;
        }
    }
    printf("%d\n", answer);

    return 0;
}
