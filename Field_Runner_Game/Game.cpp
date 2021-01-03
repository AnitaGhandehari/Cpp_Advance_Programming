
#include "Game.h"
using namespace std;
Game::Game():main_window(WINDOW_WIDTH , WINDOW_HEIGHT)
{
    window = main_window.get_window();
}

void Game::game_initialization()
{
    main_window.draw_background_image();
    main_window.assign_rooms();
    rooms = main_window.get_rooms();
    get_input();
    make_enemy_wave();
}

void Game::exit_game()
{
    exit(0);
}

EachRoom* Game::detect_tower_position(Event _event)
{
    EachRoom *selected_room_for_tower = nullptr;
    Point mouse_point = _event.get_mouse_position();
    for (int each_room_col = 0 ; each_room_col < rooms.size() ; each_room_col++)
    {
        for(int each_room_row = 0 ; each_room_row < rooms[each_room_col].size() ; each_room_row++)
        {
            if (rooms[each_room_col][each_room_row]->contain_in_room(mouse_point))
            {
                selected_room_for_tower = rooms[each_room_col][each_room_row];
                return selected_room_for_tower;
            }
        }
    }
    return selected_room_for_tower;
}

void Game::put_gatling()
{
    Gatling *gatling1 = new Gatling(selected_room->get_room_left_up());
    selected_room->set_tower_in_room(gatling1);
    towers.push_back(gatling1);
    room_detected = false;
}

void Game::put_missile()
{
    Missile *missile1 = new Missile(selected_room->get_room_left_up());
    selected_room->set_tower_in_room(missile1);
    towers.push_back(missile1);
    room_detected = false;
}

void Game::put_tesla()
{
    Tesla *tesla1 = new Tesla(selected_room->get_room_left_up());
    selected_room->set_tower_in_room(tesla1);
    towers.push_back(tesla1);
    room_detected = false;
}

void Game::put_glue()
{
    Glue *glue1 = new Glue(selected_room->get_room_left_up());
    selected_room->set_tower_in_room(glue1);
    towers.push_back(glue1);
    room_detected = false;
}

void Game::put_selected_tower_in_position(Event _event)
{
    char pressed_char = _event.get_pressed_key();
    if(selected_room->show_room_condition() == 0 && room_detected)
    {
        if(pressed_char == GATLING_KEY) {
            if(money_value - 55 > 0 && !selected_room->is_this_room_in_enemy_way())
            {
                put_gatling();
                money_value -= 55;
            }
        }
        else if(pressed_char == MISSILE_KEY && !selected_room->is_this_room_in_enemy_way()) {
            if(money_value - 70 > 0) {
                put_missile();
                money_value -= 70;
            }
        }
        else if(pressed_char == GLUE_KEY && !selected_room->is_this_room_in_enemy_way())
        {
            if(money_value - 60 > 0) {
                put_glue();
                money_value -= 60;
            }
        }

        else if(pressed_char == TESLA_KEY && !selected_room->is_this_room_in_enemy_way()) {
            if(money_value - 120 > 0)
            {
                put_tesla();
                money_value -= 120;
            }
        }
    }
    else if(selected_room->show_room_condition() == 1)
    {
        if(pressed_char == UPGRADE_KEY)
        {
            if(money_value - selected_room->get_tower_in_room_upgrade_value() > 0)
            {
                money_value -= selected_room->get_tower_in_room_upgrade_value();
                selected_room->upgrade_tower_in_room();
            }
        }
    }
}

void Game::detect_event()
{
    while (window->has_pending_event())
    {
        Event event = window->poll_for_event();
        switch (event.get_type())
        {
            case Event::QUIT:
                exit_game();

            case Event::LCLICK:
                selected_room = detect_tower_position(event);
                room_detected = true;

            case Event::KEY_PRESS:
                put_selected_tower_in_position(event);
        }
    }
}

