#include <bits/stdc++.h>

using namespace std;

// Checking if a given subsequence is valid for a given array

// Time complexity: O(n)
bool validate_subsequence(int *arr, int *sub, int n1, int n2) {
    int p = 0;
    for (int i = 0; i < n1; i++) {
        if (arr[i] == sub[p]) p++;
        if (p == n2) return true;
    }
    return p == n2;
}

int main() {
    int arr[] = {5, 1, 22, 25, 6, -1, 8, 10};
    int sub[] = {1, 6, -1, 10};
    int n1 = sizeof(arr) / sizeof(arr[0]);
    int n2 = sizeof(sub) / sizeof(sub[0]);
    bool ans = validate_subsequence(arr, sub, n1, n2);
    cout << ans << endl;
    return 0;
}