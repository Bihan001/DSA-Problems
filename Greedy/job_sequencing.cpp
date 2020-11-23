#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

// Select the jobs which has the highest profit

// TODO: Optimise time complexity with disjoint set

// Time complexity: O(n^2) | Space complexity: O(n)
vector<pii> job_sequencing(vector<pii> arr) {
    sort(arr.begin(), arr.end(), greater<pii>());
    int deadline = 1;
    for (auto it : arr) deadline = max(deadline, it.second);
    vector<pii> res;
    vector<bool> slots(deadline + 1, false);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = arr[i].second; j >= 1; j--) {
            if (!slots[j]) {
                slots[j] = true;
                res.pb(arr[i]);
                break;
            }
        }
    }
    return res;
}

int main() {
    vector<pii> arr = {{100, 2}, {19, 1}, {27, 2}, {25, 1}, {15, 3}};
    vector<pii> ans = job_sequencing(arr);
    for (auto it : ans) cout << it.first << " " << it.second << endl;
    return 0;
}