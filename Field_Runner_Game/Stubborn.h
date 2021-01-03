
#ifndef A5_STUBBORN_H
#define A5_STUBBORN_H

#include "Enemy.h"
#define THE_STUBBORN_PIC_ADDRESS "Extra/enemies/stubborn1.png"
#define THE_STUBBORN_UP_PIC_ADDRESS "Extra/enemies/stubborn2.png"
#define THE_STUBBORN_DOWN_PIC_ADDRESS "Extra/enemies/stubborn3.png"


class Stubborn: public Enemy
{
private:
    std::string stubborn_pic_address;
    Point stubborn_position;
    int next_position_index = 1;
public:
    Stubborn(std::vector<Point> _enemy_way);
    void move(Window *_window) override;
    Point get_enemy_position() override;

    void set_life_value(int _hit);
};


#endif //A5_STUBBORN_H
