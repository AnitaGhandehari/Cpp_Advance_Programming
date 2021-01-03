
#ifndef A5_TESLA_H
#define A5_TESLA_H

#include "Tower.h"
#include <string>
#define TESLA_PIC_ADDRESS "Assets/towers/tesla1.png"
#define TESLA_UPGRADE1_PIC_ADDRESS "Assets/towers/tesla2.png"
#define TESLA_UPGRADE2_PIC_ADDRESS "Assets/towers/tesla3.png"

class Tesla: public Tower{
private:
    std::string tesla_pic_address = TESLA_PIC_ADDRESS;
    int hit_power = 700;
    int upgrade_value = 100;
public:
    Tesla(Point tesla_position);
    void put_tower_in_position(Window *_window) override;
    void upgrade_tower() override;
    bool arrange_shooting_time() override;
    void detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies) override;
    int get_enemy_upgrade_value() override{return upgrade_value; };
};


#endif //A5_TESLA_H
