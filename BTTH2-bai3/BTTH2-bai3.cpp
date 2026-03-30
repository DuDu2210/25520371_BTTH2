// BTTH2-bai3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SoPhuc.h"

using namespace std;

int main()
{
	SoPhuc a, b;

	// Nhập dữ liệu cho hai số phức a và b
	a.Nhap('a');
	b.Nhap('b');

	// Thực hiện và xuất kết quả phép cộng
	SoPhuc tong = a.TinhTong(b);
	cout << "Tong: ";
	tong.Xuat();

	// Thực hiện và xuất kết quả phép trừ
	SoPhuc hieu = a.TinhHieu(b);
	cout << "Hieu: ";
	hieu.Xuat();

	// Thực hiện và xuất kết quả phép nhân
	SoPhuc tich = a.TinhTich(b);
	cout << "Tich: ";
	tich.Xuat();

	// Thực hiện phép chia (có kiểm tra điều kiện mẫu số khác 0)
	SoPhuc thuong;
	if (a.TinhThuong(b, thuong))
	{
		cout << "Thuong: ";
		thuong.Xuat();
	}
	else
	{
		cout << "Khong the chia cho 0 + 0i" << endl;
	}
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
