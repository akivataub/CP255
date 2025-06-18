#include <tice.h>
#include <graphx.h>
//hi
int colp = 255;
char colp_str[10];

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

void middle();

void beginning() {
    gfx_Begin();
    gfx_SetTextFGColor(0);
    gfx_FillScreen(255);
    gfx_PrintStringXY("Welcome to 255 Color Picker!", 10, 10);
    gfx_PrintStringXY("Click 2nd to start and mode to exit.", 10, 20);
    gfx_PrintStringXY("While in color picker click clear to return to-", 10, 30);
    gfx_PrintStringXY("this menu.", 10, 40);
    gfx_SwapDraw();

    while (1) {
        uint8_t key = os_GetCSC();
        if (key == sk_2nd) {
            middle();
            gfx_FillScreen(255);
            gfx_SetTextFGColor(0);
            gfx_PrintStringXY("Welcome to 255 Color Picker!", 10, 10);
            gfx_PrintStringXY("Click 2nd to start and mode to exit.", 10, 20);
            gfx_PrintStringXY("While in color picker click clear to return to-", 10, 30);
            gfx_PrintStringXY("this menu.", 10, 40);
            gfx_SwapDraw();
        }
        if (key == sk_Mode) {
            gfx_End();
            return;
        }
        if (key == sk_Clear) {
            gfx_FillScreen(255);
            gfx_SetTextFGColor(0);
            gfx_PrintStringXY("Welcome to 255 Color Picker!", 10, 10);
            gfx_PrintStringXY("Click 2nd to start and mode to exit.", 10, 20);
            gfx_PrintStringXY("While in color picker click clear to return to-", 10, 30);
            gfx_PrintStringXY("this menu.", 10, 40);
            gfx_SwapDraw();
        }
    }
}

void middle() {
    gfx_FillScreen(colp);
    gfx_SetTextFGColor(255 - colp);
    gfx_PrintStringXY("Color:", 100, 10);
    itoa(colp, colp_str);
    gfx_PrintStringXY(colp_str, 150, 10);
    gfx_SwapDraw();

    while (1) {
        uint8_t key = os_GetCSC();
        if (key == sk_Left) {
            gfx_SetTextFGColor(255 - colp);
            if (colp <= 0) {
                colp = 255;
            } else {
                colp = colp - 1;
            }
            gfx_FillScreen(colp);
            gfx_SetTextFGColor(255 - colp);
            gfx_PrintStringXY("Color:", 100, 10);
            itoa(colp, colp_str);
            gfx_PrintStringXY(colp_str, 150, 10);
            gfx_SwapDraw();
        }
        if (key == sk_Right) {
            if (colp >= 255) {
                colp = 0;
            } else {
                colp = colp + 1;
            }
            gfx_SetTextFGColor(255 - colp);
            gfx_FillScreen(colp);
            gfx_PrintStringXY("Color:", 100, 10);
            itoa(colp, colp_str);
            gfx_PrintStringXY(colp_str, 150, 10);
            gfx_SwapDraw();
        }
        if (key == sk_Clear) {
            return;
        }
    }
}

int main(void)
{
    beginning();
    return 0;
}