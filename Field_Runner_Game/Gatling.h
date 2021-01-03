
#ifndef A5_GATLING_H
#define A5_GATLING_H

#include "Tower.h"
#include <string>
#define GATLING_PIC_ADDRESS "Assets/towers/gattling1.png"
#define GATLING_UPGRADE1_PIC_ADDRESS "Assets/towers/gattling2.png"
#define GATLING_UPGRADE2_PIC_ADDRESS "Assets/towers/gattling3.png"


class Gatling: public Tower{
private:
    std::string gatling_pic_address = GATLING_PIC_ADDRESS;


    int hit_power = 35;
    int upgrade_value = 40;
public:
    Gatling(Point gatling_position);
    void put_tower_in_position(Window *_window) override;
    void upgrade_tower() override;
    bool arrange_shooting_time() override;
    void detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies) override;
    int get_enemy_upgrade_value() override{return upgrade_value; };
};

#endif //A5_GATLING_H
