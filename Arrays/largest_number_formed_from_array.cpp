#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

// Find largest number by concatenating all array elements in order

// Helper function to sort array in descending order based on following condition
bool compare(int a, int b) {
    string sa = to_string(a), sb = to_string(b);
    return stoi(sa + sb) > stoi(sb + sa);
}

// Time complexity: O(n) | Space complexity: O(1)
void largest_number_from_array(vi arr) {
    sort(arr.begin(), arr.end(), compare);
    for (int i = 0; i < arr.size(); i++) cout << arr[i];
}

int main() {
    vi arr = {54, 546, 548, 60};
    largest_number_from_array(arr);
    return 0;
}