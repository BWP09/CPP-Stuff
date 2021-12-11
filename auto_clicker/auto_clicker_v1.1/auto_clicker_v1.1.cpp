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
    int running = 1;
    string input;

start:
    printf("1 for left click, 2 for right click");
    cin >> input;

    if (input != "1" && input != "2") {
        printf("invalid user input");
        Sleep(50);
        goto start;
    }

    while (true) {   
        if (GetAsyncKeyState(VK_F18)) {
            running += 1;
            Sleep(200);
        }

        if (running % 2 == 0 && input == "1") {
            printf("key pressed, running left;  running = ");
            cout << running << endl;
            leftClick();
            Sleep(5);
       }
       
       else if (running % 2 == 0 && input == "2") {
            printf("key pressed, running right;  running = ");
            cout << running << endl;
            rightClick();
            Sleep(5);
       }
       
       else {
           printf("not pressed\n");
           Sleep(10);
       }
    }
}