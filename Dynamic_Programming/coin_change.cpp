#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

int coin_change(vi coins, int n, int target) {
    if (target == 0) return 1;
    if (target < 0) return 0;
    if (target >= 1 && n <= 0) return 0;
    int exclude_coin = coin_change(coins, n - 1, target);
    int include_coin = coin_change(coins, n, target - coins[n - 1]);
    return exclude_coin + include_coin;
}

int coin_change_dp(vi coins, int n, int target) {
    if (target == 0) return 1;
    int ans = 0;
    int table[target + 1][n];
    for (int i = 0; i < n; i++) table[0][i] = 1;
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            int exclude_coin = j > 0 ? table[i][j - 1] : 0;
            int include_coin = i - coins[j] >= 0 ? table[i - coins[j]][j] : 0;
            table[i][j] = include_coin + exclude_coin;
        }
    }
    return table[target][n - 1];
}

int main() {
    vi coins = {1, 2, 3};
    int n = 4;
    int ans = coin_change(coins, coins.size(), n);
    cout << ans << endl;
    ans = coin_change_dp(coins, coins.size(), n);
    cout << ans << endl;
    return 0;
}