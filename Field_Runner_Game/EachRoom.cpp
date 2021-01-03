#include "EachRoom.h"
using namespace std;

EachRoom::EachRoom(int _x_left_up_corner , int _y_left_up_corner)
{
    left_up_corner.x = _x_left_up_corner;
    left_up_corner.y = _y_left_up_corner;
    right_down_corner.x = left_up_corner.x + ROOM_SIZE;
    right_down_corner.y = left_up_corner.y + ROOM_SIZE;
}


bool EachRoom::contain_in_room(Point _mouse_point)
{
    if(_mouse_point.x > left_up_corner.x && _mouse_point.x < right_down_corner.x &&
       _mouse_point.y > left_up_corner.y && _mouse_point.y < right_down_corner.y)
    {
        return true;
    }
    else
        return false;
}

Point EachRoom::get_room_center()
{
    Point room_center;
    room_center.x = left_up_corner.x + ROOM_SIZE / 2;
    room_center.y = left_up_corner.y + ROOM_SIZE / 2;
    return room_center;
}


void EachRoom::set_tower_in_room(Tower *_tower_in_room)
{
    tower_in_room = _tower_in_room;
}

bool EachRoom::show_room_condition()
{
    return tower_in_room != nullptr;
}

int EachRoom::get_tower_in_room_upgrade_value()
{
    return tower_in_room->get_enemy_upgrade_value();
}

void EachRoom::upgrade_tower_in_room()
{
    tower_in_room->upgrade_tower();
}

void EachRoom::set_room_in_enemy_way()
{
    room_in_enemy_way = true;
}

bool EachRoom::is_this_room_in_enemy_way()
{
    return room_in_enemy_way;
}