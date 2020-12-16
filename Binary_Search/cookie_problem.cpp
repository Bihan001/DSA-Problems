#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

bool check(vi present, vi req, int mp, int mid) {
    for (int i = 0; i < req.size(); i++) {
        if (mid * req[i] <= present[i]) continue;
        mp -= (mid * req[i]) - present[i];
        if (mp < 0) return false;
    }
    return true;
}

int calc_cookies(vi present, vi req, int mp) {
    int low = 0, high = 100000000, mid;
    while (high - low > 1) {
        mid = (low + high) / 2;
        if (check(present, req, mp, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return check(present, req, mp, high) ? high : low;
}

int main() {
    vi present = {2, 1, 3, 1, 1, 4};
    vi req = {2, 3, 4, 1, 2, 3};
    int magic_powder = 20;
    int ans = calc_cookies(present, req, magic_powder);
    cout << ans;
    return 0;
}