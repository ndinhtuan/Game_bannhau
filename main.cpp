#include <iostream>
#include "KhungLong.h"
#include "TrangTri.h"
#include "Zoombie.h"

using namespace std;

int main(){
	TrangTri khung;
	khung.ve();
	KhungLong khungLong;
	khungLong.ve(); 
	Zoombie* zoom;
	zoom = new Zoombie;
	do{
		textcolor(7);
		gotoxy(14, 4);
		cout << "Diem : " << khungLong.getDiem();
		khungLong.move();
		khungLong.banDan();
		
		if (! zoom->getLife()){
			zoom->veZoom();
			zoom->no(khungLong);
			zoom->move();
			khungLong.chet(zoom->getZoom());
		}
		else{
			delete zoom;
			zoom = new Zoombie;
		}

		if (khungLong.getDiem() >= 5){
			textcolor(10);
			gotoxy(10, YMAX + 4);
			cout << " HAPPY NEW YEAR !";
			break;
		}
	} while (1);

	cin.ignore();

	return 0;
}
