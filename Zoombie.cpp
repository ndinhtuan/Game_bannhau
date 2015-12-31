#include "Zoombie.h"
#include "TrangTri.h"
#include <iostream>
#include <time.h>
#include <conio.h>
#include <Windows.h>

Zoombie::Zoombie()
{
	zoom.x = XMAX - 4;
	zoom.y = (YMAX + YMIN) / 2;
	life = SONG;
}


Zoombie::~Zoombie()
{
}

void Zoombie::veZoom(){
	if (life == SONG){
		textcolor(9);
		gotoxy(zoom.x, zoom.y);
		std::cout << char(CHR);

		textcolor(7);



		gotoxy(zoom.x, zoom.y - 1);
		std::cout << char(CHR);

		gotoxy(zoom.x, zoom.y + 1);
		std::cout << char(CHR);
	}
}

void Zoombie::xoaZoom(){
		gotoxy(zoom.x, zoom.y);
		std::cout << " ";

		textcolor(7);



		gotoxy(zoom.x, zoom.y - 1);
		std::cout << " ";

		gotoxy(zoom.x, zoom.y + 1);
		std::cout << " ";
}

void Zoombie::no(KhungLong& kl){
	ToaDo dan = kl.getDan();
	if (dan.x == zoom.x && dan.y == zoom.y){
		xoaZoom();
		life = CHET;
		kl.tangDiem();
		xoaZoom();
	}

	
}

void Zoombie::setZoom(int x, int y){
	zoom.x = x;
	zoom.y = y;
}

void Zoombie::move(){
	Sleep(40);
	xoaZoom();
	if (life == SONG){
		if (zoom.x <= XMIN + 2){
			life = CHET;
			xoaZoom();
			
		}
		else{
			srand((unsigned int)time(NULL));
			int h = rand() % 2;
			if (h == 1){
				zoom.x--;
			}
			else{
				int flag = 0;
				if (zoom.y > YMIN + 4){
					flag = 1;
					zoom.x--;
					zoom.y--;
				}
				if(flag){
					int k = rand() % 2;
					if (k){
						zoom.y++;
						zoom.x--;
					}
					else{
						zoom.x--;
					}
				}
			}
		}
	}
	
}

bool Zoombie::getLife(){
	return life;
}
