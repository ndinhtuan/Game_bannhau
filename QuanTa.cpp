#include "KhungLong.h"
#include "TrangTri.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Zoombie.h"

// Hàm thay đổi kích cỡ của khung cmd.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm dịch chuyển con trỏ đến tọa độ x, y.
void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1, y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

KhungLong::KhungLong()
{
	Coord.x = 10;
	Coord.y = 24;

	dan.x = dan.y = 0;
	life = true;
	diem = 0;
}


KhungLong::~KhungLong()
{
}

void KhungLong::ve(){
	textcolor(14);
	gotoxy(Coord.x, Coord.y);
	std::cout << char(16);
	gotoxy(Coord.x - 4, Coord.y);
	std::cout << char(CHR);
	gotoxy(Coord.x - 3, Coord.y);
	std::cout << char(CHR);
	gotoxy(Coord.x - 2, Coord.y);
	std::cout << char(CHR);
	gotoxy(Coord.x - 1, Coord.y);
	std::cout << char(CHR);
	gotoxy(Coord.x - 4, Coord.y+1);
	std::cout << char(CHR);
	gotoxy(Coord.x - 3, Coord.y+1);
	std::cout << char(CHR);
	gotoxy(Coord.x - 2, Coord.y+1);
	std::cout << char(CHR);
	gotoxy(Coord.x - 1, Coord.y+1);
	std::cout << char(CHR);
	
	gotoxy(Coord.x-2, Coord.y+2);
	std::cout << char(CHR);
	gotoxy(Coord.x-2, Coord.y + 3);
	std::cout << char(CHR);
	gotoxy(Coord.x-2, Coord.y + 4);
	std::cout << char(CHR);

	gotoxy(Coord.x - 3, Coord.y + 4);
	std::cout << char(CHR);
	gotoxy(Coord.x - 4, Coord.y + 4);
	std::cout << char(CHR);
	gotoxy(Coord.x-1, Coord.y + 4);
	std::cout << char(CHR);
	gotoxy(Coord.x, Coord.y + 4);
	std::cout << char(CHR);
}

void KhungLong::setToaDo(int x, int y){
	Coord.x = x;
	Coord.y = y;
}

void KhungLong::move(){
	
	if (!_kbhit()){
	}
	else{
		//_getch();
		clsOld();

		if (GetAsyncKeyState(VK_UP) && Coord.y > YMIN + 1){
			Coord.y--;
		}

		if (GetAsyncKeyState(VK_DOWN) && Coord.y < YMAX - HEIGHT - 1){
			Coord.y++;
		}

		if (GetAsyncKeyState(VK_LEFT) && Coord.x > XMIN + 4){
			Coord.x--;
		}

		if (GetAsyncKeyState(VK_RIGHT) && Coord.x < XMAX){
			Coord.x++;
		}

		ve();
		Sleep(20);
	}
}

void KhungLong::clsOld(){
	gotoxy(Coord.x, Coord.y);
	std::cout << " ";
	gotoxy(Coord.x - 4, Coord.y);
	std::cout << " ";
	gotoxy(Coord.x - 3, Coord.y);
	std::cout << " ";
	gotoxy(Coord.x - 2, Coord.y);
	std::cout << " ";
	gotoxy(Coord.x - 1, Coord.y);
	std::cout << " ";
	gotoxy(Coord.x - 4, Coord.y + 1);
	std::cout << " ";
	gotoxy(Coord.x - 3, Coord.y + 1);
	std::cout << " ";
	gotoxy(Coord.x - 2, Coord.y + 1);
	std::cout << " ";
	gotoxy(Coord.x - 1, Coord.y + 1);
	std::cout << " ";

	gotoxy(Coord.x - 2, Coord.y + 2);
	std::cout << " ";
	gotoxy(Coord.x - 2, Coord.y + 3);
	std::cout << " ";
	gotoxy(Coord.x - 2, Coord.y + 4);
	std::cout << " ";

	gotoxy(Coord.x - 3, Coord.y + 4);
	std::cout << " ";
	gotoxy(Coord.x - 4, Coord.y + 4);
	std::cout << " ";
	gotoxy(Coord.x - 1, Coord.y + 4);
	std::cout << " ";
	gotoxy(Coord.x, Coord.y + 4);
	std::cout << " ";
}

void xoaDan(ToaDo dan){
	gotoxy(dan.x, dan.y);
	std::cout << " ";
}

void veDan(ToaDo dan){
	textcolor(5);
	gotoxy(dan.x, dan.y);
	std::cout << char(16);
}

void KhungLong::banDan(){
	if (dan.x != 0 || dan.y != 0){
		xoaDan(dan);
	}
	if (!_kbhit()){
		if (dan.x != 0 || dan.y != 0){
			dan.x++;
		}
	}
	else{
		if (GetAsyncKeyState(32)){
			if (dan.x == 0 && dan.y == 0){
				dan.x = Coord.x;
				dan.y = Coord.y;
				dan.x++;
			}
		}
		else{
			if (dan.x != 0 || dan.y != 0){
				dan.x++;
			}
		}
	}
	if (dan.x > XMAX){
		xoaDan(dan);
		dan.x = dan.y = 0;
	}
	if (dan.x != 0 || dan.y != 0){
		veDan(dan);
		//_getch();
	}
	//Sleep(50);
}

void KhungLong::chet(ToaDo toaDoZoom){
	//ToaDo toaDoZoom = zoom.getZoom();
	if (toaDoZoom.x == Coord.x && toaDoZoom.y == Coord.y){
		life = false;
	}
	if (toaDoZoom.x == Coord.x && toaDoZoom.y == Coord.y + 1){
		life = false;
	}
	if (toaDoZoom.x == Coord.x && toaDoZoom.y == Coord.y - 1){
		life = false;
	}
	if (toaDoZoom.x == Coord.x -1 && toaDoZoom.y == Coord.y -1){
		life = false;
	}

	if (!life){
		textcolor(4);
		std::cout << "GAME OVER !";
		std::cin.ignore();
		exit(1);
	}
}
