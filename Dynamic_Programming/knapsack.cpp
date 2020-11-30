#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

int knapsack(vi vals, vi wts, int n, int w) {
    if (n == 0 || w == 0) return 0;
    if (wts[n - 1] > w) {
        return knapsack(vals, wts, n - 1, w);
    }
    return max(vals[n - 1] + knapsack(vals, wts, n - 1, w - wts[n - 1]), knapsack(vals, wts, n - 1, w));
}

int knapsack_dp(vi vals, vi wts, int n, int w) {
    int table[w + 1][n];
    for (int i = 0; i < n; i++) table[0][i] = 0;
    for (int i = 1; i <= w; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                if (wts[j] <= i) {
                    table[i][j] = vals[j];
                } else {
                    table[i][j] = 0;
                }
            } else {
                if (i - wts[j] < 0) {
                    table[i][j] = table[i][j - 1];
                } else {
                    table[i][j] = max(table[i][j - 1], vals[j] + table[i - wts[j]][j - 1]);
                }
            }
        }
    }
    return table[w][n - 1];
}

int main() {
    vi values = {359, 963, 465, 706, 146, 282, 828, 962, 492};
    vi weights = {96, 43, 28, 37, 92, 5, 3, 54, 93};
    int w = 383;
    int ans = knapsack(values, weights, values.size(), w);
    cout << ans << endl;
    ans = knapsack_dp(values, weights, values.size(), w);
    cout << ans << endl;
    return 0;
}