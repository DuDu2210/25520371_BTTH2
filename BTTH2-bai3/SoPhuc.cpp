#include "SoPhuc.h"
#include <iostream>
using namespace std;

void SoPhuc::Nhap(char ten)
{
	// Nhập phần thực
	cout << "Nhap phan thuc " << ten << ": ";
	cin >> iThuc;

	while (cin.fail()) // Kiểm tra nếu việc nhập phía trên bị lỗi 
	{
		cout << "Gia tri khong hop le! Vui long nhap lai phan thuc: ";
		cin.clear();           // Xóa trạng thái lỗi (Reset failbit)
		cin.ignore(1000, '\n'); // Xóa ký tự rác còn sót lại trong bộ nhớ đệm
		cin >> iThuc;          // Cho phép nhập lại
	}

	// Nhập phần ảo
	cout << "Nhap phan ao " << ten << ": ";
	cin >> iAo;

	while (cin.fail())
	{
		cout << "Gia tri khong hop le! Vui long nhap lai phan ao: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> iAo;
	}
}

// Xuất số phức theo định dạng chuẩn toán học
void SoPhuc::Xuat()
{
	// Trường hợp số phức bằng 0
	if (iThuc == 0 && iAo == 0)
	{
		cout << "0" << endl;
		return;
	}
	// Chỉ có phần ảo
	else if (iThuc == 0)
	{
		cout << iAo << "i" << endl;
		return;
	}
	// Chỉ có phần thực
	else if (iAo == 0)
	{
		cout << iThuc << endl;
		return;
	}
	// Có cả phần thực và phần ảo
	else
	{
		cout << iThuc;
		if (iAo > 0)
		{
			if (iAo == 1) cout << " + i" << endl; // Ẩn số 1 khi iAo = 1
			else cout << " + " << iAo << "i" << endl;
		}
		else // Trường hợp phần ảo âm
		{
			if (iAo == -1) cout << " - i" << endl; // Ẩn số 1 khi iAo = -1
			else cout << " - " << -iAo << "i" << endl;
		}
	}
}

// Cộng hai số phức: (a + bi) + (c + di) = (a+c) + (b+d)i
SoPhuc SoPhuc::TinhTong(SoPhuc sp)
{
	SoPhuc tong;
	tong.iThuc = iThuc + sp.iThuc;
	tong.iAo = iAo + sp.iAo;
	return tong;
}

// Trừ hai số phức: (a + bi) - (c + di) = (a-c) + (b-d)i
SoPhuc SoPhuc::TinhHieu(SoPhuc sp)
{
	SoPhuc hieu;
	hieu.iThuc = iThuc - sp.iThuc;
	hieu.iAo = iAo - sp.iAo;
	return hieu;
}

// Nhân hai số phức: (a + bi)(c + di) = (ac - bd) + (ad + bc)i
SoPhuc SoPhuc::TinhTich(SoPhuc sp)
{
	SoPhuc tich;
	tich.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
	tich.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
	return tich;
}

// Chia hai số phức bằng cách nhân liên hợp mẫu số
bool SoPhuc::TinhThuong(SoPhuc sp, SoPhuc& thuong)
{
	// Kiểm tra lỗi chia cho số không (mẫu số = 0 + 0i)
	if (sp.iThuc == 0 && sp.iAo == 0) return false;

	double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo; // Tính bình phương module mẫu
	thuong.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
	thuong.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;
	return true;
}