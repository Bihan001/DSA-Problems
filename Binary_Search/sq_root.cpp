#include <bits/stdc++.h>

using namespace std;

// Finding square root of a number which has an integer square root

// Time complexity: O(logn) | Space complexity: O(1)
int sq_root(int n) {
    int low = 0, high = n, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return mid;
}

int main() {
    int n = 400;
    cout << sq_root(n);
    return 0;
}