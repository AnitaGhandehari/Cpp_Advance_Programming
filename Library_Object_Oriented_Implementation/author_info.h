
#ifndef A4_AUTHOR_INFO_H
#define A4_AUTHOR_INFO_H

#include "date.h"
#include <vector>

class author_info{
private:
    int id;
    std::string name;
    std::string gender;
    date member_since;
    int year_of_birth;
    std::string place_of_birth;
    std::vector<std::string> genres;

public:
    void set_id(int in_id);
    void set_name(std::string in_name);
    void set_gender(std::string in_gender);
    void set_member_since(date member_since);
    void set_year_of_birth(int in_year_of_birth);
    void set_place_of_birth(std::string in_place_of_birth);
    void set_genres(std::vector<std::string> in_genres);

    int get_id(){ return id; };
    std::string get_name(){ return name; };
    std::string get_gender(){ return gender; };
    date get_member_since(){ return member_since; };
    int get_year_of_birth() {return year_of_birth; };
    std::string get_place_of_birth(){ return place_of_birth; };
    std::vector<std::string> get_genres(){ return genres; };



};


#endif //A4_AUTHOR_INFO_H
