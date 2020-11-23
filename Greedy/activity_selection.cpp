#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

// Helper function to sort array in ascending order based on second element of pair
bool comp(pii a, pii b) {
    return a.second < b.second;
}

// Find max activities that can be performed by a single person

// Time complexity: O(n) | Space complexity: O(1)
vector<pii> activity_selection(vector<pii> arr) {
    sort(arr.begin(), arr.end(), comp);
    vector<pii> res;
    res.pb(arr[0]);
    int last = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].first >= arr[last].second) {
            res.pb(arr[i]);
            last = i;
        }
    }
    return res;
}

int main() {
    vector<pii> arr = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}};
    vector<pii> ans = activity_selection(arr);
    for (auto it : ans) cout << it.first << " " << it.second << endl;
    return 0;
}