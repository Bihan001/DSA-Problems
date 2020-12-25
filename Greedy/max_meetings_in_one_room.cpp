#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pii pair<int, int>
#define pb push_back

// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room
// Find maximum meetings that can be held in a room given their start and finish times.
// This problem is similar to the activity_selection problem

// Helper function
bool compare(pair<pii, int> a, pair<pii, int> b) {
    return a.first.second < b.first.second;
}

// Time complexity: O(nlogn) | Space complexity: O(1)
vi max_meetings(vi start, vi finish) {
    vector<pair<pii, int>> arr;
    vi ans;
    for (int i = 0; i < start.size(); i++) {
        arr.pb({{start[i], finish[i]}, i + 1});
    }
    sort(arr.begin(), arr.end(), compare);
    ans.pb(arr[0].second);
    int last = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i].first.first >= arr[last].first.second) {
            ans.pb(arr[i].second);
            last = i;
        }
    }
    return ans;
}

int main() {
    vi start = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    vi finish = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};
    vi ans = max_meetings(start, finish);
    for (auto it : ans) {
        cout << it << " ";
    }
    return 0;
}