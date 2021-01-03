
#ifndef A5_GAME_H
#define A5_GAME_H

#include "RSDL-master/src/rsdl.hpp"
#include "GameWindow.h"
#include "Gatling.h"
#include "Missile.h"
#include "Tesla.h"
#include "Glue.h"
#include "TheRunner.h"
#include "Stubborn.h"
#include "Scrambler.h"
#include "Trooper.h"
#include <sstream>
#include <stdlib.h>

#define WINDOW_HEIGHT 1024
#define WINDOW_WIDTH 1365
#define MOVE_PERMISSION_LIMIT 7
#define GATLING_KEY 'g'
#define GLUE_KEY 'l'
#define MISSILE_KEY 'm'
#define TESLA_KEY 't'
#define UPGRADE_KEY 'u'
#define FONT_ADDRESS "Assets/OpenSans.ttf"
#define ESPACE_DEVIDER ' '
#define MAIN_GAME_SONG "Extra/game_song.mp3"
#define SOUND_EFFECT "Extra/sound_effects/lose.mp3"

class Game{
private:
    GameWindow main_window;
    Window *window;
    std::vector<std::vector<EachRoom*>> rooms;
    std::vector<Tower*> towers;
    std::vector<Enemy*> enemies;
    std::vector<Enemy*> enemies_in_game;
    EachRoom *selected_room = nullptr;
    bool room_detected = false;
    std::vector<Point> enemies_way;
    std::vector<std::vector<int>> enemies_waves;
    int game_level = 0;
    int enemy_start_permission = 0;
    int life_value = 20;
    int money_value = 200;
    std::string end_of_game = "game";
    bool music_flag = false;

public:
    Game();
    void game_initialization();
    void draw_new_frame();
    void make_enemy_wave();
    void game_process();
    void detect_event();
    void put_selected_tower_in_position(Event _event);
    void put_gatling();
    void put_missile();
    void put_tesla();
    void put_glue();
    void exit_game();
    EachRoom* detect_tower_position(Event _event);
    void get_input();
    std::vector<Point> get_way(const std::string& _line);
    void get_enemies_waves(const std::string& _line);
    void arrange_full_enemy_way(std::vector<Point> _enemy_way_rooms);
    void go_forward_x(std::vector<Point> _enemy_way_rooms , int _each_room);
    void go_backward_x(std::vector<Point> _enemy_way_rooms , int _each_room);
    void go_forward_y(std::vector<Point> _enemy_way_rooms , int _each_room);
    void go_backward_y(std::vector<Point> _enemy_way_rooms , int _each_room);
    void start_each_enemy_move();
    void draw_way();
    void draw_life_value();
    void draw_money_value();
    void manage_enemy_tower();
    void manage_game_process_drawing();
    void manage_music_effects();
};

#endif //A5_GAME_H