void Game::draw_way()
{
    for (int each_way_room = 0 ; each_way_room < enemies_way.size() ; each_way_room++)
    {
        window->fill_rect(Rectangle(enemies_way[each_way_room], 60, 60), RGB(193 ,255 ,193));
        window->draw_rect(Rectangle(enemies_way[each_way_room], 60, 60), RGB(105 ,139 ,105));
        window->show_text("END", Point(enemies_way[enemies_way.size()-1].x + 15, enemies_way[enemies_way.size()-1].y + 15)
                , RGB(0,0,120), FONT_ADDRESS, 15);
        window->show_text("START", Point(enemies_way[0].x + 15, enemies_way[0].y + 15)
                , RGB(0,0,120), FONT_ADDRESS, 15);
    }
}

void Game::draw_new_frame()
{
    main_window.draw_background_image();
    draw_life_value();
    draw_money_value();
    draw_way();
    start_each_enemy_move();
    manage_game_process_drawing();
    window->update_screen();
}

void Game::go_forward_x(vector<Point> _enemy_way_rooms , int _each_room)
{

    if (_enemy_way_rooms[_each_room + 1].x > _enemy_way_rooms[_each_room].x
        && (_enemy_way_rooms[_each_room + 1].x - _enemy_way_rooms[_each_room].x) > 1)
    {
        int diff = _enemy_way_rooms[_each_room + 1].x - _enemy_way_rooms[_each_room].x;
        for (int i = 1; i < diff; i++)
        {
            enemies_way.push_back(
                    rooms[_enemy_way_rooms[_each_room].x + i][_enemy_way_rooms[_each_room].y]->get_room_left_up());
            rooms[_enemy_way_rooms[_each_room].x + i][_enemy_way_rooms[_each_room].y]->set_room_in_enemy_way();
        }
    }
}

void Game::go_backward_x(vector<Point> _enemy_way_rooms , int _each_room)
{

    if (_enemy_way_rooms[_each_room + 1].x < _enemy_way_rooms[_each_room].x
        && (_enemy_way_rooms[_each_room].x - _enemy_way_rooms[_each_room + 1].x) > 1)
    {
        int diff = _enemy_way_rooms[_each_room].x - _enemy_way_rooms[_each_room + 1].x;
        for (int i = 1; i < diff; i++)
        {
            enemies_way.push_back(
                    rooms[_enemy_way_rooms[_each_room].x - i][_enemy_way_rooms[_each_room].y]->get_room_left_up());
            rooms[_enemy_way_rooms[_each_room].x - i][_enemy_way_rooms[_each_room].y]->set_room_in_enemy_way();
        }
    }
}

void Game::go_forward_y(vector<Point> _enemy_way_rooms, int _each_room)
{

    if (_enemy_way_rooms[_each_room + 1].y > _enemy_way_rooms[_each_room].y
        && (_enemy_way_rooms[_each_room + 1].y - _enemy_way_rooms[_each_room].y) > 1)
    {
        int diff = _enemy_way_rooms[_each_room + 1].y - _enemy_way_rooms[_each_room].y;
        for (int i = 1; i < diff; i++) {
            enemies_way.push_back(
                    rooms[_enemy_way_rooms[_each_room].x][_enemy_way_rooms[_each_room].y + i]->get_room_left_up());
            rooms[_enemy_way_rooms[_each_room].x][_enemy_way_rooms[_each_room].y + i]->set_room_in_enemy_way();
        }
    }
}

void Game::go_backward_y(vector<Point> _enemy_way_rooms, int _each_room)
{

    if(_enemy_way_rooms[_each_room + 1].y < _enemy_way_rooms[_each_room].y
       && (_enemy_way_rooms[_each_room].y - _enemy_way_rooms[_each_room + 1].y) > 1)
    {
        int diff = _enemy_way_rooms[_each_room].y - _enemy_way_rooms[_each_room + 1].y;
        for (int i = 1; i < diff; i++) {
            enemies_way.push_back(
                    rooms[_enemy_way_rooms[_each_room].y][_enemy_way_rooms[_each_room].y - i]->get_room_left_up());
            rooms[_enemy_way_rooms[_each_room].y][_enemy_way_rooms[_each_room].y - i]->set_room_in_enemy_way();
        }
    }
}

