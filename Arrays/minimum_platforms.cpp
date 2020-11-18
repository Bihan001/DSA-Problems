#include <bits/stdc++.h>

using namespace std;

// Find minimum platforms required so that none of the trains at given intervals have to wait to reach the platform

// Time complexity: O(n) | Space complexity: O(max_element(dep))
int minimum_platforms_1(int *arr, int *dep, int n) {
    int m = *max_element(dep, dep + n);
    int dp[m + 1] = {0};
    for (int i = 0; i < n; i++) {
        dp[arr[i]] += 1;
        if (dep[i] + 1 <= m) {
            dp[dep[i] + 1] -= 1;
        }
    }
    for (int i = 1; i <= m; i++) dp[i] = dp[i - 1] + dp[i];
    return *max_element(dp, dp + m + 1);
}

// Time complexity: O(nlogn) | Space complexity: O(1)
int minimum_platforms_2(int *arr, int *dep, int n) {
    sort(arr, arr + n);
    sort(dep, dep + n);
    int i = 1, j = 0, platforms = 1, ans = 1;
    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms++;
            i++;
        } else {
            platforms--;
            j++;
        }
        ans = max(platforms, ans);
    }
    return ans;
}

int main() {
    int arr[] = {900, 950, 940, 1800, 1500, 1100};
    int dep[] = {910, 1120, 1200, 2000, 1900, 1130};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << minimum_platforms_1(arr, dep, n) << endl;
    cout << minimum_platforms_2(arr, dep, n) << endl;
    return 0;
}