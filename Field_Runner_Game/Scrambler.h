
#ifndef A5_SCRAMBLER_H
#define A5_SCRAMBLER_H

#include "Enemy.h"
#define THE_SCRAMBLER_PIC_ADDRESS "Extra/enemies/scrambler1.png"
#define THE_SCRAMBLER_UP_PIC_ADDRESS "Extra/enemies/scrambler2.png"
#define THE_SCRAMBLER_DOWN_PIC_ADDRESS "Extra/enemies/scrambler3.png"

class Scrambler:public Enemy{
private:
    std::string scrambler_pic_address;
    Point scrambler_position;
    int next_position_index = 1;
public:
    Scrambler(std::vector<Point> _enemy_way);
    void move(Window *_window) override;
    Point get_enemy_position() override;

    void set_life_value(int _hit);
};

#endif //A5_SCRAMBLER_H
