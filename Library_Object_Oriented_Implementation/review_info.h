
#ifndef A4_REVIEW_INFO_H
#define A4_REVIEW_INFO_H

#include "date.h"

class review_info{
private:
    int id;
    int book_id;
    int user_id;
    int rating;
    date date_of_review;
    int number_of_likes;
public:
    void set_id(int in_id);
    void set_book_id(int in_book_id);
    void set_user_id(int in_user_id);
    void set_rating(int in_rating);
    void set_date_of_review(date in_date_of_review);
    void set_number_of_likes(int in_number_of_likes);

    int get_id(){ return id; };
    int get_book_id(){ return book_id; };
    int get_user_id(){ return user_id; };
    int get_rating(){ return rating; };
    date get_date_of_review(){ return date_of_review; };
    int get_number_of_likes(){ return number_of_likes; };

};



#endif //A4_REVIEW_INFO_H
