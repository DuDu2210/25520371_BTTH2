#include "Date.h"
#include <iostream>
using namespace std;

// Gán ngày mặc định
Date::Date()
{
	iNgay = 1;
	iThang = 1;
	iNam = 2000;
}

// Kiểm tra năm nhuận
// chia hết 4 & không chia hết 100 hoặc chia hết 400
bool Date::KiemTraNamNhuan()
{
	int y = iNam;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return true;
	return false;
}

// Nhập ngày tháng năm
bool Date::Nhap()
{
	// 1. Nhập và kiểm tra Ngày (Cơ bản)
	cout << "Nhap ngay: ";
	if (!(cin >> iNgay) || iNgay < 1 || iNgay > 31)
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}

	// 2. Nhập và kiểm tra Tháng
	cout << "Nhap thang: ";
	if (!(cin >> iThang) || iThang < 1 || iThang > 12)
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}

	// Kiểm tra các tháng có 30 ngày
	if ((iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11) && iNgay > 30)
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}
	// Kiểm tra sơ bộ tháng 2 (không bao giờ quá 29 ngày)
	if (iThang == 2 && iNgay > 29)
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}

	// 3. Nhập và kiểm tra Năm
	cout << "Nhap nam: ";
	if (!(cin >> iNam) || iNam < 1)
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}

	// Nếu là ngày 29/2 thì bắt buộc năm phải nhuận
	if (iThang == 2 && iNgay == 29 && !KiemTraNamNhuan())
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return false;
	}
	return true;
}

// Trả về số ngày trong tháng
int Date::TinhSoNgayTrongThang()
{
	int m = iThang; 
	int y = iNam;
	switch (m)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		return KiemTraNamNhuan() ? 29 : 28;
	default:
		return -1;
	}
}


// Tăng lên 1 ngày
void Date::NgayThangNamTiepTheo()
{
	iNgay++;
	int soNgay = TinhSoNgayTrongThang();

	if (iNgay > soNgay)
	{
		iNgay = 1;
		iThang++;
		if (iThang > 12)
		{
			iThang = 1;
			iNam++;
		}
	}
}

// Xuất ngày kế tiếp nếu hợp lệ
void Date::Xuat()
{
	NgayThangNamTiepTheo();
	cout << "Ngay thang nam tiep theo: ";
	cout << iNgay << "/" << iThang << "/" << iNam << endl;
}