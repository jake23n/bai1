// bài 1: cho mảng một chiều các số nguyên a, hãy tạo mảng b từ mảng a, với b[i] là các giá trị là một hoặc hai chữ số ở giữa của a.
#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
using namespace std;

int dodai(int n)
{
	int i = 0;
	if (n == 0) return 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return i;
}
void nhapmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
	cout << endl;
}
void songaunhien(int a[], int n)
{
	random_device rd;
	mt19937 rng(rd());


	uniform_int_distribution<int> uni(1, 25000);
	for (int i = 0; i < n; i++)
	{
		a[i] = uni(rng);
	}
}
void xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = " << a[i] << endl;
	}
	cout << endl;
}
void soogiua(int a[], int n)
{
	int b[1000], kq = 0, c = 0, d = 0;
	for (int i = 0; i < n; i++)
	{
		kq = dodai(a[i]);
		if (kq % 2 == 0)
		{
			c = a[i] / pow(10, kq / 2 - 1);
			b[i] = c % 100;
		}
		else if (kq % 2 == 1)
		{
			c = a[i] / pow(10, kq / 2 );
			b[i] = c % 10;
		}
	}
	xuatmang(b, n);
}
int main()
{
	int a[1000], n = 0;
	cin >> n;
	
	songaunhien(a, n);
	xuatmang(a, n);


	soogiua(a, n);
	
}