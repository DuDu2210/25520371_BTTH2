#pragma once

class Time
{
private:
	int iGio = 0;   // Giờ (0-23)
	int iPhut = 0;  // Phút (0-59)
	int iGiay = 0;  // Giây (0-59)

public:
	void Nhap();    // Nhập và kiểm tra tính hợp lệ của thời gian
	void Xuat();    // Xuất thời gian theo định dạng HH:mm:ss
	Time TinhCongThemMotGiay(); // Trả về đối tượng mới sau khi cộng 1 giây
};