#include <bits/stdc++.h>

using namespace std;

// Increment values in given range for q queries

void update_array(int *arr, int n, int q, int queries[][3]) {
    int tmp[n] = {0};
    for (int i = 0; i < q; i++) {
        int start = queries[i][0], end = queries[i][1], val = queries[i][2];
        tmp[start] += val;
        tmp[end + 1] -= val;
    }
    for (int i = 1; i < n; i++) {
        tmp[i] += tmp[i - 1];
    }
    for (int i = 0; i < n; i++) arr[i] += tmp[i];
}

int main() {
    int arr[] = {13, 64, 53, 25, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int q = 2;
    int queries[q][3] = {{1, 2, 24}, {1, 3, 6}};
    update_array(arr, n, q, queries);
    for (auto x : arr) cout << x << " ";
    return 0;
}