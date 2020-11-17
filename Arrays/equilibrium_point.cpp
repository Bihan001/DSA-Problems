#include <bits/stdc++.h>

using namespace std;

// Finding index of an array such that the sum of elements to its left equals to the sum of elements to its right

// Time complexity: O(n)
int equilibrium_index(int *arr, int n) {
    int pre_sum = 0, suf_sum = 0;
    for (int i = 0; i < n; i++) suf_sum += arr[i];
    for (int i = 0; i < n; i++) {
        suf_sum -= arr[i];
        if (pre_sum == suf_sum) return i;
        pre_sum += arr[i];
    }
    return -1;
}

int main() {
    int arr[] = {-7, 1, 5, 2, -4, 3, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = equilibrium_index(arr, n);
    cout << ans << endl;
    return 0;
}
