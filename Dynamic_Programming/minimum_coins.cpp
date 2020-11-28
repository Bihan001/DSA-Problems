#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// Find minimum number of coins required to make a given amount and print -1 if the amount cannot be made.
// For coins [3,4] and target 5, output should be -1.

// Time complexity: O(n^2) | Space complexity: O(n^2)
int minimum_coins(vi coins, int target) {
    if (target == 0) return 0;
    int n = coins.size();
    if (n == 0) return -1;
    int table[target + 1][n];
    for (int i = 0; i < n; i++) table[0][i] = 0;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                if (i - coins[j] < 0)
                    table[i][j] = target + 1;  // Max value so it is never the answer
                else if (table[i - coins[j]][j] == target + 1)
                    table[i][j] = target + 1;
                else
                    table[i][j] = 1 + table[i - coins[j]][j];
            } else {
                if (i - coins[j] < 0)
                    table[i][j] = table[i][j - 1];
                else
                    table[i][j] = min(table[i][j - 1], 1 + table[i - coins[j]][j]);
            }
        }
    }
    // DP table
    // for (int i = 0; i < target + 1; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << table[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return table[target][n - 1] == target + 1 ? -1 : table[target][n - 1];
}

int main() {
    vi coins = {1, 5, 6, 9};
    sort(coins.begin(), coins.end());
    int target = 11;
    int ans = minimum_coins(coins, target);
    cout << ans << endl;
    return 0;
}