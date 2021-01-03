
#include "GameWindow.h"
using namespace std;
GameWindow::GameWindow(int _width , int _height)
{
    height = _height;
    width = _width;
    window = new Window(width , height , GAME_NAME);
}
void GameWindow::draw_background_image() {
    window->draw_img(BACKGROUND_PIC, Rectangle(0,0,1365,1024));
}

void GameWindow::draw_lose_image()
{
    window->draw_img(LOSE_PIC, Rectangle(0,0,1365,1024));
}

void GameWindow::draw_win_image()
{
    window->draw_img(WIN_PIC, Rectangle(0,0,1365,1024));
}

void GameWindow::assign_rooms() {
    Point room_place(0 , 0);
    vector<EachRoom*> row_of_rooms;
    for (int window_col = 0 ; window_col < NUMBER_OF_WINDOW_COL ; window_col++)
    {
        for(int window_row = 0 ; window_row < NUMBER_OF_WINDOW_ROW ; window_row++)
        {
            room_place.x = WINDOW_CORNER_X + window_col * ROOM_SIZE;
            room_place.y = WINDOW_CORNER_Y + window_row * ROOM_SIZE;
            EachRoom *room = new EachRoom(room_place.x , room_place.y);
            row_of_rooms.push_back(room);
        }
        rooms.push_back(row_of_rooms);
        row_of_rooms.clear();
    }
}



