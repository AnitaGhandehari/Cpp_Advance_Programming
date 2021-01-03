
#ifndef A5_TOWER_H
#define A5_TOWER_H

#include <iostream>
#include "RSDL-master/src/rsdl.hpp"
#include "Enemy.h"
#define BULLET_RANGE 150

class Tower{
protected:
    int bullet_range = BULLET_RANGE;
    Point tower_room_position;
    int upgrade_level = 0;
    int shooting_time = 0;
public:
    Tower(Point _tower_position);
    virtual void put_tower_in_position(Window *_window) = 0;
    virtual void upgrade_tower() = 0;
    virtual bool arrange_shooting_time() = 0;
    virtual void detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy *> _enemies) = 0;
    virtual int get_enemy_upgrade_value() = 0;
};

#endif //A5_TOWER_H
