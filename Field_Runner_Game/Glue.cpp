
#include "Glue.h"
using namespace std;

Glue::Glue(Point gatling_position):Tower(gatling_position){}

void Glue::put_tower_in_position(Window *_window)
{
    _window->fill_rect(Rectangle(tower_room_position, 60, 60), RGB(141, 238, 238));
    _window->draw_rect(Rectangle(tower_room_position, 60, 60), RGB(82, 139, 139));
    _window->draw_img(glue_pic_address, Rectangle(tower_room_position,60,60));
}

void Glue::upgrade_tower()
{
    if(upgrade_level == 0)
    {
        glue_pic_address = GLUE_UPGRADE1_PIC_ADDRESS;
        hit_power += 10;
        hit_time += 5;
        upgrade_level += 1;
    }
    else if(upgrade_level == 1)
    {
        glue_pic_address = GLUE_UPGRADE2_PIC_ADDRESS;
        hit_power += 10;
        hit_time += 5;
        upgrade_level += 1;
    }
}

bool Glue::arrange_shooting_time()
{
    if(shooting_time >= 20)
    {
        shooting_time = 0;
        return true;
    }
    else{
        shooting_time += 1;
        return false;
    }
}

void Glue::detect_enemy_in_area_and_shoot(Window *_window ,std::vector<Enemy*> _enemies)
{
    Point enemy_position;
    double distance = 0;
    if(!_enemies.empty()) {
        for (int each_enemy = 0; each_enemy < _enemies.size(); each_enemy++) {
            enemy_position = _enemies[each_enemy]->get_enemy_position();

            distance = sqrt(pow(abs(enemy_position.x - tower_room_position.x), 2) +
                            pow(abs(enemy_position.y - tower_room_position.y), 2));
            if (distance < 130 && _enemies[each_enemy]->get_enemy_name() != STUBBORN) {
                _enemies[each_enemy]->set_speed_value(hit_power, hit_time);
                _window->draw_line(enemy_position, Point(tower_room_position.x + 30, tower_room_position.y + 30), YELLOW);
                _window->fill_circle(Point(enemy_position.x, enemy_position.y), 8, YELLOW);
            }
        }
    }
}
