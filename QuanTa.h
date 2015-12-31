#pragma once

//#include "Zoombie.h"

#define HEIGHT 4
#define CHR 219

struct ToaDo{
	int x;
	int y;
};
// coord

class KhungLong
{
private:
	ToaDo Coord;
	ToaDo dan;
	bool life;
	int diem;
public:

	KhungLong();
	~KhungLong();
	void ve(); // draw dinosaur.
	void setToaDo(int x, int y);// Set up coord of objet
	void move(); // this function change coord of object pass through press key
	void clsOld(); // clear old image of object
	void banDan(); // ban dan
	ToaDo getDan(){
		return dan;
	}
	void chet(ToaDo toaDoZoom);
	void tangDiem(){
		diem++;
	}
	int getDiem(){
		return diem;
	}
};

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height);

// Hàm tô màu.
void textcolor(int x);

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y);
// Hàm xóa màn hình.
void XoaManHinh();
