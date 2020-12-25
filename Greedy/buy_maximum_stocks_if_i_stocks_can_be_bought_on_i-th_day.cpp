#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back

// https://www.geeksforgeeks.org/buy-maximum-stocks-stocks-can-bought-th-day/
// Find max number of stocks that can be bought for given amount of money, if only i number of stocks can be bought on ith day

// Time complexity: O(n) | Space complexity: O(1)
int max_stocks(vector<pii> arr, int k) {
    int ans = 0;
    sort(arr.begin(), arr.end());
    for (auto it : arr) {
        int p = min(it.second, k / it.first);
        ans += p;
        k -= it.first * p;
    }
    return ans;
}

int main() {
    vector<pii> arr;
    arr.pb({10, 1});
    arr.pb({7, 2});
    arr.pb({19, 3});
    int k = 45;
    cout << max_stocks(arr, k) << endl;
    return 0;
}