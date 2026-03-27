#pragma once
#include <iostream>
using namespace std;

class Date
{
	private:
		int iNgay;
		int iThang;
		int iNam;

public:
	Date();

	void Nhap();
	void Xuat();
	void NgayThangNamTiepTheo();
};

