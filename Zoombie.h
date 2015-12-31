#pragma once
#include "KhungLong.h"


enum {SONG = 0, CHET};

class Zoombie
{
private:
	ToaDo zoom;
	bool life;
public:
	Zoombie();
	~Zoombie();
	void veZoom();
	void xoaZoom();
	void no(KhungLong& kl); // se no khi cham dan
	void setZoom(int x, int y);
	void move();
	ToaDo getZoom(){
		return zoom;
	}
	bool getLife();
};

