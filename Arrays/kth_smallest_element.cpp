#include <bits/stdc++.h>

using namespace std;

// Finding the Kth smallest element in an array
// Finding Kth largest element is similar

// TODO - Using quicksort

// Using max heap(Default STL priority queue)
// Time complexity: O(n) : Space complexity: O(n)
int kth_smallest_max_heap(vector<int> arr, int k) {
    priority_queue<int> pq;
    int cnt = 0;
    while (cnt <= k && cnt < arr.size()) pq.push(arr[cnt++]);
    while (cnt < arr.size()) {
        pq.pop();
        pq.push(arr[cnt++]);
    }
    pq.pop();
    int t = pq.top();
    while (!pq.empty()) pq.pop();
    return t;
}

// Using min heap(priority queue greater<int>)
// Time complexity: O(n) : Space complexity: O(n)
int kth_smallest_min_heap(vector<int> arr, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt = 0;
    while (cnt < arr.size()) pq.push(arr[cnt++]);
    while (k > 1) {
        pq.pop();
        k--;
    }
    int t = pq.top();
    while (!pq.empty()) pq.pop();
    return t;
}

int main() {
    vector<int> arr = {4, 6, 40, 1, 2, 3, 5, 67, 78, 10};
    int k = 3;
    int ans = kth_smallest_max_heap(arr, k);
    cout << ans << endl;
    ans = kth_smallest_min_heap(arr, k);
    cout << ans << endl;
    return 0;
}
