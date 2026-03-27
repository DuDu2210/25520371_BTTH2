#pragma once
class SoPhuc
{
private:
	double iThuc;
	double iAo;
public:
	void Nhap(char ten);
	void Xuat();
	SoPhuc TinhTong(SoPhuc sp);
	SoPhuc TinhHieu(SoPhuc sp);
	SoPhuc TinhTich(SoPhuc sp);
	bool TinhThuong(SoPhuc sp, SoPhuc &thuong);
};