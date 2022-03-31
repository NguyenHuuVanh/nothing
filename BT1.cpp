#include <iostream>
#include <string.h>
using namespace std;

class KH
{
private:
    char ht[30];
    struct NS
    {
        int ngay, thang, nam;
        void Nhap()
        {
            cout << "Nhap ngay thang nam sinh(dd/mm/yyyy):";
            cin >> ngay >> thang >> nam;
        }
        void xuat()
        {
            cout << ngay << "/" << thang << "/" << nam;
        }
    };
    char cmt[10];

public:
    char k[50];
    KH()
    {
        this->ht[30] = ' ';
        this->cmt[10] = ' ';
        this->k[50] = ' ';
    }
    ~KH() {}

    friend istream &operator>>(istream &is, KH &a)
    {
        NS b;
        cin.ignore();
        cout << "Nhap ho ten:";
        gets(a.ht);
        b.Nhap();
        // cin.ignore();
        cout << "Nhap chung minh thu:";
        cin >> a.cmt[10];
        // cin.ignore();
        cout << "Nhap ho khau:";
        gets(a.k);
        return is;
    }
    friend ostream &operator<<(ostream &os, KH a)
    {
        NS b;
        cout << "Ho ten:" << a.ht[30] << endl;
        b.xuat();
        cout << "Chung minh thu:" << a.cmt[10] << endl;
        cout << "So ho khau:" << a.k[50] << endl;
        return os;
    }

    friend NS operator>(NS a, NS b)
    {
        if (a.nam > b.nam)
        {
            return a;
        }
        return b;
    }
    bool operator==(const KH a)
    {
        if ((a.k) == "Ha Noi")
        {
            cout << a;
        }
        return a.k;
    }
};

void Thongtinkhachhang()
{
    int n, key;
    bool danhap = false;
    do
    {
        cout << "Nhap so luong khach hang: ";
        cin >> n;
    } while (n <= 0);
    KH a[n];

    while (true)
    {
        cout << "\n";
        cout << "*****************************************************************************" << endl;
        cout << "**      CHUONG TRINH QUAN LY KHACH HANG                                    **" << endl;
        cout << "**        1.Nhap du lieu                                                   **" << endl;
        cout << "**        2.In danh sach khach hang                                        **" << endl;
        cout << "**        3.In danh sach khach hang co ho khau ha noi                      **" << endl;
        cout << "**        4.Danh sach khach hang đa sap xap theo thu tu giam dan cua tuoi  **" << endl;
        cout << "**        0.Thoat                                                          **" << endl;
        cout << "*****************************************************************************" << endl;
        cout << "**           Nhap lua chon cua ban:                                        **" << endl;
        cin >> key;

        switch (key)
        {
        case 1:
            cout << "Ban da chon nhap danh sach khach hang!" << endl;

            for (int i = 0; i < n; i++)
            {
                cout << "Thong tin khach hang thu " << i + 1 << endl;
                cin >> a[i];
            }
            danhap = true;
            cout << "Nhap phim bat ki de tiep tuc!" << endl;
            system("pause");
            break;
        case 2:
            if (danhap)
            {
                cout << "\nBan da chon xuat danh sach khach hang!";
                for (int i = 0; i < n; i++)
                {
                    cout << a[i];
                }
            }
            else
            {
                cout << "\nNhap danh sach khach hang truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");
        case 3:
            if (danhap)
            {
                cout << "Danh sach khach hang co ho khau ha noi" << endl;
                for (int i = 0; i < n; i++)
                {

                    if (a[i].k)
                    {
                        cout << a;
                    }
                }
            }
            else
            {
                cout << "\nNhap danh sach khach hang truoc!";
            }
            cout << "\nNhap phim bat ki de tiep tuc!\n"
                 << endl;
            system("pause");

        case 0:
            cout << "\nBan da chon thoat chuong trinh!";
            system("pause");
            exit;

        default:
            cout << "\nKhong co chuc nang nay!";
            cout << "\nBam phim bat ky de tiep tuc!\n";
            system("pause");
            break;
        }
    }
}

int main()
{
    Thongtinkhachhang();
}