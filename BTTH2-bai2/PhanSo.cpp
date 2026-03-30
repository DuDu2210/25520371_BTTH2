#include "PhanSo.h"
#include <iostream>
#include <cmath>
using namespace std;

// Nhập tử và mẫu (có kiểm tra input)
void PhanSo::Nhap(char ten)
{
	// Nhập tử
	cout << "Nhap tu so " << ten << ": ";
	cin >> iTu;

	while (cin.fail())
	{
		cout << "Nhap khong hop le, vui long nhap lai: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> iTu;
	}
	cout << endl;

	// Nhập mẫu
	cout << "Nhap mau so " << ten << ": ";
	cin >> iMau;

	while (cin.fail() || iMau == 0)
	{
		cout << "Nhap khong hop le (mau != 0), vui long nhap lai: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> iMau;
	}
	cout << endl;
}

// Xuất phân số (rút gọn hiển thị)
void PhanSo::Xuat()
{
	if (iMau == 1)
		cout << iTu << endl;
	else if (iTu == 0)
		cout << 0 << endl;
	else
		cout << iTu << "/" << iMau << endl;
}

// Rút gọn phân số bằng thuật toán Euclid
void PhanSo::RutGon()
{
	int a = abs(iTu);
	int b = abs(iMau);

	// Tìm UCLN
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}

	iTu /= a;
	iMau /= a;

	// Đưa dấu âm lên tử
	if (iMau < 0)
	{
		iTu = -iTu;
		iMau = -iMau;
	}
}

// Tính tổng: a/b + c/d = (ad + bc) / bd
PhanSo PhanSo::TinhTong(PhanSo ps)
{
	PhanSo tong;
	tong.iTu = iTu * ps.iMau + ps.iTu * iMau;
	tong.iMau = iMau * ps.iMau;
	tong.RutGon();
	return tong;
}

// Tính hiệu: a/b - c/d
PhanSo PhanSo::TinhHieu(PhanSo ps)
{
	PhanSo hieu;
	hieu.iTu = iTu * ps.iMau - ps.iTu * iMau;
	hieu.iMau = iMau * ps.iMau;
	hieu.RutGon();
	return hieu;
}

// Tính tích: a/b * c/d
PhanSo PhanSo::TinhTich(PhanSo ps)
{
	PhanSo tich;
	tich.iTu = iTu * ps.iTu;
	tich.iMau = iMau * ps.iMau;
	tich.RutGon();
	return tich;
}

// Tính thương (có kiểm tra chia cho 0)
bool PhanSo::TinhThuong(PhanSo ps, PhanSo& kq)
{
	if (ps.iTu == 0)
	{
		cout << "Khong the chia cho phan so co tu = 0!" << endl;
		return false;
	}

	kq.iTu = iTu * ps.iMau;
	kq.iMau = iMau * ps.iTu;
	kq.RutGon();
	return true;
}

// So sánh 2 phân số bằng nhân chéo
void PhanSo::SoSanh(PhanSo ps)
{
	int a = iTu * ps.iMau;
	int b = ps.iTu * iMau;

	if (a > b)
		cout << "Phan so 1 lon hon phan so 2" << endl;
	else if (a < b)
		cout << "Phan so 1 nho hon phan so 2" << endl;
	else
		cout << "Hai phan so bang nhau" << endl;
}