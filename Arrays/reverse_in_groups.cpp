#include <bits/stdc++.h>

using namespace std;

// Reverse all subarrays of given size

// Time complexity: O(n)
void reverse_in_groups(int *arr, int n, int k) {
    int i = 0, j = 0, t = 0;
    while (t < n) {
        i = min(t, n - 1);
        j = min(t + k - 1, n - 1);
        while (i < j) {
            swap(arr[i++], arr[j--]);
        }
        t += k;
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    reverse_in_groups(arr, n, k);
    for (auto it : arr) cout << it << " ";
    return 0;
}
