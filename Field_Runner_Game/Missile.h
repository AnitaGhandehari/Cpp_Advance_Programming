
#ifndef A5_MISSILE_H
#define A5_MISSILE_H

#include "Tower.h"
#include <string>

#define MISSILE_PIC_ADDRESS "Assets/towers/missile1.png"
#define MISSILE_UPGRADE1_PIC_ADDRESS "Assets/towers/missile2.png"
#define MISSILE__UPGRADE2_PIC_ADDRESS "Assets/towers/missile3.png"

class Missile: public Tower{
private:
    std::string missile_pic_address = MISSILE_PIC_ADDRESS;
    int hit_power = 75;
    int upgrade_value = 60;

public:
    Missile(Point missile_position);
    void put_tower_in_position(Window *_window) override;
    void upgrade_tower() override;
    bool arrange_shooting_time() override;
    void detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies) override;
    int get_enemy_upgrade_value() override{return upgrade_value; };
};


#endif //A5_MISSILE_H
