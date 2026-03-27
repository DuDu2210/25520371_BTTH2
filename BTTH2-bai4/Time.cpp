#include "Time.h"
#include <iostream>
using namespace std;

void Time::Nhap()
{
	cout << "Nhap gio: ";
	cin >> iGio;
	cout << "Nhap phut: ";
	cin >> iPhut;
	cout << "Nhap giay: ";
	cin >> iGiay;
}

void Time::Xuat()
{
	cout << iGio << " gio " << iPhut << " phut " << iGiay << " giay" << endl;
}

Time Time::TinhCongThemMotGiay()
{
	Time t;
	t.iGio = iGio;
	t.iPhut = iPhut;
	t.iGiay = iGiay + 1;
	if (t.iGiay == 60)
	{
		t.iGiay = 0;
		t.iPhut++;
	}
	if (t.iPhut == 60)
	{
		t.iPhut = 0;
		t.iGio++;
	}
	if (t.iGio == 24)
	{
		t.iGio = 0;
	}
	return t;
}