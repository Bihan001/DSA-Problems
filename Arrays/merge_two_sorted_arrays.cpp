#include <bits/stdc++.h>

using namespace std;

// Merge two sorted arrays so that the resulting array is also sorted

// Time complexity: O(n) | Space complexity: O(n)
vector<int> merge_arrays(vector<int> arr1, vector<int> arr2) {
    int n1 = arr1.size(), n2 = arr2.size();
    vector<int> arr3(n1 + n2);
    int i = 0, j = 0, k = 0;
    while (k < n1 + n2) {
        if (i == n1) {
            arr3[k++] = arr2[j++];
            continue;
        }
        if (j == n2) {
            arr3[k++] = arr1[i++];
            continue;
        }
        if (arr1[i] <= arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
    return arr3;
}

int main() {
    vector<int> arr1 = {-1, 0, 1, 1, 2, 3, 5, 10};
    vector<int> arr2 = {2, 4, 6, 8, 9};
    vector<int> arr_merged = merge_arrays(arr1, arr2);
    for (auto it : arr_merged) cout << it << " ";
    return 0;
}
