
#include "Stubborn.h"

Stubborn::Stubborn(std::vector<Point> _enemy_way): Enemy(_enemy_way) , stubborn_position(enemy_way[0])
{
    stubborn_pic_address = THE_STUBBORN_PIC_ADDRESS;
    enemy_speed = 4;
    enemy_life_value = 400;
    enemy_name = STUBBORN;
    enemy_attack = 4;
    enemy_death_value = 10;
}

void Stubborn::move(Window *_window)
{

    _window->draw_img(stubborn_pic_address, Rectangle(stubborn_position, 60, 60));
    double life_rect_width = enemy_life_value / 10;
    _window->fill_rect(Rectangle(Point(stubborn_position.x , stubborn_position.y + 5), life_rect_width, 5), GREEN);

    if(stubborn_position.x == enemy_way[enemy_way.size()-1].x && stubborn_position.y == enemy_way[enemy_way.size()-1].y)
    {
        enemy_life_condition = ENEMY_REACHED_END;
    }

    if(stubborn_position.x == enemy_way[next_position_index].x && stubborn_position.y == enemy_way[next_position_index].y)
    {
        stubborn_position = enemy_way[next_position_index];
        next_position_index += 1;
    }
    if (enemy_way[next_position_index - 1].x != enemy_way[next_position_index].x)
    {
        stubborn_position.x += enemy_speed;
        stubborn_pic_address = THE_STUBBORN_PIC_ADDRESS;
    }
    else if (enemy_way[next_position_index - 1].y != enemy_way[next_position_index].y)
    {
        if(enemy_way[next_position_index - 1].y < enemy_way[next_position_index].y)
        {
            stubborn_position.y += enemy_speed;
            stubborn_pic_address = THE_STUBBORN_DOWN_PIC_ADDRESS;
        }
        else if(enemy_way[next_position_index - 1].y > enemy_way[next_position_index].y)
        {
            stubborn_position.y -= enemy_speed;
            stubborn_pic_address = THE_STUBBORN_UP_PIC_ADDRESS;
        }

    }
}

Point Stubborn::get_enemy_position()
{
    Point center_stubborn_position;
    center_stubborn_position.x = stubborn_position.x + 30;
    center_stubborn_position.y = stubborn_position.y + 30;
    return center_stubborn_position;
}

void Stubborn::set_life_value(int _hit)
{
    enemy_life_value = enemy_life_value - _hit;
    if(enemy_life_value < 0)
        enemy_life_condition = ENEMY_DEAD;
}