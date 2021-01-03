
#ifndef A5_THERUNNER_H
#define A5_THERUNNER_H

#include "Enemy.h"
#define THE_RUNNER_PIC_ADDRESS "Extra/enemies/runner1.png"
#define THE_RUNNER_UP_PIC_ADDRESS "Extra/enemies/runner2.png"
#define THE_RUNNER_DOWN_PIC_ADDRESS "Extra/enemies/runner3.png"

class TheRunner:public Enemy{
private:
    std::string runner_pic_address;
    Point runner_position;
    int next_position_index = 1;
public:
    TheRunner(std::vector<Point> _enemy_way);
    void move(Window *_window) override;
    Point get_enemy_position() override;
    void set_life_value(int _hit) override;
};
#endif //A5_THERUNNER_H
