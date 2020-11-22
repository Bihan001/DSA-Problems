#include <bits/stdc++.h>

using namespace std;

// Find sets of three numbers in an array such that its sum equals to a given sum

#define vi vector<int>
#define pb push_back

// Time complexity: O(n^2) | Space Complexity: O(n)
vector<vi> three_number_sum(vi arr, int s) {
    if (arr.size() < 3) return {};
    vector<vi> res;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            int tmpSum = arr[i] + arr[j] + arr[k];
            if (tmpSum == s) {
                res.pb({arr[i], arr[j], arr[k]});
                i++, j--;
            } else if (tmpSum < s)
                i++;
            else if (tmpSum > s)
                j--;
        }
    }
    return res;
}

int main() {
    vi arr = {-8, -6, 1, 2, 3, 5, 6, 12};
    int sum = 0;
    vector<vi> ans = three_number_sum(arr, sum);
    for (auto it : ans) {
        for (auto x : it) cout << x << " ";
        cout << endl;
    }
    return 0;
}