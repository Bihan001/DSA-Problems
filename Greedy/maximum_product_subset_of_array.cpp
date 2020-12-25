#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// https://www.geeksforgeeks.org/maximum-product-subset-array
// Given an array, find maximum product possible with the subset of elements present in the array.

// Time complexity : O(n) | Space complexity : O(1)
int maximum_product_subset(vi arr) {
    if (arr.size() == 1) return arr[0];
    int negcnt = 0, zerocnt = 0, maxneg = INT_MIN, ans = 1;
    for (auto it : arr) {
        negcnt += it < 0, zerocnt += it == 0;
        maxneg = it >= 0 ? maxneg : max(maxneg, it);
        ans *= it == 0 ? 1 : it;
    }
    if (zerocnt == arr.size()) return 0;
    if (zerocnt > 0 && negcnt == 1 && zerocnt + negcnt == arr.size()) return 0;
    ans /= negcnt & 1 ? maxneg : 1;
    return ans;
}

int main() {
    vi arr = {-1, -1, -2, 4, 3};
    cout << maximum_product_subset(arr);
    return 0;
}