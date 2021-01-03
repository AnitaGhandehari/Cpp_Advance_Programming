
#ifndef A5_ENEMY_H
#define A5_ENEMY_H

#include "RSDL-master/src/rsdl.hpp"
#include <vector>

#define ENEMY_DEAD "enemy_died"
#define ENEMY_REACHED_END "enemy_reached_end"
#define ENEMY_IS_ALIVE "enemy_is_alive"
#define RUNNER "runner"
#define STUBBORN "stubborn"
#define SCRAMBLER "scrambler"
#define TROOPER "trooper"

class Enemy{
protected:
    std::vector<Point> enemy_way;
    int enemy_speed = 0;
    int recent_enemy_speed = 0;
    double enemy_life_value = 0;
    std::string enemy_life_condition = ENEMY_IS_ALIVE;
    std::string enemy_name;
    int enemy_attack;
    int enemy_death_value;
    bool attack_by_glue = false;
    int enemy_low_speed_time;
public:
    Enemy(std::vector<Point> _enemy_way);
    virtual void move(Window *_window) = 0;
    virtual Point get_enemy_position() = 0;
    virtual void set_life_value(int _hit) = 0;
    void set_speed_value(int _glue_hit , int _glue_time);
    void initial_enemy_life_value(int _level);
    std::string get_enemy_condition() { return enemy_life_condition; };
    std::string get_enemy_name() { return enemy_name; };
    int get_enemy_attack(){ return enemy_attack; };
    int get_enemy_death_prize() { return enemy_death_value; };
};

#endif //A5_ENEMY_H
