//PRACTICAL Assignment No:03 {Computer Graphics}
// Roll No:205B065

// Write a C++ program to braw the shape.
// Use DDA line and Bresenham's circle drawing algorithm.Applyth econcept of Encaptulation

#include<iostream.h>
#include<graphics.h>
#include<stdio.h>
#include<dos.h>
#include<math.h>
#include<conio.h>

void DDA_ALGORITHM(int x1,int y1,int x2,int y2)
{
float Dx,Dy,delx,dely,x0,y0,len,i;
 //cout<<"Enter The values of (x1,y1),(x2,y2)";
 //cin>>x1>>y1>>x2>>y2;
//x1=100;
//y1=100;
//x2=400;
//y2=400;

 //cal
 Dx=x2-x1;
 Dy=y2-y1;
 if(Dx>Dy){len=Dx;}
 else{len=Dy;}

 delx=Dx/len;
 dely=Dy/len;

 x0=x1+0.5;
 y0=y1+0.5;

 for(i=1;i<=len;i++)
 {x0=x0+delx;
 y0=y0+dely;
 //cout<<x<<" , "<<y<<endl;
 putpixel(x0,y0,9);
}
}
void Displaying_and_drawingCircle(int Xcentre, int Ycentre, int x, int y) {
    putpixel(Xcentre + x, Ycentre + y, WHITE);
    putpixel(Xcentre - x, Ycentre + y, WHITE);
    putpixel(Xcentre + x, Ycentre - y, WHITE);
    putpixel(Xcentre - x, Ycentre - y, WHITE);
    putpixel(Xcentre + y, Ycentre + x, WHITE);
    putpixel(Xcentre - y, Ycentre + x, WHITE);
    putpixel(Xcentre + y, Ycentre - x, WHITE);
    putpixel(Xcentre - y, Ycentre - x, WHITE);
}

void Bresenham_Circle_Calculations(int Xcentre, int Ycentre, int radius) {
    int x = 0, y = radius;
    int d = 3 - 2 * radius;

    Displaying_and_drawingCircle(Xcentre, Ycentre, x, y);

    while (y >= x)
    {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;} 
        else 
        {
            d = d + 4 * x + 6;}
        Displaying_and_drawingCircle(Xcentre, Ycentre, x, y);
        if (x != y) {
            Displaying_and_drawingCircle(Xcentre, Ycentre, y, x);}
    }
}

void main() {
    int gd = DETECT, gm=0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Vertices of the triangle
    int x1 = 200, y1 = 200;
    int x2 = 400, y2 = 400;
    int x3 = 600, y3 = 200;
    DDA_ALGORITHM(200,200,400,475);
    DDA_ALGORITHM(400,475,600,200);
    DDA_ALGORITHM(200,200,600,200);

    // Calculate circumcircle center and radius
    int circumcenterX = (x1 + x2 + x3) / 3;
    int circumcenterY = (y1 + y2 + y3) / 3;
    int circumradius = sqrt(pow(x1 - circumcenterX, 2) + pow(y1 - circumcenterY, 2));

    // Draw the circumcircle
    Bresenham_Circle_Calculations(circumcenterX, circumcenterY, circumradius);
    Bresenham_Circle_Calculations(circumcenterX, circumcenterY, circumradius/2);

    delay(5000);
    closegraph();
    getch();
}
//End OF Program
