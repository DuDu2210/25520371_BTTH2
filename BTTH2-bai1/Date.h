#pragma once

class Date
{
private:
	int iNgay;
	int iThang;
	int iNam;
	bool KiemTraNamNhuan();
	int TinhSoNgayTrongThang();

public:
	// Khởi tạo mặc định: 1/1/2000
	Date();


	// Nhập ngày, tháng, năm từ bàn phím
	bool Nhap();

	// In ra ngày kế tiếp (nếu hợp lệ)
	void Xuat();

	// Tính ngày tiếp theo
	void NgayThangNamTiepTheo();
};