#include <bits/stdc++.h>

using namespace std;

// Time complexity: O(n^2) | Space complexity: O(n^2)
int nPr(int n, int r) {
    static int table[100000][100000];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            if (j == 0) {
                table[i][j] = 1;
            } else {
                table[i][j] = table[i - 1][j] + (j * table[i - 1][j - 1]);
            }
            table[i][j + 1] = 0;
        }
    }
    return table[n][r];
}

int main() {
    cout << nPr(5, 4) << endl;
    return 0;
}