#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>

// https://codeforces.com/problemset/problem/778/A - Details about the question
// Checking whether we can find a given substring in a string after removing a sequence of characters from the string

bool check(string s, string sub, vi arr, int mid) {
    string tmp = s;
    for (int i = 1; i <= mid; i++) {
        tmp[arr[i] - 1] = '$';
    }
    int j = 0;
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == sub[j]) j++;
        if (j == sub.size()) return true;
    }
    return false;
}

int count_removals(string s, string sub, vi arr) {
    int low = 0, high = arr.size(), mid;
    while (high - low > 1) {
        mid = (low + high) / 2;
        if (check(s, sub, arr, mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return check(s, sub, arr, high) ? high : low;
}

int main() {
    string s = "bbbabb";
    string sub = "bb";
    // Indexes of letters to be removed
    vi arr = {INT_MAX, 1, 6, 3, 4, 2, 5};
    // Prints the max number of letters that can be remoevd from the string to get the substring
    cout << count_removals(s, sub, arr);
    return 0;
}