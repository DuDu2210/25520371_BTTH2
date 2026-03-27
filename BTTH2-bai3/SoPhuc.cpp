#include "SoPhuc.h"
#include <iostream>
using namespace std;

void SoPhuc::Nhap(char ten)
{
	cout << "Nhap phan thuc " << ten << ": ";
	cin >> iThuc;
	cout << "Nhap phan ao " << ten << ": ";
	cin >> iAo;
}

void SoPhuc::Xuat()
{
	if (iThuc == 0 && iAo == 0)
	{
		cout << "0" << endl;
		return;
	}
	else if (iThuc == 0)
	{
		cout << iAo << "i" << endl;
		return;
	}
	else if (iAo == 0)
	{
		cout << iThuc << endl;
		return;
	}
	else 
	{
		cout << iThuc;
		if (iAo > 0)
			cout << " + " << iAo << "i" << endl;
		else
			cout << " - " << -iAo << "i" << endl;
	}
}

SoPhuc SoPhuc::TinhTong(SoPhuc sp)
{
	SoPhuc tong;
	tong.iThuc = iThuc + sp.iThuc;
	tong.iAo = iAo + sp.iAo;
	return tong;
}

SoPhuc SoPhuc::TinhHieu(SoPhuc sp)
{
	SoPhuc hieu;
	hieu.iThuc = iThuc - sp.iThuc;
	hieu.iAo = iAo - sp.iAo;
	return hieu;
}

SoPhuc SoPhuc::TinhTich(SoPhuc sp)
{
	SoPhuc tich;
	tich.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
	tich.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
	return tich;
}

bool SoPhuc::TinhThuong(SoPhuc sp, SoPhuc &thuong)
{
	if (sp.iThuc == 0 && sp.iAo == 0) return false;
	
	double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
	thuong.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
	thuong.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;
	return true;
}