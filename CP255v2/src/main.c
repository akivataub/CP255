#include <tice.h>
#include <graphx.h>

char color_str[4];
int cpx = 0;
int cpy = 5;
int bsx = 0;
int bsy = 0;

void itoa(int num, char* str) {
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    int i = 0;
    while (num > 0) {
        int digit = num % 10;
        str[i] = '0' + digit;
        num /= 10;
        i++;
    }
    str[i] = '\0';
    int len = i;
    for (int j = 0; j < len / 2; j++) {
        char temp = str[j];
        str[j] = str[len - 1 - j];
        str[len - 1 - j] = temp;
    }
}

void about() {
    gfx_SetDrawBuffer();
    gfx_FillScreen(255);
    gfx_SetColor(0);
    gfx_SetTextScale(1.5, 1.5);
    gfx_PrintStringXY("About Color Picker 2.0", 80, 20);
    gfx_PrintStringXY("Made by mumbojum2", 90, 50);
    gfx_PrintStringXY("github.com/mumbojum2", 90, 80);
    gfx_PrintStringXY("Version 2", 110, 150);
    gfx_PrintStringXY("Press Clear to return to menu", 60, 180);
    gfx_BlitBuffer();
    while (1) {
        if (os_GetCSC() == sk_Clear) {
            gfx_FillScreen(255);
            break;
        }
    }
}

void start() {
    gfx_SetDrawBuffer();
    gfx_FillScreen(255);
    int cols = 15;
    int rows = 17;
    int squareWidth = 10;
    int squareHeight = 12;
    int lineWidth = 2;
    int xStart = 0;
    int yStart = 0;
    for (int i = 0; i < 255; i++) {
        int col = i % cols;
        int row = i / cols;
        int x = xStart + col * (squareWidth + lineWidth);
        int y = yStart + row * (squareHeight + lineWidth);
        if (x + squareWidth <= 160) {
            gfx_SetColor(i);
            gfx_FillRectangle(x, y, squareWidth, squareHeight);
        }
    }
    gfx_SetColor(0);
    for (int i = 0; i < cols; i++) {
        int x = xStart + i * (squareWidth + lineWidth) + squareWidth;
        if (x + lineWidth < 160) {
            gfx_VertLine(x, yStart, 238);
            gfx_VertLine(x + 1, yStart, 238);
        }
    }
    for (int i = 0; i < rows; i++) {
        int y = yStart + i * (squareHeight + lineWidth) + squareHeight;
        if (y + lineWidth < 240) {
            gfx_HorizLine(xStart, y - 1, xStart + cols * squareWidth + 4);
            gfx_HorizLine(xStart, y, xStart + cols * squareWidth + 4);
            gfx_HorizLine(xStart, y + 1, xStart + cols * squareWidth + 4);
        }
    }
    gfx_SetColor(0);
    gfx_FillRectangle(156, 0, 164, 240);
    gfx_FillRectangle(0, 238, 156, 2);
    uint8_t color = gfx_GetPixel(cpx + 5, cpy + 4);
    gfx_SetColor(color);
    gfx_FillRectangle(156, 0, 164, 240);
    gfx_SetColor(255);
    gfx_Rectangle(bsx, bsy, 11, 12);
    gfx_BlitBuffer();
    while (1) {
        uint8_t key = os_GetCSC();
        if (key == sk_Right) {
            cpx += 12;
            bsx += 12;
            if (cpx >= 150) { cpx = 0; bsx = 0; gfx_SetColor(0); gfx_Rectangle(144, bsy, 11, 12); }
            uint8_t new_color = gfx_GetPixel(cpx + 5, cpy + 4);
            gfx_SetColor(new_color);
            gfx_FillRectangle(156, 0, 164, 240);
            gfx_SetColor(0);
            gfx_Rectangle(bsx - 12, bsy, 11, 12);
            gfx_SetColor(255);
            gfx_Rectangle(bsx, bsy, 11, 12);
            gfx_BlitBuffer();
        }
        if (key == sk_Left) {
            int prevbsx = bsx;
            cpx -= 12;
            bsx -= 12;
            if (cpx < 0) { cpx = 144; bsx = 144; gfx_SetColor(0); gfx_Rectangle(144, bsy, 11, 12); }
            uint8_t new_color = gfx_GetPixel(cpx + 5, cpy + 4);
            gfx_SetColor(new_color);
            gfx_FillRectangle(156, 0, 164, 240);
            gfx_SetColor(0);
            gfx_Rectangle(prevbsx, bsy, 11, 12);
            gfx_SetColor(255);
            gfx_Rectangle(bsx, bsy, 11, 12);
            gfx_BlitBuffer();
        }
        if (key == sk_Down) {
            cpy -= 14;
            bsy -= 14;
            if (cpy > 238) {cpy = 0; bsy = 0; gfx_SetColor(0); gfx_Rectangle(bsx, 238, 11, 12);}
        }
        if (key == sk_Clear) {
            break;
        }
    }
    gfx_End();
}

int main(void)
{
    int state = 0;
    gfx_Begin();
    while (1) {
        if (state == 0) {
            gfx_SetDrawBuffer();
            gfx_SetColor(0);
            gfx_SetTextScale(1.5, 1.5);
            gfx_PrintStringXY("Welcome to Color Picker 2.0!", 10, 10);
            gfx_PrintStringXY("To start the program press 2nd", 10, 30);
            gfx_PrintStringXY("To Quit the program press mode now or clear", 10, 50);
            gfx_PrintStringXY("within the program to get back to this menu", 10, 60);
            gfx_PrintStringXY("Press math in this menu for the about section.", 10, 80);
            gfx_BlitBuffer();
            uint8_t key = os_GetCSC();
            if (key == sk_Mode) {
                gfx_End();
                break;
            }
            if (key == sk_2nd) {
                state = 1;
                gfx_FillScreen(255);
            }
            if (key == sk_Math) {
                state = 2;
                gfx_FillScreen(255);
            }
        }
        if (state == 1) {
            start();
            state = 0;
        }
        if (state == 2) {
            about();
            state = 0;
        }
    }
    return 0;
}