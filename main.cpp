#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
//#include <winbgim.h> 
#include "mylib.h"
#include "data.h"
#include <graphics.h>
using namespace std;
void DDALine(int x1,int y1,int x2,int y2,int c); // ve doan thang
void vetoado();
void menu();
void cuong();
void Elipse(int x_center,int y_center,int a,int b,int color);
void put5pixel(int x,int y);
void MidPoint(int x1,int y1,int x2,int y2);
void Dung()
{
	cout <<"DUng";
}
void put5pixel(int x,int y)
{
	int x1,x2,y1,y2;
	x1=(x/5)*5;y1=(y/5)*5;
	x2=x1+5;y2=y1+5;
	setfillstyle(1,0);				
	bar(x1,y1,x2,y2);
}
void cuong() {
	int x, y,diem=0;
	int d1x,d1y;
	int x1,y1,x2,y2;
	while (1) {
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			diem++;
			if(diem==1)
			{
				d1x=x;
				d1y=y;
			}
			cout << x << " " << y << endl;
<<<<<<< HEAD
=======
			
>>>>>>> 00ad7c5cce8f5135f3f1f8e9482826bf2cdd6c44
			if(x>=TDGOC_X && y>=TDGOC_Y)
			{
				put5pixel(x,y);
			}
			//ve doan thang
			if(diem==2)
			{
				if(d1x>TDGOC_X && x>TDGOC_X)
				{
					//DDALine(d1x,d1y,x,y,3);					
					MidPoint(d1x,d1y,x,y);
					//Elipse(d1x,d1y,x,y,3);
				}
				diem=0;
			}
					
			// xoa nhung gi co tren do thi		
			if(x>=350 && x<=420 && y>=85 && y<=115)
				{
					cleardevice();
					menu();
				}
			
<<<<<<< HEAD

=======
>>>>>>> 00ad7c5cce8f5135f3f1f8e9482826bf2cdd6c44
		}
		delay(0.00001);
	}
	return;
}
// toa do khung ve

int c = 3;
void menu();
void vetoado()
{
	setcolor(3);
	// ve doc
<<<<<<< HEAD
=======

>>>>>>> 00ad7c5cce8f5135f3f1f8e9482826bf2cdd6c44
	for(int i=TDGOC_X+5;i<=TDCUOI_X;i+=5)
	     	{
	    		line(i,TDGOC_Y,i,TDCUOI_Y);
	    	}
<<<<<<< HEAD

=======
>>>>>>> 00ad7c5cce8f5135f3f1f8e9482826bf2cdd6c44
	//ve ngang
	for(int i=TDGOC_Y+5;i<TDCUOI_Y;i+=5)
		{
			line(TDGOC_X+1,i,TDCUOI_X,i);
		}
}




void draw8point(int x,int y,int x0,int y0){ //ve 8 diem doi xung
	putpixel(x0+x,y0+y,c);
	putpixel(x0-x,y0-y,c);
	putpixel(x0+x,y0-y,c);
	putpixel(x0-x,y0+y,c);
	putpixel(x0+y,y0+x,c);
	putpixel(x0-y,y0-x,c);
	putpixel(x0+y,y0-x,c);
	putpixel(x0-y,y0+x,c);
}
void circle_bresenham(int x0,int y0,int r){ //ve duong tron
	int c;
	int x=0, y=r;
	int p=3-2*r;
	for(x;x<=y;x++){
		if(p<0){
			p+=4*x+6;
		}
		else{
			p+=4*(x-y)+10;
			y--;
		}
		draw8point(x,y,x0,y0);
	}
}
// thuat toan ve doan thang DDA
void DDALine(int x1,int y1,int x2,int y2,int c) {
	int x=x1;
	float y=y1;
	float k=(float)abs(y2-y1)/abs(x2-x1);
	//putpixel(x,round(y),c);
	put5pixel(x,y);
	for(int i=x1;i<=x2;i++)
	{
		x++;
		y=y+k;
		//putpixel(x,round(y),c);
		put5pixel(x,y);
	}
}
// Ve duong thang midpoint
void MidPoint(int x1, int y1, int x2, int y2){
	int x, y, dX, dY, p1, p2, absdX, absdY, xE, yE;
	dX = x2 - x1;				//denta x
	dY = y2 - y1;				//denta y
	absdX = fabs(double(dX));	//lay tri tuyet doi denta x
	absdY = fabs(double(dY));	//lay tri tuyet doi denta y
	p1 = 2*absdY - absdX;
	p2 = 2*absdX - absdY;

	int xUnit, yUnit;
	float m = float(dY) / dX;

	if (m < 0) xUnit = yUnit = -1;
	else xUnit = yUnit = 1;

	if (absdY <= absdX){	//ung voi moi gia tri cua x tinh gia tri y
		if (dX >= 0) {	//diem dau(x1,y1) nam ben trai diem cuoi(x2,y2)
			x = x1;		//gan diem dau la diem nam ben trai(x1,y1)
			y = y1;
			xE = x2;	//diem cuoi la diem nam ben phai(x2,y2)
		}
		else {			//diem dau nam ben phai diem cuoi
			x = x2;		//gan diem dau la diem nam ban phai
			y = y2;
			xE = x1;
		}
		put5pixel(x,y);
		for (x; x < xE; x++) {
			if (p1 <= 0) p1 += 2*absdY;
			else {
				y += yUnit;
				p1 += (2*absdY - 2*absdX);
			}
			put5pixel(x,y);
			delay(10);
		}
	}
	else{			
		if (dY >= 0) {
			x = x1;
			y = y1;
			yE = y2;
		}
		else {
			x = x2;
			y = y2;
			yE = y1;
		}
		put5pixel(x,y);
		for (y; y < yE; y++) {
			if (p2 <= 0)	p2 += 2*absdX;
			else{
				x += xUnit;
				p2 += (2*absdX - 2*absdY);
			}
			put5pixel(x,y);
			delay(10);
		}
	}
}

