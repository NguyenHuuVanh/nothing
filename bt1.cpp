#include <iostream>
using namespace std;
#define MAX 100

void input_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]= ";
        cin >> arr[i];
    }
}

void output_Array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "]=" << arr[i] << endl;
    }
}

int phandonvi(int a)
{
    int hangdonvi = a % 10;
    return hangdonvi;
}
int phanchuc(int a)
{
    int hangdonvi = a / 10;
    int hangchuc = hangdonvi % 10;
    return hangchuc;
}
int phantram(int a)
{
    int hangtram = a / 100;
    return hangtram;
}

void sapxep(int arr[], int n)
{

    int tmp; // dùng Bubble sort
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (phandonvi(arr[j]) == phandonvi(arr[i]))
            {
                if (phanchuc(arr[j]) == phanchuc(arr[i]))
                {
                    if (phantram(arr[j]) < phantram(arr[i]))
                    {
                        tmp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = tmp;
                    }
                }
                else if (phanchuc(arr[j]) < phanchuc(arr[i]))
                {
                    tmp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = tmp;
                }
            }
            else if (phandonvi(arr[j]) < phandonvi(arr[i]))
            {
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main()
{
    int n, arr[MAX], m, brr[MAX];
    do
    {
        cout << "Enter value n: ";
        cin >> n;
    } while (n < 1 || n > MAX);
    cout << "----------Nhap vao mang------------" << endl;
    input_Array(arr, n);
    cout << "----------xuat mang--------------" << endl;
    output_Array(arr, n);
    cout << "----------xuat mang sau sap xep--------------" << endl;
    sapxep(arr, n);
    output_Array(arr, n);
}
