#include <bits/stdc++.h>

using namespace std;

// Sort an array which only contains values 0,1,2

// Inclusive ranges after sorting:
// arr[0 - (low-1)] - 0
// arr[low - (mid-1)] - 1
// arr[(high+1) - (n-1)] - 2

// Time complexity: O(n) | Space complexity: O(1)
void sort_012(int *arr, int n) {
    int l = 0, m = 0, h = n - 1;
    while (m <= h) {
        if (arr[m] == 0) {
            swap(arr[l], arr[m]);
            l++, m++;
        } else if (arr[m] == 1) {
            m++;
        } else if (arr[m] == 2) {
            swap(arr[m], arr[h]);
            h--;
        } else {
            break;
        }
    }
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort_012(arr, n);
    for (auto it : arr) cout << it << " ";
    return 0;
}
