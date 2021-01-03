
#include "TheRunner.h"
using namespace std;
TheRunner::TheRunner(std::vector<Point> _enemy_way): Enemy(_enemy_way) , runner_position(enemy_way[0])
{
    runner_pic_address = THE_RUNNER_PIC_ADDRESS;
    enemy_speed = 5;
    enemy_life_value = 250;
    enemy_name = RUNNER;
    enemy_attack = 1;
    enemy_death_value = 6;
}

void TheRunner::move(Window *_window)
{
    int distance = 0;
    int distance_from_end = 0;
    _window->draw_img(runner_pic_address, Rectangle(runner_position, 60, 60));
    double life_rect_width = enemy_life_value / 10;
    _window->fill_rect(Rectangle(Point(runner_position.x , runner_position.y + 5), life_rect_width, 5), GREEN);

    distance_from_end = sqrt(pow(abs(runner_position.x - enemy_way[enemy_way.size()-1].x), 2) +
                             pow(abs(runner_position.y - enemy_way[enemy_way.size()-1].y), 2));
    if(distance_from_end <= enemy_speed)
    {
        enemy_life_condition = ENEMY_REACHED_END;
    }
    distance = sqrt(pow(abs(runner_position.x - enemy_way[next_position_index].x), 2) +
            pow(abs(runner_position.y - enemy_way[next_position_index].y), 2));

    if(distance <= enemy_speed)
    {
        runner_position = enemy_way[next_position_index];
        next_position_index += 1;
    }
    if (enemy_way[next_position_index - 1].x != enemy_way[next_position_index].x)
    {
        runner_position.x += enemy_speed;
        runner_pic_address = THE_RUNNER_PIC_ADDRESS;
    }
    else if (enemy_way[next_position_index - 1].y != enemy_way[next_position_index].y)
    {
        if(enemy_way[next_position_index - 1].y < enemy_way[next_position_index].y)
        {
            runner_position.y += enemy_speed;
            runner_pic_address = THE_RUNNER_DOWN_PIC_ADDRESS;
        }
        else if(enemy_way[next_position_index - 1].y > enemy_way[next_position_index].y)
        {
            runner_position.y -= enemy_speed;
            runner_pic_address = THE_RUNNER_UP_PIC_ADDRESS;
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

Point TheRunner::get_enemy_position()
{
    Point center_runner_position;
    center_runner_position.x = runner_position.x + 30;
    center_runner_position.y = runner_position.y + 30;
    return center_runner_position;
}

void TheRunner::set_life_value(int _hit)
{
    enemy_life_value -=_hit;
    if(enemy_life_value <= 0)
        enemy_life_condition = ENEMY_DEAD;
}
