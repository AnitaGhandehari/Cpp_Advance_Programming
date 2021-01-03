
#ifndef A5_GAMEWINDOW_H
#define A5_GAMEWINDOW_H

#include "RSDL-master/src/rsdl.hpp"
#include "EachRoom.h"
#include <vector>

#define NUMBER_OF_WINDOW_COL 19
#define NUMBER_OF_WINDOW_ROW 11
#define WINDOW_CORNER_X 122
#define WINDOW_CORNER_Y 175
#define GAME_NAME "FieldRunners"
#define BACKGROUND_PIC "Assets/background.png"
#define LOSE_PIC "Extra/lose.png"
#define WIN_PIC "Extra/win.png"


class GameWindow
{
private:
    int height;
    int width;
    std::vector<std::vector<EachRoom*>> rooms;
    Window *window;
public:
    GameWindow(int _width , int _height);
    void draw_background_image();
    void assign_rooms();
    Window* get_window(){return window;};
    std::vector<std::vector<EachRoom*>> get_rooms(){return rooms;};
    void draw_lose_image();
    void draw_win_image();
};
#endif //A5_GAMEWINDOW_H
