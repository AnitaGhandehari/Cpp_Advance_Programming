
#include "Missile.h"

Missile::Missile(Point missile_position):Tower(missile_position){}

void Missile::put_tower_in_position(Window *_window)
{
    _window->fill_rect(Rectangle(tower_room_position, 60, 60), RGB(171, 130, 255));
    _window->draw_rect(Rectangle(tower_room_position, 60, 60), RGB(93, 71, 139));
    _window->draw_img(missile_pic_address, Rectangle(tower_room_position,60,60));
}

void Missile::upgrade_tower()
{
    if(upgrade_level == 0)
    {
        missile_pic_address = MISSILE_UPGRADE1_PIC_ADDRESS;
        hit_power += 75;
        upgrade_level += 1;
    }
    else if(upgrade_level == 1)
    {
        missile_pic_address = MISSILE__UPGRADE2_PIC_ADDRESS;
        hit_power += 75;
        upgrade_level += 1;
    }
}

bool Missile::arrange_shooting_time()
{
    if(shooting_time >= 30)
    {
        shooting_time = 0;
        return true;
    }
    else{
        shooting_time += 1;
        return false;
    }
}

void Missile::detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies)
{
    Point enemy_position;
    double distance = 0;
    for(int each_enemy = 0 ; each_enemy < _enemies.size() ; each_enemy++)
    {
        enemy_position = _enemies[each_enemy]->get_enemy_position();
        distance = sqrt(pow(abs(enemy_position.x - tower_room_position.x) , 2) +
                        pow(abs(enemy_position.y - tower_room_position.y) , 2));
        if(distance < 150)
        {
            _enemies[each_enemy]->set_life_value(hit_power);
            _window->draw_line(enemy_position, Point(tower_room_position.x + 30, tower_room_position.y + 30), RED);
            _window->fill_circle(Point(enemy_position.x, enemy_position.y), 8, RED);
        }
    }
}
