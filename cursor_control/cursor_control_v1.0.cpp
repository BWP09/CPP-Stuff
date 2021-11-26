#include <iostream>
#include <string>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <stdio.h>
using namespace std;

int speed = 0;

void upMove() {         // Move cursor up function
    POINT p;
    if (GetCursorPos(&p)) {
        speed -= 4;
        SetCursorPos(p.x, p.y + speed);
    }
}

void downMove() {       // Move cursor down function
    POINT p;
    if (GetCursorPos(&p)) {
        speed += 4;
        SetCursorPos(p.x, p.y + speed);
    }
}

void leftMove() {       // Move cursor left function
    POINT p;
    if (GetCursorPos(&p)) {
        speed -= 4;
        SetCursorPos(p.x + speed, p.y);
    }
}

void rightMove() {      // Move cursor right function
    POINT p;
    if (GetCursorPos(&p)) {
        speed += 4;
        SetCursorPos(p.x + speed, p.y);
    }
}

void leftClick() {      // Left click function
    POINT p;
    if (GetCursorPos(&p)) {
        mouse_event(0x0002, p.x, p.y, 0, 0);
        mouse_event(0x0004, p.x, p.y, 0, 0);
    }
}

void rightClick() {     // Right click function
    POINT p;
    if (GetCursorPos(&p)) {
        mouse_event(0x0008, p.x, p.y, 0, 0);
        mouse_event(0x0010, p.x, p.y, 0, 0);
    }
}

int main() {
    int commonDelay = 1;
    int scrollLock = 0;
    
    while (true) {
        if (GetAsyncKeyState(0x91)) {       // Increments up "scrollLock"
            scrollLock += 1;
            Sleep(100);
        }

        if (scrollLock % 2 == 0) {          // Detects if "scrollLock" is even, used to turn off and on the cursor moving functionality
            Sleep(1);

            if (GetAsyncKeyState(0x68)) {   // If "up" on the numpad (8) is pressed, this will print "up is pressed", and run the "upMove()" function
                speed = 0;
                printf("up       is pressed\n");
                upMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x65)) {   // If "down" on the numpad (5) is pressed, this will print "down is pressed", and run the "downMove()" function
                speed = 0;
                printf("down     is pressed\n");
                downMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x64)) {   // If "left" on the numpad (4) is pressed, this will print "left is pressed", and run the "leftMove()" function
                speed = 0;
                printf("left     is pressed\n");
                leftMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x66)) {   // If "right" on the numpad (6) is pressed, this will print "right is pressed", and run the "rightMove()" function
                speed = 0;
                printf("right    is pressed\n");
                rightMove();
                Sleep(commonDelay);
            }

            if (GetAsyncKeyState(0x60) || GetAsyncKeyState(0x67)) {     // If "leftClick" on the numpad (7 or 0 keys) are pressed, this will print "leftC is pressed", and run the "leftClick()" function
                speed = 0;
                printf("leftC    is pressed\n");
                leftClick();
                Sleep(100);
            }

            if (GetAsyncKeyState(0x63) || GetAsyncKeyState(0x69)) {     // If "rightClick" on the numpad (9 or 3 keys) are pressed, this will print "rightC is pressed", and run the "rightClick()" function
                speed = 0;
                printf("rightC   is pressed\n");
                rightClick();
                Sleep(100);
            }
        }
    }
}