// Subsequence: Need not be contiguous, but maintains order

// There are 2^(n) - 1 subsequences excluding empty subsequence

// Each element occurs 2^(n-1) times considering all subsequences

#include <bits/stdc++.h>

using namespace std;

int sum_of_subsequences(int *arr, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * (1 << n - 1);
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sum_of_subsequences(arr, n);
    return 0;
}