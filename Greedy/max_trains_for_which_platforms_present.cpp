#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>

// https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/
// Find max number of trains that can stop at platforms, given their platform number, arrival and departure times.
// Approach: We sort the trains of same platform number by their departure times then use same algorithm as activity_selection problem

// Time complexity: O(nlogn) | Space complexity: O(1)
int max_trains(map<int, vector<pii>> &m) {
    for (auto &it : m) {
        sort(it.second.begin(), it.second.end());
    }
    int ans = 1;
    for (auto it : m) {
        int last = 0;
        for (int i = 1; i < it.second.size(); i++) {
            if (it.second[i].first >= it.second[last].second) {
                ans++;
                last = i;
            }
        }
    }
    return ans;
}

int main() {
    map<int, vector<pii>> m;
    m[1].pb({1000, 1030});
    m[1].pb({1010, 1030});
    m[1].pb({900, 1005});
    m[2].pb({1000, 1020});
    m[2].pb({1030, 1230});
    m[3].pb({1200, 1230});
    cout << max_trains(m) << endl;
    m.clear();
    m[1].pb({1000, 1030});
    m[1].pb({1110, 1130});
    m[1].pb({1200, 1230});
    cout << max_trains(m) << endl;
    return 0;
}