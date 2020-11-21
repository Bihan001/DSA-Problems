#include <bits/stdc++.h>

using namespace std;

// Find total units of rainwater that can be stored for the given array of heights

// Time complexity: O(n) | Space complexity: O(n)
int trapping_rainwater(int *arr, int n) {
    if (n == 0) return 0;
    int cnt = 0;
    int left[n] = {0}, right[n] = {0};
    int ml = arr[0], mr = arr[n - 1];
    for (int i = 1; i < n; i++) {
        left[i] = max(ml, left[i - 1]);
        ml = max(ml, arr[i]);
    }
    for (int i = n - 2; i >= 0; i--) {
        right[i] = max(mr, right[i + 1]);
        mr = max(mr, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        int tmp = min(left[i], right[i]);
        tmp = tmp - arr[i];
        cnt += tmp < 0 ? 0 : tmp;
    }
    return cnt;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = trapping_rainwater(arr, n);
    cout << ans;
    return 0;
}
