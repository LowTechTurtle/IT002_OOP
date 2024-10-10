#include<bits/stdc++.h>
using namespace std;

class cArray {
private:
    vector<int> arr;

public:
    void input(int n) {
        arr.clear();
        int num;
        cout << "nhap " << n << " phan tu" << endl;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            arr.push_back(num);
        }
    }

    void output() const {
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
    }

    void random(int n, int low = 0, int hi = 100) {
        arr.clear();
        srand(static_cast<unsigned>(std::time(0)));
        for (int i = 0; i < n; ++i) {
            arr.push_back(low + std::rand() % (hi - low + 1));
        }
    }

    int count(int x) const {
        int count = 0;
        for (int num : arr) {
            if (num == x) {
                ++count;
            }
        }
        return count;
    }

    bool isAscending() const {
        for (size_t i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }

    int minOdd() {
        int min = INT_MAX;
        for (int num : arr) {
            if (num % 2 != 0) {
                if (num < min) {
                    min = num;
                }
            }
        }
        return min;
    }

    void sortAscending() {
        std::sort(arr.begin(), arr.end());
    }
};

int main() {
    cArray arr;
    int n, x;

    cout << "Nhap vao so phan tu: ";
    cin >> n;
    arr.input(n);
    cout << "Cac phan tu trong arr la: ";
    arr.output();

    cout << "Xoa array va random " << n << " phan tu:" << endl;
    arr.random(n);
    arr.output();

    cout << "Nhập số cần đếm: ";
    cin >> x;
    cout << x << " xuat hien " << arr.count(x) << " lan" << endl;

    if (arr.isAscending())
        cout << "Day tang dan" << endl;
    else 
        cout << "Day khong tang dan" << endl;

    cout << "Gia tri le nho nhat la :" << arr.minOdd() << endl;

    cout << "sort day tang dan" << endl;
    arr.sortAscending();
    cout << "day moi la: " << endl;
    arr.output();

    return 0;
}
