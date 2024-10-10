#include<bits/stdc++.h>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {
    }

    double getReal() { 
        return real; 
    }

    double getImag() { 
        return imag; 
    }

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag,
                       real * other.imag + imag * other.real);
    }

    Complex operator/(const Complex &other) const {
        double x = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / x,
                       (imag * other.real - real * other.imag) / x);
    }

    bool operator==(const Complex &other) const {
        return (real == other.real && imag == other.imag);
    }

    friend ostream &operator<<(ostream &os, const Complex &c) {
        if (c.imag >= 0)
            os << c.real << " + " << c.imag << "i";
        else
            os << c.real << " - " << -c.imag << "i";
        return os;
    }

    friend istream &operator>>(istream &is, Complex &c) {
        cout << "Nhap phan thuc: ";
        is >> c.real;
        cout << "Nhap phan ao: ";
        is >> c.imag;
        return is;
    }
};

int main() {
    Complex c1, c2, result;

    cout << "Nhap so phuc dau tien:" << endl;
    cin >> c1;
    cout << "Nhap so phuc thu 2" << endl;
    cin >> c2;

    result = c1 + c2;
    cout << "Tong la: " << result << endl;

    result = c1 - c2;
    cout << "Hieu la: " << result << endl;

    result = c1 * c2;
    cout << "Tich la: " << result << endl;

    result = c1 / c2;
    cout << "Thuong la: " << result << endl;

    if (c1 == c2)
        cout << "Hai so phuc bang nhau" << endl;
    else
        cout << "Hai so phuc khong bang nhau" << endl;

    return 0;
}
