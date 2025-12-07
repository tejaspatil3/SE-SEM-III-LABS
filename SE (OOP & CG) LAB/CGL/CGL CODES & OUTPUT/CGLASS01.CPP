//PRACTICAL Assignment No:01 {Computer Graphics}
// Roll No:205B065

/*  Write C++ program to draw a concave polygon and fill it with desired color using
    scan fill algorithm. Apply the concept of inheritance.*/

#include<iostream.h>
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <dos.h>

class ASS01 {
public:
    void scanline(int[], int[], int);
    void drawPixel(int, int);
};

void ASS01::drawPixel(int x, int y) {
    putpixel(x, y, RED);
}

void ASS01::scanline(int Xx[10], int Yy[10], int n) {
    int i, k, temp, Ymax = 0, Ymin = 480, inx[50], x, y;
    double m[50], Dx, Dy;
    setcolor(RED);

    for (i = 0; i < n; i++) {
        if (Yy[i] >= Ymax)
            Ymax = Yy[i];
        if (Yy[i] <= Ymin)
            Ymin = Yy[i];

        Dx = Xx[i + 1] - Xx[i];
        Dy = Yy[i + 1] - Yy[i];

        if (Dx == 0) { m[i] = 0; }
        if (Dy == 0) { m[i] = 1; }
        if (Dx != 0 && Dy != 0)
            m[i] = (Dx / Dy);
    }

    for (y = Ymax; y >= Ymin; y--) {
        int c = 0;
        for (i = 0; i < n; i++) {
            if ((Yy[i] > y && Yy[i + 1] <= y) || (Yy[i] <= y && Yy[i + 1] > y)) {
                inx[c] = (Xx[i] + (m[i] * (y - Yy[i])));
                c++;
            }
        }

        for (k = 0; k < c - 1; k += 2) {
            for (x = inx[k]; x <= inx[k + 1]; x++) {
                drawPixel(x, y);
            }
        }

	delay(100);  // Adjust the delay value as per your requirement
    }
}

int main() {
    int Xx[10], Yy[10], n, i = 0, x, y;
    printf("\nPRACTICAL Assignment No:01 {Computer Graphics}\nRoll No:205B065");
    printf("\n\tSCANLINE POLYGON FILL ALGORITHM");
    printf("\nEnter No. of vertices less than 10: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
	printf("\nEnter vertices of polygon : ");
	scanf("%d %d", &Xx[i], &Yy[i]);
    }

    ASS01 S1;
    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Draw the polygon and fill using scanline algorithm
    S1.scanline(Xx, Yy, n);
    
    getch();  // Wait for a key press before closing the graphics window
    closegraph();  // Close the graphics window

    return 0;
}
//End of program