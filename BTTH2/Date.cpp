#include "Date.h"

Date::Date()
{
	iNgay = 1;
	iThang = 1;
	iNam = 2000;
}

bool KiemTraNamNhuan(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		return true;
	return false;
}

void Date::Nhap()
{
	cout << "Nhap ngay: ";
	cin >> iNgay;
	cout << "Nhap thang: ";
	cin >> iThang;
	cout << "Nhap nam: ";
	cin >> iNam;
}

int TinhSoNgayTrongThang(int m, int y)
{
	switch (m)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30;
	case 2:
		if (KiemTraNamNhuan(y))
			return 29;
		else
			return 28;
	default:
		return -1; // Tháng không hợp lệ
	}
}

bool KiemTraNgayHopLe(int d, int m, int y)
{
	if (m < 1 || m > 12)
		return false;
	int soNgay = TinhSoNgayTrongThang(m, y);
	if (d < 1 || d > soNgay)
		return false;
	return true;
}

void Date::NgayThangNamTiepTheo()
{
	iNgay++;
	int soNgay = TinhSoNgayTrongThang(iThang, iNam);
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

void Date::Xuat()
{
	if (!KiemTraNgayHopLe(iNgay, iThang, iNam))
	{
		cout << "Ngay thang nam khong hop le!" << endl;
		return;
	}
	NgayThangNamTiepTheo();
	cout << "Ngay thang nam tiep theo: ";
	cout << iNgay << "/" << iThang << "/" << iNam << endl;
}