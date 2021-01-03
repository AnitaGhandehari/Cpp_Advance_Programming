
#ifndef A5_GLUE_H
#define A5_GLUE_H

#include "Tower.h"
#include <string>
#define GLUE_PIC_ADDRESS "Assets/towers/glue1.png"
#define GLUE_UPGRADE1_PIC_ADDRESS "Assets/towers/glue2.png"
#define GLUE_UPGRADE2_PIC_ADDRESS "Assets/towers/glue3.png"

class Glue: public Tower{
private:
    std::string glue_pic_address = GLUE_PIC_ADDRESS;
    int hit_power = 40;
    int upgrade_value = 45;
    int hit_time = 25;
public:
    Glue(Point glue_position);
    void put_tower_in_position(Window *_window) override;
    void upgrade_tower() override;
    bool arrange_shooting_time() override;
    void detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies) override;
    int get_enemy_upgrade_value() override{return upgrade_value;};
};


#endif //A5_GLUE_H
