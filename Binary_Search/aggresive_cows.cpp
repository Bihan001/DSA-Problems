#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

// https://www.spoj.com/problems/AGGRCOW/
// Given an array of integers denoting distances between poles, place the given number of cows such that the minimum distance between them is maximised and output the distance

bool check(vi arr, int c, int mid) {
    ll cnt = 0, pre = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] - pre >= mid) {
            cnt++;
            pre = arr[i];
        }
    }
    return cnt >= c;
}

// Time complexity: O(nlogn) | Space complexity: O(1)
int aggresive_cows(vi arr, int c) {
    sort(arr.begin(), arr.end());
    int ans = INT_MIN;
    int low = 0, high = arr.size() - 1, mid;
    while (high - low > 1) {
        mid = (high + low) / 2;
        if (check(arr, c, mid)) {
            low = mid;
            ans = max(ans, mid);
        } else {
            high = mid;
        }
    }
    return ans;
}

int main() {
    vi arr = {1, 2, 8, 4, 9};
    int c = 3;
    int ans = aggresive_cows(arr, c);
    cout << ans << endl;
    return 0;
}