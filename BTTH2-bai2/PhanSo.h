class PhanSo
{
private:
	int iTu;   // tử số
	int iMau;  // mẫu số
	void RutGon(); // rút gọn phân số

public:
	// Nhập phân số
	void Nhap(char ten);

	// Xuất phân số
	void Xuat();

	// Tính tổng 2 phân số
	PhanSo TinhTong(PhanSo ps);

	// Tính hiệu 2 phân số
	PhanSo TinhHieu(PhanSo ps);

	// Tính tích 2 phân số
	PhanSo TinhTich(PhanSo ps);

	// Tính thương 2 phân số
	bool TinhThuong(PhanSo ps, PhanSo &kq);

	// So sánh 2 phân số
	void SoSanh(PhanSo ps);
};