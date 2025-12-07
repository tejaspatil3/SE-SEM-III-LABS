// PRACTICAL Assignment No:07 {Computer Graphics}
// Roll No:205B065

// Write a C++ program to implement bouncing ball using sine wave form.
// Apply the Conept of Polymorphism

#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void main()
{
    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");
    float x = 1, y = 0.00000, j = 0.5, increment = 0.1;
    float r = 15;
    //Drawing Green Ground
    setcolor(10);
    line(9, 315, 550, 315);
    line(9, 325, 560, 325);
    line(9, 335, 570, 335);
    line(9, 345, 580, 345);
    line(9, 355, 590, 355);
    line(9, 365, 600, 365);
    line(9, 375, 610, 375);
    line(9, 385, 630, 385);

    delay(1000);
    //First For loop gives the bounces of the Ball
    for (int k = 0; k <= 9; k++) {
        
        for (float i = 90; i < 370; i += 10) {
	    y = sin(((i * 22 / 7) / 180)) / j;

        if (y > 0) {
		y = -y;
		x += 5;
	    }
	    setcolor(12);
	    setfillstyle(1, 12);
	    circle(x, y * 100 + 300, r);
	    floodfill(x, y * 100 + 300, 12);
	    delay(100);
	    setcolor(0);
	    setfillstyle(1, 0);
	    circle(x, y * 100 + 300, r);

	    floodfill(x, y * 100 + 300, 0);
	}

	j += increment;
	increment += 0.01;
    }

    delay(1000);
    closegraph();
    getch();
}
//End Of Program