void Game::arrange_full_enemy_way(vector<Point> _enemy_way_rooms)
{
    for(int each_room = 0 ; each_room < _enemy_way_rooms.size() - 1; each_room++)
    {
        enemies_way.push_back(rooms[_enemy_way_rooms[each_room].x][_enemy_way_rooms[each_room].y]->get_room_left_up());
        rooms[_enemy_way_rooms[each_room].x][_enemy_way_rooms[each_room].y]->set_room_in_enemy_way();
        if(_enemy_way_rooms[each_room].x != _enemy_way_rooms[each_room + 1].x)
        {

            go_forward_x(_enemy_way_rooms , each_room);
            go_backward_x(_enemy_way_rooms , each_room);
        }
        else if(_enemy_way_rooms[each_room].y != _enemy_way_rooms[each_room + 1].y)
        {
            go_forward_y(_enemy_way_rooms , each_room);
            go_backward_y(_enemy_way_rooms , each_room);
        }
    }
    enemies_way.push_back(rooms[_enemy_way_rooms[_enemy_way_rooms.size()-1].x][_enemy_way_rooms[_enemy_way_rooms.size()-1].y]->get_room_left_up());
    rooms[_enemy_way_rooms[_enemy_way_rooms.size()-1].x][_enemy_way_rooms[_enemy_way_rooms.size()-1].y]->set_room_in_enemy_way();
}

vector<Point> Game::get_way(const string& _line)
{
    bool choose_x_y = false;
    Point each_way_room(0,0);
    vector<Point> enemy_way_rooms;
    string each_point_part;

    stringstream s(_line);
    while (getline(s, each_point_part, ESPACE_DEVIDER))
    {
        if (!choose_x_y) {
            each_way_room.x = stoi(each_point_part);
            choose_x_y = true;
        } else
        {
            each_way_room.y = stoi(each_point_part);
            enemy_way_rooms.push_back(each_way_room);
            choose_x_y = false;
        }
    }
    return enemy_way_rooms;
}

void Game:: get_enemies_waves(const std::string &_line)
{
    vector<int> enemies;
    for(char each_part : _line)
    {
        if(each_part != ESPACE_DEVIDER)
        {
            enemies.push_back((int(each_part) - '0'));
        }
    }
    enemies_waves.push_back(enemies);
}

void Game::get_input()
{
    int line_number = 1;

    for (string line; getline(cin, line);)
    {
        vector<Point> way;

        if(line_number == 1)
        {
            way = get_way(line);
            arrange_full_enemy_way(way);
            line_number += 1;
        }
        else
        {
            get_enemies_waves(line);
        }
    }
}

void Game::make_enemy_wave()
{
    for(int each_runner = 0 ; each_runner < enemies_waves[0][0] ; each_runner++)
    {
        TheRunner *runner1 = new TheRunner(enemies_way);
        runner1->initial_enemy_life_value(game_level);
        enemies.push_back(runner1);
    }
    for(int each_stubborn = 0 ; each_stubborn < enemies_waves[0][1] ; each_stubborn++)
    {
        Stubborn *stubborn1 = new Stubborn(enemies_way);
        stubborn1->initial_enemy_life_value(game_level);
        enemies.push_back(stubborn1);
    }
    for(int each_trooper = 0 ; each_trooper < enemies_waves[0][2] ; each_trooper++)
    {
        Trooper *trooper1 = new Trooper(enemies_way);
        trooper1->initial_enemy_life_value(game_level);
        enemies.push_back(trooper1);
    }
    for(int each_scrambler = 0 ; each_scrambler < enemies_waves[0][3] ; each_scrambler++)
    {
        Scrambler *scrambler1 = new Scrambler(enemies_way);
        scrambler1->initial_enemy_life_value(game_level);
        enemies.push_back(scrambler1);
    }
}

