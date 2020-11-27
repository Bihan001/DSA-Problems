#include <bits/stdc++.h>

using namespace std;

// Spirally traverse a matrix

// Time complexity: O(n * m) | Space complexity: O(Number of calls in recursion)
void spiral_matrix(vector<vector<int>> matrix, pair<int, int> src, pair<int, int> size) {
    int r = src.first;
    int c = src.second;
    int n = size.first;
    int m = size.second;
    if (r >= n || c >= m) return;

    for (int j = r; j < m; j++) {
        cout << matrix[r][j] << " ";
    }
    for (int i = r + 1; i < n; i++) {
        cout << matrix[i][m - 1] << " ";
    }
    if (r != n - 1) {
        for (int j = m - 2; j >= c; j--) {
            cout << matrix[n - 1][j] << " ";
        }
    }
    if (c != m - 1) {
        for (int i = n - 2; i > r; i--) {
            cout << matrix[i][c] << " ";
        }
    }
    spiral_matrix(matrix, {r + 1, c + 1}, {n - 1, m - 1});
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    spiral_matrix(matrix, {0, 0}, {matrix.size(), matrix[0].size()});
    return 0;
}