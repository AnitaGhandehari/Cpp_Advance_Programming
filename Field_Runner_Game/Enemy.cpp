
#include "Enemy.h"
using namespace std;

Enemy::Enemy(vector<Point> _enemy_way)
{
    enemy_way = _enemy_way;
}

void Enemy::initial_enemy_life_value(int _level)
{
    enemy_life_value = enemy_life_value * (0.9 + 0.1 * (_level + 1));
}


void Enemy::set_speed_value(int _glue_hit , int _glue_time)
{
    if(!attack_by_glue)
    {
        enemy_low_speed_time = _glue_time;
        recent_enemy_speed = enemy_speed;
        enemy_speed = (_glue_hit * enemy_speed) / 100;
        attack_by_glue = true;
    }
}

