#include <iostream>
#include <string>
#include <windows.h>
#include <winuser.h>
#include <conio.h>
#include <stdio.h>
using namespace std;


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
    int F17 = 1;
    int F18 = 1;

    while (true) {   
        if (GetAsyncKeyState(VK_F17)) {
            F17 += 1;
            Sleep(200);
        }

        if (GetAsyncKeyState(VK_F18)) {
            F18 += 1;
            Sleep(200);
        }

        if (F17 % 2 == 0) {
            printf("key pressed, running left;  running = ");
            cout << F17 << endl;
            leftClick();
            Sleep(5);
       }
       
       else if (F18 % 2 == 0) {
            printf("key pressed, running right;  running = ");
            cout << F18 << endl;
            rightClick();
            Sleep(5);
       }
       
       else {
           printf("not pressed\n");
           Sleep(10);
       }
    }
}