#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// Finding three largest numbers in an array

// Time complexity: O(n)
vector<int> three_largest_numbers(vi arr) {
    vector<int> res(3, INT_MIN);
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > res[2]) {
            int tmp = res[2];
            res[2] = arr[i];
            swap(tmp, res[1]);
            res[0] = tmp;
        } else if (arr[i] > res[1]) {
            swap(res[0], res[1]);
            res[1] = arr[i];
        } else if (arr[i] > res[0]) {
            res[0] = arr[i];
        }
    }
    return res;
}

int main() {
    vi arr = {16, 17, 4, 3, 5, 2};
    vector<int> ans = three_largest_numbers(arr);
    for (auto x : ans) cout << x << " ";
    return 0;
}