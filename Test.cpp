#include<graphics.h>                                           // Khai bao thu vien do hoa 
#include<conio.h>                                              // De dung man hinh do hoa
#include<iostream>
#define ROUND(a) (int)(a+0.5)                                  // Cau lenh lam tron
using namespace std; 
 
void Xuat(int xc, int yc, int x, int y, int color)
{
    putpixel(xc+x, yc+y, color);                               // Hien Thi ra man hinh
    putpixel(xc-x, yc+y, color);                               // Hien Thi ra man hinh
    putpixel(xc+x, yc-y, color);                               // Hien Thi ra man hinh
    putpixel(xc-x, yc-y, color);                               // Hien Thi ra man hinh
}
void Timdiem(int xc,int yc, int a, int b, int color)
{
    int x, y, fx, fy, a2, b2, p;                               // Khoi tao cac bien nguyen
    x = 0;                                                     // Gan x = 0
    y = b;                                                     // Gan y = b
    a2 = a*a;                                                  // Gan a2 = a binh phuong
    b2 = b*b;                                                  // Gan b2 = b binh phuong
    fx = 0;                                                    // Cho F(x) = 0
    fy = 2 * a2 * y;                                           // Cho F(y) = 2*A2*y
    Xuat(xc, yc, x, y, color);                                 // Hien thi ra man hinh 
    p = ROUND(b2 -(a2*b) + (0.25*a2));                         //p=b2 - a2*b +a2/4
    while(fx<fy)                                               // Xet truong hop : 2A2y > 0
    {
        x++;                                                   // Tang Gia tri cua x len 1
        fx += 2*b2;                                            // Tang Gia tri cua F(x) len 2*b2
        delay(50);                                             // Tao do tre
        if(p<0)                                                // Xet p < 0 de chon p
        {  
            p += b2*(2*x + 3);                                 //p=p + b2*(2x +3)
        }
        else
        {
            y--;
            p += b2*(2*x +3) + a2*(2- 2*y);                    //p=p +b2(2x +3) +a2(2-2y)
            fy -= 2*a2;
        }
        Xuat(xc, yc, x, y, color);                             // Hien Thi ra man hinh 
    }
    p = ROUND(b2*(x +0.5)*(x +0.5) + a2*(y-1)*(y-1) - a2*b2);  // Neu 2A2y <= 0
    //
    while(y>0)
    {
        y--;                                                   // Giam gia tri cua y di 1 
        fy -= 2*a2;                                            // Giam gia tri cua F(y) di 2*a2
        delay(50);
        if(p >=0)
        {
            p += a2*(3-2*y);                                   //p=p +a2(3-2y)
        }
        else
        {
            x++;
            fx += 2*b2;
            p += b2*(2*x +2) +a2*(3- 2*y);                     //p=p+ b2(2x +2) + a2(3-2y)
        }
        Xuat(xc, yc, x, y, color);                             // Hien thi ra man hinh 
    }
}
int main()
{
    int gd=DETECT, gm;                                         // Khoi tao cua so do hoa
    initgraph(&gd,&gm,"");
    Timdiem(getmaxx()/2, getmaxy()/2,150,80,15);               // Khai bao gia tri bien cho ham Tim diem
    getch();
    closegraph();
    return 0;
}
    
