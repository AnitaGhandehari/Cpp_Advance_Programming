
#ifndef A5_TROOPER_H
#define A5_TROOPER_H


#include "Enemy.h"

#define THE_TROOPER_PIC_ADDRESS "Extra/enemies/trooper1.png"
#define THE_TROOPER_UP_PIC_ADDRESS "Extra/enemies/trooper2.png"
#define THE_TROOPER_DOWN_PIC_ADDRESS "Extra/enemies/trooper3.png"

class Trooper:public Enemy {
private:
    std::string trooper_pic_address;
    Point trooper_position;
    int next_position_index = 1;
public:
    Trooper(std::vector<Point> _enemy_way);
    void move(Window *_window) override;
    Point get_enemy_position() override;
    void set_life_value(int _hit) override;
};

#endif //A5_TROOPER_H
