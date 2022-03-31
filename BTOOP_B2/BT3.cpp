#include <iostream>
using namespace std;

class Dathuc3
{
private:
    int a, b, c, d;

public:
    Dathuc3()
    {
        this->a = 0;
        this->b = 0;
        this->c = 0;
        this->d = 0;
    }
    ~Dathuc3() {}
    friend istream &operator>>(istream &is, Dathuc3 &k)
    {
        cout << "Nhap he so bac 3:";
        cin >> k.a;
        cout << "Nhap he so bac 2:";
        cin >> k.b;
        cout << "Nhap he so bac 1:";
        cin >> k.c;
        cout << "Nhap he so bac 0:";
        cin >> k.d;
        return is;
    }
    friend ostream &operator<<(ostream &os, Dathuc3 k)
    {
        cout << k.a << "x^3 + " << k.b << "x^2 + " << k.c << "x + " << k.d;
        return os;
    }
    friend Dathuc3 operator+(const Dathuc3 a, const Dathuc3 b)
    {
        Dathuc3 c;
        c.a = a.a + b.a;
        c.b = a.b + b.b;
        c.c = a.c + b.c;
        c.d = a.d + b.d;
        return c;
    }
    friend Dathuc3 operator-(const Dathuc3 &a, const Dathuc3 &b)
    {
        Dathuc3 c;
        c.a = a.a - b.a;
        c.b = a.b - b.b;
        c.c = a.c - b.c;
        c.d = a.d - b.d;
        return c;
    }
};

void Dathucbac3()
{
    Dathuc3 a[2], b[2], c[2];
    for (int i = 0; i < 2; i++)
    {
        cout << "Nhap he so da thuc thu " << i + 1 << " la: " << endl;
        cin >> a[i];
    }
    for (int i = 0; i < 2; i++)
    {
        cout << "\nDa thuc thu " << i + 1 << " la: ";
        cout << a[i];
    }
    cout << "\nTong hai da thuc la: ";
    c[2] = a[2] + b[2];
    cout << c[2];
    cout << "\nHieu hai da thuc la: ";
    c[2] = a[2] - b[2];
    cout << c[2];
}

int main()
{
    Dathucbac3();
}
