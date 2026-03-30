#pragma once

class SoPhuc
{
private:
	double iThuc; // Phần thực của số phức
	double iAo;   // Phần ảo của số phức

public:
	// Nhập phần thực và ảo từ bàn phím với tên gợi nhớ (a, b...)
	void Nhap(char ten);

	// Xuất số phức ra màn hình theo định dạng chuẩn (a + bi)
	void Xuat();

	// Trả về kết quả cộng đối tượng hiện tại với số phức sp
	SoPhuc TinhTong(SoPhuc sp);

	// Trả về kết quả trừ đối tượng hiện tại với số phức sp
	SoPhuc TinhHieu(SoPhuc sp);

	// Trả về kết quả nhân đối tượng hiện tại với số phức sp
	SoPhuc TinhTich(SoPhuc sp);

	// Tính thương và lưu vào biến tham chiếu 'thuong'. Trả về false nếu mẫu bằng 0
	bool TinhThuong(SoPhuc sp, SoPhuc& thuong);
};