void Game::start_each_enemy_move()
{
    int random_enemy_index = 0;
    if(!enemies.empty())
    {
        srand(enemy_start_permission);
        if (enemy_start_permission >= MOVE_PERMISSION_LIMIT)
        {
            random_enemy_index = random() % enemies.size();
            enemies_in_game.push_back(enemies[random_enemy_index]);
            enemies.erase(enemies.begin() + random_enemy_index);
            enemy_start_permission = 0;
        }
        enemy_start_permission++;
    }
}

void Game::game_process()
{
    window->play_music(MAIN_GAME_SONG);
    int duration_between_enemy_waves = 0;
    while(true)
    {
        if((enemies_in_game.empty()) && (game_level < enemies_waves.size()))
        {
            if(duration_between_enemy_waves >= 30)
            {
                duration_between_enemy_waves = 0;
                game_level++;
                make_enemy_wave();
            }
            else
                duration_between_enemy_waves++;
        }
        manage_music_effects();
        detect_event();
        draw_new_frame();
        delay(100);
    }
}

void Game::draw_life_value()
{
    window->fill_rect(Rectangle(65, 74, 120, 50), RGB(130,0,0));
    window->show_text("Life: ", Point(80, 80), BLACK, FONT_ADDRESS, 25);
    window->show_text((to_string(life_value)), Point(140, 80), RGB(0,0,120), FONT_ADDRESS, 25);
}

void Game::draw_money_value()
{
    window->fill_rect(Rectangle(1200, 74, 150, 50), RGB(255,215,0));
    window->show_text("Money: ", Point(1205, 80), BLACK, FONT_ADDRESS, 25);
    window->show_text((to_string(money_value)), Point(1300, 80), RGB(0,0,120), FONT_ADDRESS, 25);

}

void Game::manage_enemy_tower()
{
    for (int i = 0; i < enemies_in_game.size(); i++) {
        if (enemies_in_game[i]->get_enemy_condition() == ENEMY_DEAD) {
            money_value += enemies_in_game[i]->get_enemy_death_prize();
            enemies_in_game.erase(enemies_in_game.begin() + i);
        }
        else if (enemies_in_game[i]->get_enemy_condition() == ENEMY_REACHED_END) {
            life_value -= enemies_in_game[i]->get_enemy_attack();
            if(life_value < 0)
                life_value = 0;
            enemies_in_game.erase(enemies_in_game.begin() + i);
        }
        else if (enemies_in_game[i]->get_enemy_condition() == ENEMY_IS_ALIVE) {
            enemies_in_game[i]->move(window);
        }
    }
    for (int i = 0; i < towers.size(); i++) {
        towers[i]->put_tower_in_position(window);
        if (towers[i]->arrange_shooting_time())
            towers[i]->detect_enemy_in_area_and_shoot(window, enemies_in_game);
    }
}

void Game::manage_game_process_drawing()
{
    if(life_value > 0 && (game_level < enemies_waves.size()) && end_of_game == "game")
        manage_enemy_tower();
    else if(life_value <= 0)
    {
        main_window.draw_lose_image();
        end_of_game = "lose";
    }

    else if(((life_value > 0) && (game_level == enemies_waves.size()) && (enemies_in_game.empty())) || end_of_game == "win")
    {
        main_window.draw_win_image();
        end_of_game = "win";
    }
}

void Game::manage_music_effects()
{
    if((end_of_game == "lose" || end_of_game == "win") && !music_flag)
    {
        window->stop_music();
        window->play_music(SOUND_EFFECT);
        music_flag = true;
        delay(4000);
        window->stop_music();
        delay(1000);
        exit(0);
    }
}