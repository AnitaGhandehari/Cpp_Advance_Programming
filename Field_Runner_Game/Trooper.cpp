

#include "Trooper.h"

Trooper::Trooper(std::vector<Point> _enemy_way): Enemy(_enemy_way) , trooper_position(enemy_way[0])
{
    trooper_pic_address = THE_TROOPER_PIC_ADDRESS;
    enemy_speed = 3;
    enemy_life_value = 500;
    enemy_name = TROOPER;
    enemy_attack = 4;
    enemy_death_value = 8;
}

void Trooper::move(Window *_window)
{
    int distance = 0;
    int distance_from_end = 0;

    _window->draw_img(trooper_pic_address, Rectangle(trooper_position, 60, 60));
    double life_rect_width = enemy_life_value / 10;
    _window->fill_rect(Rectangle(Point(trooper_position.x , trooper_position.y + 5), life_rect_width, 5), GREEN);

    distance_from_end = sqrt(pow(abs(trooper_position.x - enemy_way[enemy_way.size()-1].x), 2) +
                             pow(abs(trooper_position.y - enemy_way[enemy_way.size()-1].y), 2));
    if(distance_from_end <= enemy_speed)
    {
        enemy_life_condition = ENEMY_REACHED_END;
    }
    distance = sqrt(pow(abs(trooper_position.x - enemy_way[next_position_index].x), 2) +
                    pow(abs(trooper_position.y - enemy_way[next_position_index].y), 2));
    if(distance <= enemy_speed)
    {
        trooper_position = enemy_way[next_position_index];
        next_position_index += 1;
    }
    if (enemy_way[next_position_index - 1].x != enemy_way[next_position_index].x)
    {
        trooper_position.x += enemy_speed;
        trooper_pic_address = THE_TROOPER_PIC_ADDRESS;
    }
    else if (enemy_way[next_position_index - 1].y != enemy_way[next_position_index].y)
    {
        if(enemy_way[next_position_index - 1].y < enemy_way[next_position_index].y)
        {
            trooper_position.y += enemy_speed;
            trooper_pic_address = THE_TROOPER_DOWN_PIC_ADDRESS;
        }
        else if(enemy_way[next_position_index - 1].y > enemy_way[next_position_index].y)
        {
            trooper_position.y -= enemy_speed;
            trooper_pic_address = THE_TROOPER_UP_PIC_ADDRESS;
        }

    }
    if(attack_by_glue)
    {
        if(enemy_low_speed_time > 0)
        {
            enemy_low_speed_time -= 1;
        }
        else
        {
            enemy_speed = recent_enemy_speed;
            attack_by_glue = false;
        }
    }

}

Point Trooper::get_enemy_position()
{
    Point center_trooper_position;
    center_trooper_position.x = trooper_position.x + 30;
    center_trooper_position.y = trooper_position.y + 30;
    return center_trooper_position;
}


void Trooper::set_life_value(int _hit)
{
    enemy_life_value = enemy_life_value - _hit;
    if(enemy_life_value <= 0)
        enemy_life_condition = ENEMY_DEAD;
}