// ve hinh elip

void Ve4diem(int xc,int yc,int x, int y,int color)//ve 4 diem doi xung
{
    put5pixel(xc+x,yc+y);
    put5pixel(xc-x,yc+y);
    put5pixel(xc-x,yc-y);
    put5pixel(xc+x,yc-y);
    //delay(50);
//    putpixel(xc+x,yc+y,color);
//    putpixel(xc-x,yc+y,color);
//    putpixel(xc-x,yc-y,color);
//    putpixel(xc+x,yc-y,color);
}
void Elipse(int x_center,int y_center,int a,int b,int color)// ve elipse
{
    float p,a2,b2;
    int x,y;
    a2=pow(a,2);
    b2=pow(b,2);
    x=0;
    y=b;
     
    p=2*((float)b2/a2)-(2*b)+1;
     
    //ve nhanh thu 1(tu tren xuong )
    while(((float)b2/a2)*x<=y)
    {
        Ve4diem(y_center,y_center,x,y,color);
        if(p<0)
        {
            p=p+2*((float)b2/a2)*(2*x+3);
        }
        else{
            p= p- 4*y + 2*((float)b2/a2)*(2*x+3);
            y--;
        }
        x++;
    }
    //ve nhanh thu 2(tu duoi len )
    y=0;
    x=a;
    p=2*((float)a2/b2)-2*a+1;
    while(((float)a2/b2)*y<=x)
    {
        Ve4diem(y_center,y_center,x,y,color);
        if(p<0)
        {
            p=p +2*((float)a2/b2)*(2*y+3);
        }
        else
        {
            p=p- 4*x + 2*((float)a2/b2)*(2*y+3);
            x=x-1;
        }
        y=y+1;
    }
}
void menu()
{
	setcolor(0);
	rectangle(1,0,450,685);
	rectangle(560,0,1335,685);
	settextstyle(0,0,1);
	setcolor(3);
	int k=10;
	for(int i=0;i<5;i++)
	{
		k+=20;
		outtextxy(455,k,"<<<<(())>>>>");
	}
	
	setcolor(12);
	settextstyle(0,0,2);
	outtextxy(490,170,"KY");
	outtextxy(465,270,"THUAT");
	outtextxy(490,370,"DO");
	outtextxy(480,470,"HOA");
	
	settextstyle(0,0,1);
	setcolor(3);
	k=510;
	for(int i=0;i<5;i++)
	{
		k+=20;
		outtextxy(455,k,"<<<<(())>>>>");
	}
	// tab 2D
	settextstyle(0,0,2);	
	setfillstyle(1,7);
	bar(70,10,200,60);
	outtextxy(87,25,"-+2D+-");
	//tab 3D
	settextstyle(0,0,2);	
	setfillstyle(1,7);
	bar(250,10,380,60);
	outtextxy(267,25,"-+3D+-");
	setcolor(0);
	line(2,70,450,70);
	//nut xoa
	settextstyle(0,0,2);
	setcolor(4);
	rectangle(350,85,420,115);
	outtextxy(365,92,"Xoa");
	// toa do 2D (560,0,1339,685);
	vetoado();

}

int main(){	
//Hieu	
	initwindow(1350,700);
	setbkcolor(15);
	cleardevice();
	setcolor(3);
	menu();
	cuong();
	getch();
}

