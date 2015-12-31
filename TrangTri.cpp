#pragma once
#include "TrangTri.h"
#include <Windows.h>
#include <iostream>
#include "KhungLong.h"

TrangTri::TrangTri()
{
}


TrangTri::~TrangTri()
{
}

void TrangTri::ve(){
	resizeConsole(800, 600);
	SetConsoleTitle("Programmer : Nguyen Dinh Tuan - theiron1997@gmail.com");
	textcolor(12);

	for (int i = 1; i <= XLENGTH; i++){
		gotoxy(i, YMIN);
		std::cout << char(CHR);
		gotoxy(i, YMAX);
		std::cout << char(CHR);
	}
	textcolor(7);
}
