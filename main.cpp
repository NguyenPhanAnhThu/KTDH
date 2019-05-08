/* 
graphics in Dev-C++ - nguyenvanquan7826 
*/
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <windows.h>
#include <winbgim.h> 
//#include <graphics.h>
using namespace std;
int c = 3;
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
// thua toan ve doan thang DDA
void DDALine(int x1,int y1,int x2,int y2,int c) {
	int x=x1;
	float y=y1;
	float k=(float)(y2-y1)/(x2-x1);
	putpixel(x,round(y),c);
	for(int i=x1;i<=x2;i++)
	{
		x++;
		y=y+k;
		putpixel(x,round(y),c);
	}
}

// ve hinh elip

void Ve4diem(int xc,int yc,int x, int y,int color)//ve 4 diem doi xung
{
    putpixel(xc+x,yc+y,color);
    putpixel(xc-x,yc+y,color);
    putpixel(xc-x,yc-y,color);
    putpixel(xc+x,yc-y,color);
    //delay(50);
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
int main(){
	initwindow(1028,700);
//	int x,y,r;
//	printf("Nhap tam va ban kinh duong tron: \n R= ");
//	scanf("%d",&r);
//	printf("Tam duong tron: \n x= ");
//	scanf("%d",&x);
//	printf("\n y= ");
//	scanf("%d",&y);
//	circle_bresenham(x,y,r); //ve duong tron
//	DDALine(10,10,200,100,3); //ve doan thang
//  cout<<"\nNhap toa do tam Elip \nx: "; cin>>x;
//  cout<<"\ny: "; cin>>y;
//  Elipse(x,y,200,100,c);// ve elip
    rectangle(300,50,900,600);
    setcolor(3);
    line(305,301,888,303);
    outtextxy(890,298,">");
    outtextxy(596,53,"^");
    settextjustify(0,2);
    line(600,59,600,595);
    //outtextxy(54,590,"^");
	getch();
}
//int main(int argc, char *argv[])
//{
//	// now, you can run project
//	initwindow(300, 300);			// init window graphics
//	setbkcolor(1);					// set background
//   	cleardevice();
//	setcolor(14);					// set text color
//	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
//	
//	while(!kbhit()) delay(1);		// pause screen	
//	return 0;
//}
