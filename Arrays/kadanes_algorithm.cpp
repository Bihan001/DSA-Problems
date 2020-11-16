#include <bits/stdc++.h>

using namespace std;

// Finding max contagious subarray sum

int kadane(int *arr, int n) {
    int max = arr[0], cnt = arr[0], start = 0, end = 0, tmp = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > cnt + arr[i]) {
            cnt = arr[i];
            tmp = i;
        } else {
            cnt += arr[i];
        }
        if (cnt >= max) {
            max = cnt;
            start = tmp;
            end = i;
        }
    }
    cout << start << ' ' << end << endl;
    return max;
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = kadane(arr, n);
    cout << ans << " ";
    return 0;
}