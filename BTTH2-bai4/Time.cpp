#include "Time.h"
#include <iostream>
using namespace std;

void Time::Nhap()
{
	// 1. Nhập và kiểm tra Giờ
	cout << "Nhap gio : ";
	while (!(cin >> iGio) || iGio < 0 || iGio >= 24)
	{
		cout << "Gio khong hop le! Nhap lai: ";
		cin.clear();           // Reset trạng thái lỗi
		cin.ignore(1000, '\n'); // Xóa bộ nhớ đệm
	}

	// 2. Nhập và kiểm tra Phút
	cout << "Nhap phut: ";
	while (!(cin >> iPhut) || iPhut < 0 || iPhut >= 60)
	{
		cout << "Phut khong hop le! Nhap lai: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}

	// 3. Nhập và kiểm tra Giây
	cout << "Nhap giay: ";
	while (!(cin >> iGiay) || iGiay < 0 || iGiay >= 60)
	{
		cout << "Giay khong hop le! Nhap lai: ";
		cin.clear();
		cin.ignore(1000, '\n');
	}
}

// Xuất thời gian với định dạng 2 chữ số (thêm số 0 phía trước nếu < 10)
void Time::Xuat()
{
	if (iGio < 10) cout << "0";
	cout << iGio << ":";
	if (iPhut < 10) cout << "0";
	cout << iPhut << ":";
	if (iGiay < 10) cout << "0";
	cout << iGiay << endl;
}

// Tính toán cộng thêm 1 giây và xử lý tràn số theo cấp: Giây -> Phút -> Giờ
Time Time::TinhCongThemMotGiay()
{
	Time t;
	t.iGio = iGio;
	t.iPhut = iPhut;
	t.iGiay = iGiay + 1;

	// Xử lý tràn giây sang phút
	if (t.iGiay == 60)
	{
		t.iGiay = 0;
		t.iPhut++;
	}
	// Xử lý tràn phút sang giờ
	if (t.iPhut == 60)
	{
		t.iPhut = 0;
		t.iGio++;
	}
	// Xử lý tràn giờ sang ngày mới (Reset về 0)
	if (t.iGio == 24)
	{
		t.iGio = 0;
	}
	return t;
}