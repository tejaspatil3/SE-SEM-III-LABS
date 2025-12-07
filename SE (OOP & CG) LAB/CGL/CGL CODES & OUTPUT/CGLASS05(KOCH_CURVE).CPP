// PRACTICAL Assignment No:05 {Computer Graphics}
// Roll No:205B065

/*	a) Write C++ program to generate snowflake using concept of fractals.
							OR
	b) Write C++ program to generate Hilbert curve using concept of fractals.
							OR
	c) Write C++ program to generate fractal patterns by using Koch curves.*/

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void Koch_Curves(int X1, int Y1, int X2, int Y2, int color)
{
    double Angle = 60*3.142/180;
    int X3 = (2*X1+X2)/3;
    int Y3 = (2*Y1+Y2)/3;
    int X4 = (X1+2*X2)/3;
    int Y4 = (Y1+2*Y2)/3;
    int x = X3 + (X4-X3)*cos(Angle)+(Y4-Y3)*sin(Angle);
    int y = Y3 - (X4-X3)*sin(Angle)+(Y4-Y3)*cos(Angle);

    if(color > 0)
    {
        Koch_Curves(X1, Y1, X3, Y3, color-1);
        Koch_Curves(X3, Y3, x, y, color-1);
        Koch_Curves(x, y, X4, Y4, color-1);
        Koch_Curves(X4, Y4, X2, Y2, color-1);
    }
    else
    {
        line(X1, Y1, X3, Y3);
        line(X3, Y3, x, y);
        line(x, y, X4, Y4);
        line(X4, Y4, X2, Y2);
    }
}

void main()
{
    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int X1 = 150, Y1 = 250, X2 = 450, Y2 = 250;
    Koch_Curves(X1, Y1, X2, Y2, 3);

    delay(5000); 

    closegraph();
    getch();
}
//End Of Program