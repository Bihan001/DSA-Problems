#include <bits/stdc++.h>

using namespace std;

// Finding max contagious subarray sum

int kadane(int *arr, int n) {
    int max = INT_MIN, cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += arr[i];
        if (cnt > max) max = cnt;
        if (cnt < 0) cnt = 0;
    }
    return max;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = kadane(arr, n);
    cout << ans << " ";
    return 0;
}