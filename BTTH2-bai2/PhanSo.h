#pragma once
class PhanSo
{
private:
	int iTu;
	int iMau;
public:
	void Nhap(char ten);
	void Xuat();
	void RutGon();

	PhanSo TinhTong(PhanSo ps);
	PhanSo TinhHieu(PhanSo ps);
	PhanSo TinhTich(PhanSo ps);
	PhanSo TinhThuong(PhanSo ps);

	void SoSanh(PhanSo ps);
};

