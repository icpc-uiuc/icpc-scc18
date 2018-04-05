#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void printn(char ch, int n) {
    while (n--) 
        cout << ch;
}

void hrule(const vector<int> &col_width) {
    for (int w: col_width) {
        cout << "$";
        printn('-', w);
    }
    cout << "$\n";
}

int main() {
    string line;
    getline(cin, line);

    int n = stoi(line);

    vector<vector<string>> table;

    vector<int> col_width;

    for (int i = 0; i < n; i++) {
        getline(cin, line);
        istringstream sin(line);

        vector<string> row;
        string cell;

        while (getline(sin, cell, ',')) {
            row.push_back(cell);
        }

        if (line.back() == ',')
            row.push_back("");

        if (line != "") {
            if (col_width.empty())
                col_width.assign(row.size(), 0);
            for (int j = 0; j < row.size(); j++)
                col_width[j] = max(col_width[j], (int)row[j].size());
        }

        table.push_back(row);
    }

    if (col_width.size() == 0)
        col_width = {0};

    hrule(col_width);

    for (int i = 0; i < n; i++) {
        if (table[i].size() == 0)
            table[i].assign(col_width.size(), "");

        printf("|");

        for (int j = 0; j < table[i].size(); j++) {
            bool num = true;

            for (char ch: table[i][j])
                if (ch < '0' || ch > '9')
                    num = false;
            if (num) {
                printn(' ', col_width[j] - table[i][j].size());
                cout << table[i][j];
            } else {
                cout << table[i][j];
                printn(' ', col_width[j] - table[i][j].size());
            }
            cout << "|";
        }
        cout << "\n";
        hrule(col_width);
    }
}
