#include <bits/stdc++.h>

using namespace std;

int nCr(int n, int r) {
    // First or last column
    if (r == 0 || r == n) return 1;

    return nCr(n - 1, r - 1) + nCr(n - 1, r);
}

// Time complexity: O(n^2) | Space complexity: O(n^2)
int nCr_dp(int n, int k) {
    int table[n + 1][k + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                table[i][j] = 1;
            else
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
        }
    }
    // Prints Pascal's triangle
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= i; j++) {
    //         cout << table[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    return table[n][k];
}

int main() {
    cout << nCr(5, 2) << endl
         << nCr(5, 3) << endl
         << nCr(4, 2) << endl
         << nCr_dp(5, 2) << endl
         << nCr_dp(5, 3) << endl
         << nCr_dp(4, 3) << endl;
    return 0;
}