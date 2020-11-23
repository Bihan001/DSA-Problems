#include <bits/stdc++.h>

using namespace std;

// Find max profit on buying and selling stocks

// Time complexity: O(n) | Space complexity: O(1)
int buy_and_sell_stocks(vector<int> arr) {
    if (arr.size() == 0) return 0;
    int min_el = arr[0];
    int maxProfit = 0;
    int currentProfit = 0;
    for (int i = 0; i < arr.size(); i++) {
        min_el = min(min_el, arr[i]);
        currentProfit = arr[i] - min_el;
        maxProfit = max(maxProfit, currentProfit);
    }
    return maxProfit;
}

int main() {
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    int ans = buy_and_sell_stocks(arr);
    cout << ans << endl;
    return 0;
}