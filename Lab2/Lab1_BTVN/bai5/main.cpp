#include<bits/stdc++.h>
#include "bai5.cpp"
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int>> matrix(m, vector<int>(n));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    
    vector<rectangle> rectangles = solve(matrix, m, n);

    for (auto rect : rectangles) {
        cout << "[" << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << "]\n";
    }

    return 0;
}
