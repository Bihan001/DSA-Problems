#include <bits/stdc++.h>

using namespace std;

// Helper function to count even numbers in an array
int count_even_numbers(vector<int> arr) {
    int cnt = 0;
    for (auto it : arr)
        if (!(it & 1)) cnt += 1;
    return cnt;
}

// Modifying original array to add duplicate of even numbers after itself

// Time complexity: O(n)
void repeat_even_numbers_twice(vector<int> &arr) {
    int evens = count_even_numbers(arr);
    int l = arr.size() - 1;
    arr.resize(arr.size() + evens);
    int h = arr.size() - 1;
    for (; l >= 0; l--) {
        if (arr[l] & 1) {
            arr[h--] = arr[l];
        } else {
            arr[h--] = arr[l];
            arr[h--] = arr[l];
        }
    }
}

int main() {
    vector<int> arr = {2, 4, 1, 0, 3};
    repeat_even_numbers_twice(arr);
    for (auto it : arr) cout << it << " ";
    return 0;
}