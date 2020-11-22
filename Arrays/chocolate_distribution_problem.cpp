#include <bits/stdc++.h>

using namespace std;

// Find min difference between packet with max chocolates and packet with min chocolates

// Time complexity: O(nlogn) | Space complexity: O(1)
int chocolate_distribution(vector<int> arr, int m) {
    int min_diff = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - m + 1; i++) {
        min_diff = min(min_diff, arr[i + m - 1] - arr[i]);
    }
    return min_diff;
}

int main() {
    vector<int> arr = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int number_of_students = 7;
    int ans = chocolate_distribution(arr, number_of_students);
    cout << ans << endl;
    return 0;
}