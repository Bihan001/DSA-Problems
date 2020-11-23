#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// Finding the index of an element in array such that all elements to its left is less than it and all elements to its right are greater than it

// Time complexity: O(n) | Space complexity: O(n)
int equilibrium_index(vi arr) {
    vi leftMax(arr.size(), INT_MIN), rightMin(arr.size(), INT_MAX);
    for (int i = 1; i < arr.size(); i++) {
        leftMax[i] = max(leftMax[i - 1], arr[i - 1]);
    }
    for (int i = arr.size() - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);
    }
    for (int i = 1; i < arr.size() - 1; i++) {
        if (leftMax[i] < arr[i] && rightMin[i] > arr[i]) return i;
    }
    return -1;
}

int main() {
    vi arr = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    int ans = equilibrium_index(arr);
    cout << ans << endl;
    return 0;
}
