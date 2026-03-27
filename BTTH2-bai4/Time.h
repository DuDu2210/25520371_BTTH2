#pragma once
class Time
{
private:
	int iGio = 0;
	int iPhut = 0;
	int iGiay = 0;
public:
	void Nhap();
	void Xuat();
	Time TinhCongThemMotGiay();
};

