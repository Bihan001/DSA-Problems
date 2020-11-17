#include <bits/stdc++.h>

using namespace std;

// The Next greater Element(NGE) for an element x is the first greater element on the right side of x in an array.

// Time complexity: O(n)
vector<int> nge(int *arr, int n) {
    vector<int> res;
    stack<int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++) {
        while (!s.empty() && arr[i] > s.top()) {
            res.push_back(arr[i]);
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.empty()) {
        res.push_back(-1);
        s.pop();
    }
    return res;
}

int main() {
    int arr[] = {11, 13, 21, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans = nge(arr, n);
    for (auto x : ans) cout << x << " ";
    cout << endl;
    int arr1[] = {4, 5, 2, 25};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    ans = nge(arr1, n1);
    for (auto x : ans) cout << x << " ";
    return 0;
}