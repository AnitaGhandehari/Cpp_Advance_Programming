#include <iostream>
#include "functions.h"
#include "goodreads.h"
#include "review_info.h"

using namespace std;

int main(int argc, char *argv[]) {

    string first_instruction;
    string instruction_shelf_type;
    string instruction_selected_genres;
    int instruction_author_id;
    int instruction_user_id;
    goodreads all_goodreads_info;


    all_goodreads_info.set_all_goodreads_user_info(read_users_file(argv));
    all_goodreads_info.set_all_goodreads_author_info(read_author_file(argv));
    all_goodreads_info.set_all_goodreads_book_info(read_books_file(argv));
    all_goodreads_info.set_all_goodreads_review_info(read_review_file(argv));
    all_goodreads_info.set_all_goodreads_follower_info(read_follower_file(argv));


    cin >> first_instruction;
    if(first_instruction == "show_author_info")
    {
        cin >> instruction_author_id;
        all_goodreads_info.scroll_author_data(instruction_author_id);
    }
    else if(first_instruction == "show_sorted_shelf")
    {
        cin >> instruction_user_id;
        cin >> instruction_shelf_type;
        cin >> instruction_selected_genres;
        all_goodreads_info.show_sorted_lib(instruction_user_id , instruction_shelf_type , instruction_selected_genres);
    }
    else if(first_instruction == "credit")
    {
        float credit = 0;
        cin >> instruction_user_id;
        credit = all_goodreads_info.calculate_credit(instruction_user_id);
        cout << credit << endl;
    }
    else if(first_instruction == "best_book")
    {
        all_goodreads_info.find_best_book();
    }
    else if(first_instruction == "best_reviewer")
    {
        all_goodreads_info.find_best_reviewer();
    }
    else if(first_instruction == "recommend_first_approach")
    {
        cin >> instruction_user_id;
        all_goodreads_info.find_recommended_first_approach(instruction_user_id);
    }
    else if(first_instruction == "recommend_second_approach")
    {
        cin >> instruction_user_id;
        all_goodreads_info.find_recommend_second_approach(instruction_user_id);
    }



    return 0;
}
