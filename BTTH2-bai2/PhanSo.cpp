#include "PhanSo.h"
#include <iostream>
using namespace std;
	
void PhanSo::Nhap(char ten)
{
	cout << "Nhap tu so " << ten << ": ";
	cin >> iTu; cout << endl;
	cout << "Nhap mau so " << ten << ": ";
	cin >> iMau; cout << endl;
	while (iMau == 0)
	{
		cout << "Mau so khong duoc bang 0, vui long nhap lai: ";
		cin >> iMau; cout << endl;
	} 
}

void PhanSo::Xuat()
{
	cout << iTu << "/" << iMau << endl;
}

void PhanSo::RutGon()
{
	int a = iTu, b = iMau;
	while (b != 0)
	{
		int temp = b;
		b = a % b;
		a = temp;
	}
	iTu /= a;
	iMau /= a;
	if (iMau < 0)
	{
		iTu = -iTu;
		iMau = -iMau;
	}
}

PhanSo PhanSo::TinhTong(PhanSo ps)
{
	PhanSo tong;
	tong.iTu = iTu * ps.iMau + ps.iTu * iMau;
	tong.iMau = iMau * ps.iMau;
	tong.RutGon();
	return tong;
}

PhanSo PhanSo::TinhHieu(PhanSo ps)
{
	PhanSo hieu;
	hieu.iTu = iTu * ps.iMau - ps.iTu * iMau;
	hieu.iMau = iMau * ps.iMau;
	hieu.RutGon();
	return hieu;
}

PhanSo PhanSo::TinhTich(PhanSo ps)
{
	PhanSo tich;
	tich.iTu = iTu * ps.iTu;
	tich.iMau = iMau * ps.iMau;
	tich.RutGon();
	return tich;
}

PhanSo PhanSo::TinhThuong(PhanSo ps)
{
	PhanSo thuong;
	thuong.iTu = iTu * ps.iMau;
	thuong.iMau = iMau * ps.iTu;
	thuong.RutGon();
	return thuong;
}

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