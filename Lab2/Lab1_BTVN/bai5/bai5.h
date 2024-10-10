#include<bits/stdc++.h>
using namespace std;

//luu hinh chu nhat
struct rectangle {
    int x, y, w, h; //toa do x, y, width, height
};

// Kiem tra xem hinh chu nhat w x h co toan la so 1 hay khong
bool checkhcn(vector<vector<int>> matrix, int x, int y, int w, int h);

//tim cac hinh chu nhat thoa man de bai
vector<rectangle> solve(vector<vector<int>> matrix, int m, int n);

bool sosanh(rectangle a, rectangle b);