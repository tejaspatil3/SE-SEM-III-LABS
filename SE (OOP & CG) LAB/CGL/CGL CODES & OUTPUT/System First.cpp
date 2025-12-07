
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <cmath>

void drawSun(int x, int y, int radius) {
    setcolor(YELLOW);

    // Draw the sun as a circle
    for (int i = 0; i <= 360; i++) {
        float angle = static_cast<float>(i) * 3.14f / 180.0f;
        int x_pos = x + radius * cos(angle);
        int y_pos = y + radius * sin(angle);
        putpixel(x_pos, y_pos, YELLOW);
    }
}

void drawScene(int sunX, int sunY, int timeOfDay) {
    cleardevice();

    // Draw the sky
    if (timeOfDay < 50) {
        // Sunrise - Change sky color to light blue
        setbkcolor(LIGHTBLUE);
    } else {
        // Sunset - Change sky color to orange
        setbkcolor(LIGHTRED);
    }

    drawSun(sunX, sunY, 30);

    delay(50);
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\Turboc3\\BGI");

    int sunX = 300, sunY = 100;
    int timeOfDay = 0;

    while (!kbhit()) {
        drawScene(sunX, sunY, timeOfDay);

        // Update time of day for animation
        timeOfDay++;

        if (timeOfDay > 100) {
            timeOfDay = 0;
        }

        // Update sun position for animation
        sunX = 300 + static_cast<int>(200 * cos(timeOfDay * 3.14 / 180.0));
        sunY = 300 + static_cast<int>(100 * sin(timeOfDay * 3.14 / 180.0));
    }

    closegraph();
    return 0;
}
