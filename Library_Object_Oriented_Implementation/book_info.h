
#ifndef A4_BOOK_INFO_H
#define A4_BOOK_INFO_H
#include <string>

class book_info{
private:
    int id;
    std::string name;
    int author_id;
    std::string genre;
    float rating;
public:
    void set_id(int in_id);
    void set_name(std::string in_name);
    void set_author_id(int in_author_id);
    void set_genre(std::string in_genre);
    void set_rating(float in_rating);

    int get_id(){ return id; };
    std::string get_name(){ return name; };
    int get_author_id(){ return author_id; };
    std::string get_genre(){ return genre; };
    float get_rating(){ return rating; };

};

#endif //A4_BOOK_INFO_H
