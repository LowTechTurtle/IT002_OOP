#include<bits/stdc++.h>
#include "bai5.h"
using namespace std;

// Kiem tra xem hinh chu nhat w x h co toan la so 1 hay khong
bool checkhcn(vector<vector<int>> matrix, int x, int y, int w, int h, int m, int n) {

    for (int i = y; i < y + h; i++) {
        for (int j = x; j < x + w; j++) {
            if (matrix[i][j] == 0) 
                return false;
            if (i - 1 >= 0 && i == y && matrix[i-1][j] == 1)
                return false;
            if (j - 1 >= 0 && j == x && matrix[i][j-1] == 1)
                return false;
            if (j + w <= m && j == x+w-1 && matrix[i][j+w-1] == 1)
                return false;
            if (i + h <= n && i == y+h-1 && matrix[i+h-1][j] == 1)
                return false;
        }
    }
    return true;
}

//tim tat ca cac hinh chu nhat thoa man de bai
vector<rectangle> solve(vector<vector<int>> matrix, int m, int n) {
    vector<rectangle> rectangles;

    for (int y = 0; y < m - 1; y++) {
        for (int x = 0; x < n - 1; x++) {
            if (matrix[y][x] == 1) { 
                for (int h = 2; y + h <= m; ++h) {
                    for (int w = 2; x + w <= n; ++w) {
                        if (checkhcn(matrix, x, y, w, h, m, n)) {
                            rectangles.push_back({x, y, w, h});
                        }
                    }
                }
            }
        }
    }

    sort(rectangles.begin(), rectangles.end(), sosanh);

    return rectangles;
}

//so sanh de sap xep theo thu tu tu trai sang phai va tren xuong duoi
bool sosanh(rectangle a, rectangle b) {
    if (a.y == b.y) 
        return a.x < b.x;
    return a.y < b.y;
}