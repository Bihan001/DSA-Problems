#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// Given a sorted array of integers rotated few times, we need to find the min, max elements and the number of rotations performed
// If rotations == 3 then: [0,1,2,3,4,5] -> [1,2,3,4,5,0] -> [2,3,4,5,0,1] -> [3,4,5,0,1,2]

// Time complexity: O(logn) | Space complexity: O(1)
vi find_min_max_rotation(vi arr) {
    vi ans(3);
    int low = 0, high = arr.size() - 1, mid;
    while (high - low > 1) {
        mid = (high + low) / 2;
        if (arr[0] < arr[mid]) {
            low = mid;
        } else {
            high = mid;
        }
    }
    ans[0] = arr[high];
    ans[1] = arr[low];
    ans[2] = arr.size() - high;
    return ans;
}

int main() {
    vi arr = {3, 4, 5, 6, 7, 0, 1, 2};
    vi ans = find_min_max_rotation(arr);
    cout << "Min: " << ans[0] << " Max: " << ans[1] << " Rotation: " << ans[2] << endl;
    return 0;
}