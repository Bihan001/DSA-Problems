#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

/* An array is given which was initially sorted. Odd indexed elements have been swapped with each other randomly (One element can be swapped only once e.g. if 5 is swapped once then it cannot be swapped again).
   Even indexed elements remain intact.
   We are to check whether a given number is present in the array or not.
*/

/* Approach: We traverse all the even indexes and return the index if element is found.
   Else we search for the given number using binary search. If found we return the index. 
   Else we take the number present at that index and apply binary search on it. 
   If number is found there then we return the index else -1. 
   This is because every element can be swapped only once so if the element is not found first time,
   then it must be present in the corresponding index of the element present there.
*/

// Time complexity: O(logn) | Space complexity: O(1)
int search_number(vi arr, int k) {
    int bkp = k;
    for (int i = 1; i < arr.size(); i += 2) {
        if (arr[i] == k) return i;
        if (arr[i] > k) break;
    }
    int low = 0, high = arr.size() - 1, mid;
    while (high - low > 1) {
        mid = (low + high) / 2;
        if (arr[mid] == bkp) {
            return mid;
        } else if (arr[mid] < k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    if ((low + 1) & 1) {
        k = arr[low];
    } else {
        k = arr[high];
    }
    low = 0, high = arr.size() - 1, mid;
    while (high - low > 1) {
        mid = (low + high) / 2;
        if (arr[mid] == bkp) {
            return mid;
        } else if (arr[mid] < k) {
            low = mid;
        } else {
            high = mid;
        }
    }
    return -1;
}

int main() {
    vi arr = {19, 3, 10, 8, 5, 12, 1, 25};
    int k = 5;
    int ans = search_number(arr, k);
    cout << ans;
    return 0;
}