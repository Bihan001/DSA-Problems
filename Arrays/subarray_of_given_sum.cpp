#include <bits/stdc++.h>

using namespace std;

// Calculation is based on 0th based index

// Finding subarray with sum equal to given sum when all elements in the array are positive

deque<int> subarray_sum(int *arr, int n, int target) {
    deque<int> res;
    int sum = arr[0], l = 0, h = 0;
    res.push_back(0);
    while (sum != target && h < n) {
        if (sum > target) {
            while (sum > target) {
                sum -= arr[l++];
                res.pop_front();
            }
        } else if (sum < target) {
            sum += arr[++h];
            res.push_back(h);
        }
        if (sum == target) {
            cout << l << " " << h << endl;
            return res;
        }
    }
    return res;
}

int main() {
    int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 23;
    deque<int> ans = subarray_sum(arr, n, sum);
    for (auto x : ans) cout << x << " ";
    return 0;
}