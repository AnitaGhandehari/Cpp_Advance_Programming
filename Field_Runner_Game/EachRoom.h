
#ifndef A5_EACHROOM_H
#define A5_EACHROOM_H

#include "RSDL-master/src/rsdl.hpp"
#include "Tower.h"
#define ROOM_SIZE 60

class EachRoom{
private:
    Point left_up_corner;
    Point right_down_corner;
    Tower *tower_in_room = nullptr;
    bool room_in_enemy_way = false;
public:
    EachRoom(int _x_left_up_corner , int _y_left_up_corner);
    bool contain_in_room(Point _mouse_point);
    Point get_room_center();
    Point get_room_left_up(){ return left_up_corner; };
    void set_tower_in_room(Tower *_tower_in_room);
    bool show_room_condition();
    int get_tower_in_room_upgrade_value();
    void upgrade_tower_in_room();
    void set_room_in_enemy_way();
    bool is_this_room_in_enemy_way();
};

#endif //A5_EACHROOM_H
