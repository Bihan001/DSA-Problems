#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// https://www.geeksforgeeks.org/find-minimum-maximum-amount-buy-n-candies/
// If price of n different candies are given and k different candies are given for free when one candy is bought then find the max and min amount required to have all the candies

// Time complexity : O(n) | Space complexity: O(1)
vi max_min_candies(vi arr, int k) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) {
        min += arr[i];
        n -= k;
    }
    int c = 0;
    n = arr.size();
    for (int i = n - 1; i >= c; i--) {
        max += arr[i];
        c += k;
    }
    return {min, max};
}

int main() {
    vi arr = {1, 2, 3, 4};
    int k = 2;
    vi ans = max_min_candies(arr, k);
    cout << ans[0] << " " << ans[1] << " " << endl;
    return 0;
}