#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// Converting an array into zig zag fashion i.e. a < b > c < d > e < f > g ....
// Multiple solutions can be present

// Time complexity: O(n) | Space complexity: O(1)
void convert_zig_zag(vi &arr) {
    char current = '<';
    for (int i = 0; i < arr.size() - 1; i++) {
        if (current == '<') {
            if (arr[i] > arr[i + 1]) swap(arr[i], arr[i + 1]);
        } else if (current == '>') {
            if (arr[i] < arr[i + 1]) swap(arr[i], arr[i + 1]);
        }
        current = current == '<' ? '>' : '<';
    }
}

// Time complexity: O(nlogn) | Space complexity: O(1)
void convert_zig_zag_1(vi &arr) {
    sort(arr.begin(), arr.end());
    for (int i = 1; i < arr.size() - 1; i += 2) {
        swap(arr[i], arr[i + 1]);
    }
}

int main() {
    vi arr = {4, 3, 7, 8, 6, 2, 1};
    convert_zig_zag(arr);
    for (auto x : arr) cout << x << " ";
    cout << endl;
    convert_zig_zag_1(arr);
    for (auto x : arr) cout << x << " ";
    return 0;
}