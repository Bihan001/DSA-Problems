#include <bits/stdc++.h>

using namespace std;

// Rearrange array alternatively

// TODO: Space complexity: O(1)

// Time complexity: O(n) | Space complexity: O(n)
void rearrange_array(int *arr, int n) {
    int tmp[n];
    int l = 0, h = n - 1;
    for (int i = 0; i < n; i++) {
        if (i & 1)
            tmp[i] = arr[l++];
        else
            tmp[i] = arr[h--];
    }
    for (int i = 0; i < n; i++) arr[i] = tmp[i];
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    rearrange_array(arr, n);
    for (int it : arr) cout << it << " ";
    return 0;
}
