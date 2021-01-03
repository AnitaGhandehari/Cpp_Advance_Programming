
#include "Scrambler.h"

Scrambler::Scrambler(std::vector<Point> _enemy_way): Enemy(_enemy_way) , scrambler_position(enemy_way[0])
{
    scrambler_pic_address = THE_SCRAMBLER_PIC_ADDRESS;
    enemy_speed = 10;
    enemy_life_value = 100;
    enemy_name = SCRAMBLER;
    enemy_attack = 2;
    enemy_death_value = 4;
}

void Scrambler::move(Window *_window)
{
    int distance = 0;
    int distance_from_end = 0;
    _window->draw_img(scrambler_pic_address, Rectangle(scrambler_position, 60, 60));
    double life_rect_width = enemy_life_value / 10;
    _window->fill_rect(Rectangle(Point(scrambler_position.x , scrambler_position.y + 5), life_rect_width, 5), GREEN);

    distance_from_end = sqrt(pow(abs(scrambler_position.x - enemy_way[enemy_way.size()-1].x), 2) +
                    pow(abs(scrambler_position.y - enemy_way[enemy_way.size()-1].y), 2));
    if(distance_from_end <= enemy_speed)
    {
        enemy_life_condition = ENEMY_REACHED_END;
    }
    distance = sqrt(pow(abs(scrambler_position.x - enemy_way[next_position_index].x), 2) +
                    pow(abs(scrambler_position.y - enemy_way[next_position_index].y), 2));
    if(distance <= enemy_speed)
    {
        scrambler_position = enemy_way[next_position_index];
        next_position_index += 1;
    }
    if (enemy_way[next_position_index - 1].x != enemy_way[next_position_index].x)
    {
        scrambler_position.x += enemy_speed;
        scrambler_pic_address = THE_SCRAMBLER_PIC_ADDRESS;
    }
    else if (enemy_way[next_position_index - 1].y != enemy_way[next_position_index].y)
    {
        if(enemy_way[next_position_index - 1].y < enemy_way[next_position_index].y)
        {
            scrambler_position.y += enemy_speed;
            scrambler_pic_address = THE_SCRAMBLER_DOWN_PIC_ADDRESS;
        }
        if(enemy_way[next_position_index - 1].y > enemy_way[next_position_index].y)
        {
            scrambler_position.y -= enemy_speed;
            scrambler_pic_address = THE_SCRAMBLER_UP_PIC_ADDRESS;
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

Point Scrambler::get_enemy_position()
{
    Point center_scrambler_position;
    center_scrambler_position.x = scrambler_position.x + 30;
    center_scrambler_position.y = scrambler_position.y + 30;
    return center_scrambler_position;
}

void Scrambler::set_life_value(int _hit)
{
    enemy_life_value = enemy_life_value - _hit;
    if(enemy_life_value <= 0)
        enemy_life_condition = ENEMY_DEAD;
}