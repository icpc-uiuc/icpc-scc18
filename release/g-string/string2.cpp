#include <iostream>

using namespace std;

string s, k;
int res, n;

struct Node {
    Node() {
        for (int i = 0; i < 26; ++i)
            nxt[i] = NULL;
        end_word = false;
    }

    Node* nxt[26];
    bool end_word;
};

Node* root;

void add(string& k) {
    Node* curr = root;
    for (int i = 0; i < k.length(); ++i) {
        if (curr->nxt[k[i] - 'a'] == NULL)
            curr->nxt[k[i] - 'a'] = new Node();
        curr = curr->nxt[k[i] - 'a'];
    }
    curr->end_word = true;
}

int match(int i) {
    Node* curr = root;
    int j = -1;
    while (i < s.length()) {
        if (curr->nxt[s[i] - 'a'] == NULL) 
            break;
        curr = curr->nxt[s[i] - 'a'];
        if (curr->end_word) 
            j = i;
        ++i;
    }
    return j;
}

int main() {
    root = new Node();
    cin >> s;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> k;
        add(k);
    }
    
    Node* curr = root;
    int cnt = 0;
    int i = 0;
    while (i < s.length()) {
        int j = match(i);
        if (j == -1) ++i;
        else {
            res += (j - i + 1);
            i = j + 1;
        }
    }
    cout << res << endl;
}
