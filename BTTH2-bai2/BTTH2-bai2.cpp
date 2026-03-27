// BTTH2-bai2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo a, b;
	a.Nhap('a');
	b.Nhap('b');
	
	PhanSo tong = a.TinhTong(b);
	cout << "Tong: ";
	tong.Xuat();
	PhanSo hieu = a.TinhHieu(b);
	cout << "Hieu: ";
	hieu.Xuat();
	PhanSo tich = a.TinhTich(b);
	cout << "Tich: ";
	tich.Xuat();
	PhanSo thuong = a.TinhThuong(b);
	cout << "Thuong: ";
	thuong.Xuat();
	a.SoSanh(b);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
