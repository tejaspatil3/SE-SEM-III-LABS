#include <iostream.h>
#include <graphics.h>
//nclude <cmath>

//ing namespace std;

const int WIDTH = 800;
const int HEIGHT = 800;

void drawSnowflake(int x, int y, int size, int depth) {
    if (depth == 0)
        return;

    int x1, y1, x2, y2;
    double angle = 60 * (M_PI / 180.0);  // Convert to radians

    x1 = x + size * cos(angle);
    y1 = y - size * sin(angle);

    x2 = x + size * cos(-angle);
    y2 = y - size * sin(-angle);

    line(x, y, x1, y1);
    line(x, y, x2, y2);

    drawSnowflake(x1, y1, size / 3, depth - 1);
    drawSnowflake(x2, y2, size / 3, depth - 1);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    // Set the window size
    setwindow(0, 0, WIDTH, HEIGHT);
    setbkcolor(BLACK);
    cleardevice();

    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int size = 200;
    int depth = 4;

    drawSnowflake(x, y, size, depth);

    getch();
    closegraph();
    return 0;
}