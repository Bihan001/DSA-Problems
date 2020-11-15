// Subarray: Contiguous sequence in an array

// There are (n - i) subarrays where the subarray is beginning with arr[i]

// There are (n - i) * i subarrays where arr[i] is not the starting element

// So total number of subarrays which has arr[i] is (n - i) + ((n - i) * i) = (n - i) * (i + 1)

#include <bits/stdc++.h>

using namespace std;

int sum_of_subarrays(int *arr, int n) {
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i] * (n - i) * (i + 1);
    }
    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << sum_of_subarrays(arr, n);
    return 0;
}