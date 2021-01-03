
#ifndef A4_USER_INFO_H
#define A4_USER_INFO_H

#include "date.h"
#include <vector>

class user_info{
private:
    int id;
    std::string name;
    std::string place_of_birth;
    date member_since;
    std::vector<int> favorite_authors;
    std::vector<std::string> favorite_genres;
    std::vector<int> want_to_read;
    std::vector<int> currently_reading;
    std::vector<int> read;
public:
    void set_id(int in_id);
    void set_name(std::string in_name);
    void set_place_of_birth(std::string in_place_of_birth);
    void set_member_since(date member_since);
    void set_favorite_authors(std::vector<int> in_favorite_authors);
    void set_favorite_genres(std::vector<std::string> in_favorite_genres);
    void set_want_to_read(std::vector<int> in_want_to_read);
    void set_currently_reading(std::vector<int> in_currently_reading);
    void set_read(std::vector<int> in_read);

    int get_id(){ return id; };
    std::string get_name(){ return name; };
    std::string get_place_of_birth(){ return place_of_birth; };
    date get_member_since(){ return member_since; };
    std::vector<int> get_favorite_authors(){ return favorite_authors; };
    std::vector<std::string> get_favorite_genres(){ return favorite_genres; };
    std::vector<int> get_want_to_read(){ return want_to_read; };
    std::vector<int> get_currently_reading(){ return currently_reading; };
    std::vector<int> get_read(){ return read; };

};


#endif //A4_USER_INFO_H
