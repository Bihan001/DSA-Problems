// Subarray: Contiguous sequence in an array

// Using sliding window technique

#include <bits/stdc++.h>

using namespace std;

vector<int> sum_of_subarrays(int *arr, int n, int k) {
    long long sum = 0;
    vector<int> res;
    for (int i = 0; i < k; i++) sum += arr[i];
    res.push_back(sum);
    for (int i = 0, j = k; j < n; i++, j++) {
        sum -= arr[i];
        sum += arr[j];
        res.push_back(sum);
    }
    return res;
}

int main() {
    int arr[] = {1, -2, 3, -4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    vector<int> ans = sum_of_subarrays(arr, n, k);
    for (auto it : ans) cout << it << " ";
    return 0;
}