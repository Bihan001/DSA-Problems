#include <bits/stdc++.h>

using namespace std;

// Find all the pythogorian triplets in a given array

#define vi vector<int>
#define pb push_back

// Time complexity: O(n^2) | Space complexity: O(n)
vector<vi> pythogorian_triplets(vi arr) {
    if (arr.size() < 3) return {};
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vi> res;
    vi sq;
    for (auto it : arr) sq.pb(it * it);
    for (int k = n - 1; k >= 2; k--) {
        int i = 0, j = k - 1;
        while (i < j) {
            int tmpSum = sq[i] + sq[j];
            if (tmpSum == sq[k]) {
                vi tmp;
                res.pb({arr[i], arr[j], arr[k]});
                i++, j--;
            } else if (tmpSum < sq[k])
                i++;
            else
                j--;
        }
    }
    return res;
}

int main() {
    vi arr = {3, 1, 4, 6, 5};
    int sum = 0;
    vector<vi> ans = pythogorian_triplets(arr);
    for (auto it : ans) {
        for (auto x : it) cout << x << " ";
        cout << endl;
    }
    return 0;
}