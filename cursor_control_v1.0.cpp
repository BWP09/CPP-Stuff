#include <iostream>
#include <string>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int speed = 0;

void upMove() {
    POINT p;
    if (GetCursorPos(&p)) {
        speed -= 4;
        SetCursorPos(p.x, p.y + speed);
    }
}

void downMove() {
    POINT p;
    if (GetCursorPos(&p)) {
        speed += 4;
        SetCursorPos(p.x, p.y + speed);
    }
}

void leftMove() {
    POINT p;
    if (GetCursorPos(&p)) {
        speed -= 4;
        SetCursorPos(p.x + speed, p.y);
    }
}

void rightMove() {
    POINT p;
    if (GetCursorPos(&p)) {
        speed += 4;
        SetCursorPos(p.x + speed, p.y);
    }
}

void leftClick() {
    POINT p;
    if (GetCursorPos(&p)) {
        mouse_event(0x0002, p.x, p.y, 0, 0);
        mouse_event(0x0004, p.x, p.y, 0, 0);
    }
}

void rightClick() {
    POINT p;
    if (GetCursorPos(&p)) {
        mouse_event(0x0008, p.x, p.y, 0, 0);
        mouse_event(0x0010, p.x, p.y, 0, 0);
    }
}

int main() {
    int commonDelay = 1;
    int numlock = 0;
    
    while (true) {
        if (GetAsyncKeyState(0x91)) {
            numlock += 1;
            Sleep(100);
        }

        if (numlock % 2 == 0) {
            Sleep(1);

            if (GetAsyncKeyState(0x68)) {
                speed = 0;
                printf("up       is pressed\n");
                upMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x65)) {
                speed = 0;
                printf("down     is pressed\n");
                downMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x64)) {
                speed = 0;
                printf("left     is pressed\n");
                leftMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x66)) {
                speed = 0;
                printf("right    is pressed\n");
                rightMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x60) || GetAsyncKeyState(0x67)) {
                speed = 0;
                printf("leftC    is pressed\n");
                leftClick();
                Sleep(100);
            }

            if (GetAsyncKeyState(0x63) || GetAsyncKeyState(0x69)) {
                speed = 0;
                printf("rightC   is pressed\n");
                rightClick();
                Sleep(100);
            }
        }
    }
}