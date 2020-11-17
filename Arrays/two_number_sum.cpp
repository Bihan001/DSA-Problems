#include <bits/stdc++.h>

using namespace std;

// Finding two numbers in an array such that its sum results to a given value

// Time complexity: O(n)
vector<int> two_number_sum_hash(int *arr, int n, int key) {
    map<int, int> hash;
    vector<int> res = {-1, -1};
    for (int i = 0; i < n; i++) {
        if (hash[key - arr[i]] > 0) {
            res[0] = arr[i];
            res[1] = key - arr[i];
            return res;
        } else {
            hash[arr[i]] = 1;
        }
    }
    return res;
}

// Time complexity: O(n)
vector<int> two_number_sum_sort(int *arr, int n, int key) {
    sort(arr, arr + n);
    int l = 0, h = n - 1;
    vector<int> res = {-1, -1};
    while (l < h) {
        if (arr[l] + arr[h] == key) {
            res[0] = arr[l];
            res[1] = arr[h];
            return res;
        } else if (arr[l] + arr[h] < key) {
            l++;
        } else {
            h--;
        }
    }
    return res;
}

int main() {
    int arr[] = {3, 5, -4, 8, 11, 1, -1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    vector<int> ans = two_number_sum_hash(arr, n, key);
    cout << ans[0] << " " << ans[1] << endl;
    ans = two_number_sum_sort(arr, n, key);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}