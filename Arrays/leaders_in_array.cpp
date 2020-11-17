#include <bits/stdc++.h>

using namespace std;

// Finding elements which are greater than all the elements to its right

// Time complexity: O(n)
vector<int> leaders_in_array(int *arr, int n) {
    vector<int> res;
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] > max) {
            max = arr[i];
            res.insert(res.begin(), arr[i]);
        }
    }
    return res;
}

int main() {
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = leaders_in_array(arr, n);
    for (auto x : ans) cout << x << " ";
    return 0;
}