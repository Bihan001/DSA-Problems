#include <bits/stdc++.h>

using namespace std;

int main() {
    int s = 10, n = 16, m = 2;
    if (m > n || (s > 6 && (m * 7) > (n * 6))) {
        cout << "No" << endl;
    } else {
        int days = (m * s) / n;
        if ((m * s) % n != 0) days++;
        cout << "Yes " << days << endl;
    }
    return 0;
}