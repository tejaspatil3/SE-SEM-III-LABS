// PRACTICAL Assignment No:05 {Computer Graphics}
// Roll No:205B065

/*	a) Write C++ program to generate snowflake using concept of fractals.
							OR
	b) Write C++ program to generate Hilbert curve using concept of fractals.
							OR
	c) Write C++ program to generate fractal patterns by using Koch curves.*/

#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include<dos.h>
#include<stdio.h>

void move(int j, int h, int &x, int &y) {
if (j == 1)
y -= h;
else if (j == 2)
x += h;
else if (j == 3)
y += h;
else if (j == 4)
x -= h;
lineto(x, y);
}
void hilbert(int r, int d, int l, int u, int i, int h, int &x, int &y) {
if (i > 0) {
i--;
hilbert(d, r, u, l, i, h, x, y);
move(r, h, x, y);
hilbert(r, d, l, u, i, h, x, y);
move(d, h, x, y);
hilbert(r, d, l, u, i, h, x, y);
move(l, h, x, y);
hilbert(u, l, d, r, i, h, x, y);
}} int main() {
int n, x1, y1;
int x0 = 50, y0 = 100, x, y, h = 10, r = 2, d = 3, l = 4, u = 1;
cout<<"\nPRACTICAL Assignment No:05 {Computer Graphics}\nRoll No:205B065";
cout<<" \nGive the value of n : ";
cin>>n;
x = x0;
y = y0;
int gdriver = DETECT, gmode;
initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");
moveto(x, y);
hilbert(r, d, l, u, n, h, x, y);
delay(6000);
closegraph();
return 0;
}
