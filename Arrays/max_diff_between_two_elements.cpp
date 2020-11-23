#include <bits/stdc++.h>

using namespace std;

// Finding the max diff between two elements such that larger element appears after the smaller number

// Time complexity: O(n) | Space complexity: O(1)
int max_diff(vector<int> arr) {
    int max_diff = arr[1] - arr[0];
    int min_el = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        max_diff = max(max_diff, arr[i] - min_el);
        min_el = min(min_el, arr[i]);
    }
    return max_diff;
}

int main() {
    vector<int> arr = {1, 2, 90, 10, 110};
    int ans = max_diff(arr);
    cout << ans << endl;
    return 0;
}