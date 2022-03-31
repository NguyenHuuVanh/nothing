#include <iostream>
using namespace std;

class GV
{
private:
    char ht[30], bc[15], cn[20];
    int t;
    float bl;

public:
    GV()
    {
        this->ht[30] = ' ';
        this->bc[15] = ' ';
        this->cn[20] = ' ';
        this->t = 0;
        this->bl = 0;
    }
    ~GV() {}
    friend istream &operator>>(istream &is, GV &a)
    {
        cin.ignore();
        cout << "Nhap ho ten:";
        gets(a.ht);
        cout << "Nhap tuoi:";
        cin >> a.t;
        cin.ignore();
        cout << "Nhap chuyen nganh:";
        gets(a.cn);
        cout << "Nhap bang cap(gioi/kha):";
        gets(a.bc);
        cout << "Nhap bac luong:";
        cin >> a.bl;
        return is;
    }
    friend ostream &operator<<(ostream &os, GV a)
    {

        cout << "Ho ten:" << a.ht << endl;
        cout << "Tuoi:" << a.t << endl;
        cout << "Chuyen nganh:" << a.cn << endl;
        cout << "Bang cap:" << a.bc << endl;
        cout << "Bac luong:" << a.bl << endl;
        cout << "So tien luong:" << a.tienluong(a) << "000vnd" << endl;
        return os;
    }

    float tienluong(GV &a)
    {
        return a.bl * 610;
    }
    friend bool operator==(const GV &a, const GV &b)
    {

        if (a.bc == b.bc)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    friend bool operator>(const GV &a, const GV &b)
    {

        if (a.bl > b.bl)
        {
            return true;
        }
        return false;
    }

    friend void sapxep(GV a[], int n);
};

void sapxep(GV a[], int n)
{

    GV tmp; // dùng Bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i].bl > a[j].bl)
            {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void ThongTinGiaoVien()
{
    int n;
    do
    {
        cout << "Nhap so luong giao vien: ";
        cin >> n;
    } while (n <= 0);
    GV a[n];
    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Nhap thong tin giao vien thu " << i + 1 << endl;
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Thong tin giao vien thu " << i + 1 << endl;
        cout << a[i];
    }
    cout << "--------------------------------------------------" << endl;
    cout << "Danh sach giao vien sap xep theo bang cap" << endl;
    sapxep(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << "--------------------------------------------------" << endl;
        cout << "Thong tin giao vien thu " << i + 1 << endl;
        cout << a[i];
    }
}

int main()
{
    ThongTinGiaoVien();
}