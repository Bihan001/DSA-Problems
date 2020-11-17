#include <bits/stdc++.h>

using namespace std;

// Finding the sum of the products of all possible pairs in an array

/*
Explanation from gfg:
We know that
(a + b + c)^2 = a^2 + b^2 + c^2 + 2*(a*b + b*c + c*a)
Let required sum be P
Let E = (a1 + a2 + a3 + a4 ... + an)^2 
=> E = a1^2 + a2^2 + ... + an^2 + 2*(a1*a2 + a1*a3 + ....)
=> E = S + 2*(P)        let S = a1^2 + a2^2 + ... + an^2, P = a1*a2 + a1*a3 + ....
=> P = ( E - S ) / 2
*/

// Time complexity: O(n)
long long sum_of_products_of_all_pairs(int *arr, int n) {
    long long E = 0, S = 0;
    for (int i = 0; i < n; i++) E += arr[i];
    E = E * E;
    for (int i = 0; i < n; i++) S += arr[i] * arr[i];
    return (E - S) / 2;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long ans = sum_of_products_of_all_pairs(arr, n);
    cout << ans << endl;
    return 0;
}