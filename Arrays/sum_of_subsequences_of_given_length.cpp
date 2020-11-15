// Subsequence: Need not be contiguous, but maintains order

// There are nCk subsequences of length k

// Total elements in all k length subsequences is k * nCk

// So each element occurs (k * nCk) / n times considering all k length subsequences

#include <bits/stdc++.h>

using namespace std;

int fact(int n) {
    if (n <= 1) return 1;
    return n * fact(n - 1);
}

int nCr(int n, int r) {
    return fact(n) / (fact(r) * fact(n - r));
}

int subsequences_sum(int *arr, int n, int k) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    // We can multiply the expression to each element and then add it to total sum or we can just take common and multiply it to the final sum
    return sum * (k * nCr(n, k) / n);
}

int main() {
    int arr[] = {2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    cout << subsequences_sum(arr, n, k);
    return 0;
}