#include <vector>

#ifndef A4_GOODREADS_H
#define A4_GOODREADS_H

#include "functions.h"
#include "user_info.h"
#include "author_info.h"
#include "book_info.h"
#include "follower_info.h"
#include "date.h"

class goodreads{
private:
    std::vector<user_info> all_goodreads_user_info;
    std::vector<author_info> all_goodreads_author_info;
    std::vector<book_info> all_goodreads_book_info;
    std::vector<review_info> all_goodreads_review_info;
    std::vector<follower_info> all_goodreads_follower_info;
public:
    void set_all_goodreads_user_info( std::vector<user_info> in_all_goodreads_user_info);
    void set_all_goodreads_author_info( std::vector<author_info> in_all_goodreads_author_info);
    void set_all_goodreads_book_info( std::vector<book_info> in_all_goodreads_book_info);
    void set_all_goodreads_review_info( std::vector<review_info> in_all_goodreads_review_info);
    void set_all_goodreads_follower_info( std::vector<follower_info> in_all_goodreads_follower_info);

    void scroll_author_data(int author_id);
    void show_sorted_lib(int user_id , std::string user_shelf_type , std::string selected_genres);
    float calculate_credit(int user_id);
    void find_best_book();
    void find_best_reviewer();
    void find_recommended_first_approach(int user_id);
    std::vector<user_info> find_follower_path(std::vector<user_info> follower_path , int user_id);
    std::vector<book_info> find_best_three_book_of_following(std::vector<book_info> chosen_books , std::vector<user_info> follower_path);
    void find_recommend_second_approach(int user_id);

};

#endif //A4_GOODREADS_H
