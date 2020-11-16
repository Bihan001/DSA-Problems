#include <bits/stdc++.h>

using namespace std;

// Sum of two numbers equals to a third number in the array

// Time complexity: O(n^2)

vector<vector<int>> count_triplets(int *arr, int n) {
    vector<vector<int>> res;
    map<int, int> hash;
    int k = n - 1;
    for (int i = 0; i < n; i++) hash[arr[i]]++;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (hash[arr[i] + arr[j]] > 0) {
                vector<int> tmp;
                tmp.push_back(arr[i]);
                tmp.push_back(arr[j]);
                tmp.push_back(arr[i] + arr[j]);
                res.push_back(tmp);
            }
        }
    }
    return res;
}

int main() {
    int arr[] = {5, 32, 1, 7, 10, 50, 19, 21, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> ans = count_triplets(arr, n);
    for (auto x : ans) cout << x[0] << " " << x[1] << " " << x[2] << endl;
    return 0;
}