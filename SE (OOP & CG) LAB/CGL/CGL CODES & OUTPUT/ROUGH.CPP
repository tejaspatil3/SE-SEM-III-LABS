
#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>  // Include this header for the prototype of delay function

class ASS01
{
 public:
    void scanline(int [], int [], int);
};

void ASS01 :: scanline(int Xx[10], int Yy[10], int n)
{
    int i, k, temp, Ymax = 480, Ymin = 0, inx[50];
    float m[50], Dx, Dy;

    for(i = 0; i < n; i++)
    {
        if(Yy[i] >= Ymax)
            Ymax = Yy[i];
        if(Yy[i] <= Ymin)
            Ymin = Yy[i];

        Dx = Xx[i + 1] - Xx[i];
        Dy = Yy[i + 1] - Yy[i];

        if(Dx == 0) { m[i] = 0; }
        if(Dy == 0) { m[i] = 1; }
        if(Dx != 0 && Dy != 0)
            m[i] = (float)(Dx / Dy);
    }

    for(int y = Ymax; y <= Ymin; y++)
    {
        int c = 0;
        for(i = 0; i < n; i++)
        {
            if((Yy[i] > y && Yy[i + 1] <= y) || (Yy[i] <= y && Yy[i + 1] > y))
            {
                inx[c] = (Xx[i] + (m[i] * (y - Yy[i])));
                c++;
            }
        }

        for(k = 0; k < c - 1; k++)
        {
            for(i = 0; i < c - 1; i++)
            {
                if(inx[i] > inx[i + 1])
                {
                    temp = inx[i];
                    inx[i] = inx[i + 1];
                    inx[i + 1] = temp;
                }
            }
        }

        for(i = 0; i < c - 1; i += 2)
        {
            line(inx[i], y, inx[i + 1] + 1, y);
            delay(300);
        }
    }
}

int main()
{
    int Xx[10], Yy[10], n;

    cout<<"Enter No. of vertices : ";
    cin>>n;

    for(int i = 0; i < n; i++)
    {
        cout<<"\nEnter vertices of polygon : ";
        cin>>Xx[i]>>Yy[i];
    }

    int gd = DETECT, gm = 0;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    ASS01 s;
    s.scanline(Xx, Yy, n);

    getch();
    closegraph();
    return 0;
}