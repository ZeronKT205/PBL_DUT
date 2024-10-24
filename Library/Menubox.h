#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#ifndef MENUBOX_H
#define MENUBOX_H
#include <iostream>
#include <conio.h>
#include <string>
#include <ctime>     /* thư viện hỗ trợ về thời gian thực */
#include "windows.h" // thư viện này bá đạo lắm nhé - chứa nhiều đồ chơi nek - cứ tìm hiểu dần dần s
//======= lấy tọa độ x của con trỏ hiện tại =============
constexpr int KEY_NONE = -1;
using namespace std;
int whereX()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.X;
    return -1;
}
//========= lấy tọa độ y của con trỏ hiện tại =======
int whereY()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
        return csbi.dwCursorPosition.Y;
    return -1;
}
//============== dịch con trỏ hiện tại đến điểm có tọa độ (x,y) ==========
void gotoXY(int x, int y) {
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { (SHORT)x, (SHORT)y }; // Đảm bảo kiểu dữ liệu đúng
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    if (SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos) == FALSE) {
        // Xử lý lỗi nếu không thể đặt vị trí con trỏ
        DWORD dwError = GetLastError();
        printf("ERROR: Unable to set cursor position. Error code: %lu\n", dwError);
    }
}
//============= đặt màu cho chữ =========
void SetColor(WORD color)
{
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
//============== làm ẩn trỏ chuột ===========
void ShowCur(bool CursorVisibility)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor = { 1, CursorVisibility };
    SetConsoleCursorInfo(handle, &cursor);
}
//======= trả về mã phím người dùng bấm =========
int inputKey()
{
    if (_kbhit()) // true
    {
        int key = _getch();

        if (key == 224)
        {
            key = _getch();
            return key + 1000;
        }

        return key;
    }
    else
    {
        return KEY_NONE;
    }
    return KEY_NONE;
}
void textcolor(int x)
{
    HANDLE mau;
    mau = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(mau, x);
}
int inputKey1(int key)
{
    // if (_kbhit())
    // {
    // int key = _getch();
    if (key == 224)
    {
        key = _getch();
        return key + 1000;
    }
    else
        return key;
    // }
    // else
    // {
    //     return KEY_NONE;
    // }

    return KEY_NONE;
}
void ToMau(int x, int y, char* a, int color)
{
    gotoXY(x, y);
    textcolor(color);
    cout << a;
    textcolor(7);
}
void resizeConsole(int width, int heigth)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, heigth, TRUE);
}
#endif
