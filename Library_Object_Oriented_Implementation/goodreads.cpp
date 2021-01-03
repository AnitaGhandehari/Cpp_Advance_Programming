#include "goodreads.h"
#include <iostream>
using namespace std;

void goodreads::set_all_goodreads_user_info(vector<user_info> in_all_goodreads_user_info)
{
    all_goodreads_user_info = in_all_goodreads_user_info;
}

void goodreads::set_all_goodreads_author_info(vector<author_info> in_all_goodreads_author_info)
{
    all_goodreads_author_info = in_all_goodreads_author_info;
}

void goodreads::set_all_goodreads_book_info( std::vector<book_info> in_all_goodreads_book_info)
{
    all_goodreads_book_info = in_all_goodreads_book_info;
}

void goodreads::set_all_goodreads_review_info( std::vector<review_info> in_all_goodreads_review_info)
{
    all_goodreads_review_info = in_all_goodreads_review_info;
}

void goodreads::set_all_goodreads_follower_info(vector<follower_info> in_all_goodreads_follower_info)
{
    all_goodreads_follower_info = in_all_goodreads_follower_info;
}


void goodreads::scroll_author_data(int author_id)
{
    for(int i = 0 ; i < all_goodreads_author_info.size() ; i++)
    {
        if(all_goodreads_author_info[i].get_id() == author_id)
        {
            cout << "id: " << all_goodreads_author_info[i].get_id() << endl;
            cout << "Name: " << all_goodreads_author_info[i].get_name() << endl;
            cout << "Year of Birth: " << all_goodreads_author_info[i].get_year_of_birth() << endl;
            cout << "Place of Birth: " << all_goodreads_author_info[i].get_place_of_birth() << endl;
            cout << "Member Since: "; all_goodreads_author_info[i].get_member_since().print_info();
            cout << "Genres: ";
            for(int j = 0 ; j < all_goodreads_author_info[i].get_genres().size() ; j++)
            {
                cout << all_goodreads_author_info[i].get_genres()[j];
                if(j != (all_goodreads_author_info[i].get_genres().size()-1))
                    cout << ",";
            }
            cout << endl;
        }
    }
    cout << "Books:" << endl;
    for(int a = 0 ; a < all_goodreads_book_info.size() ; a++)
    {
        if(all_goodreads_book_info[a].get_author_id() == author_id)
        {
            cout << "id: " << all_goodreads_book_info[a].get_id() << " " << "Title: " << all_goodreads_book_info[a].get_name() << endl;
        }
    }
}


void goodreads::show_sorted_lib(int user_id , string user_shelf_type , string selected_genres)
{
    user_info selected_user;
    vector<int> book_id_list;
    vector<book_info> book_object_list;

    for(int i = 0 ; i < all_goodreads_user_info.size() ; i++)
    {
        if(all_goodreads_user_info[i].get_id() == user_id)
        {
            selected_user = all_goodreads_user_info[i];

            break;
        }
    }

    if(user_shelf_type == "want_to_read")
    {
        book_id_list = selected_user.get_want_to_read();
    }
    else if(user_shelf_type == "currently_reading")
    {
        book_id_list = selected_user.get_currently_reading();

    }
    else if(user_shelf_type == "read")
    {
        book_id_list = selected_user.get_read();
    }

    for(int i = 0 ; i < book_id_list.size(); i++)
    {
        for(int j = 0 ; j < all_goodreads_book_info.size() ; j++)
        {
            if(book_id_list[i] == all_goodreads_book_info[j].get_id())
            {
                book_object_list.push_back(all_goodreads_book_info[j]);
            }
        }
    }
    sort(book_object_list.begin(), book_object_list.end(), compare_genres);
    for(int i = 0 ; i < book_object_list.size() ; i++)
    {
        if(book_object_list[i].get_genre() == selected_genres)
        {
            cout << "id: " << book_object_list[i].get_id() << endl;
            cout << "Title: " << book_object_list[i].get_name() << endl;
            cout << "Genre: " << book_object_list[i].get_genre() << endl;
            for(int j = 0 ; j < all_goodreads_author_info.size() ; j++)
            {
                if(all_goodreads_author_info[j].get_id() == book_object_list[i].get_author_id())
                {
                    cout << "Author: " << all_goodreads_author_info[j].get_name() << endl;
                }
            }
            cout << "***" << endl;
        }
    }

    for(int i = 0 ; i < book_object_list.size() ; i++)
    {
        if(book_object_list[i].get_genre() != selected_genres)
        {
            cout << "id: " << book_object_list[i].get_id() << endl;
            cout << "Title: " << book_object_list[i].get_name() << endl;
            cout << "Genre: " << book_object_list[i].get_genre() << endl;
            for(int j = 0 ; j < all_goodreads_author_info.size() ; j++)
            {
                if(all_goodreads_author_info[j].get_id() == book_object_list[i].get_author_id())
                {
                    cout << "Author: " << all_goodreads_author_info[j].get_name() << endl;
                }
            }
            cout << "***" << endl;
        }
    }

}


float goodreads::calculate_credit(int user_id)
{

    int number_of_reviews = all_goodreads_review_info.size();
    int number_of_likes = 0;
    float credit = 0;

    int number_of_user_reviews = 0;
    int number_of_user_reviews_likes = 0;

    for(int i = 0 ; i < all_goodreads_review_info.size() ; i++)
    {
        number_of_likes += all_goodreads_review_info[i].get_number_of_likes();
    }

    for(int i = 0 ; i < all_goodreads_review_info.size() ; i++)
    {
        if(user_id == all_goodreads_review_info[i].get_user_id())
        {
            number_of_user_reviews += 1;
            number_of_user_reviews_likes += all_goodreads_review_info[i].get_number_of_likes();
        }
    }

    if((number_of_likes == 0) || (number_of_reviews == 0))
    {
        credit = 0;
    }
    else
    {
       credit = float(float(float(static_cast<float>(number_of_user_reviews) / static_cast<float>(number_of_reviews)) +
                             float(static_cast<float>(number_of_user_reviews_likes) / static_cast<float>(number_of_likes))) / 2);
       credit = roundf( credit * 1000000);
       credit = float(credit / 1000000);

    }


    return credit;
}

void goodreads::find_best_book()
{
    book_info best_book;
    int number_of_each_book_rate = 0;
    int total_rate_of_book = 0;
    float max_average_rate = 0;
    float max_average_rate_new = 0;
    for(int i = 0 ; i < all_goodreads_book_info.size() ; i++)
    {
        for(int j = 0 ; j < all_goodreads_review_info.size() ; j++)
        {
            if(all_goodreads_book_info[i].get_id() == all_goodreads_review_info[j].get_book_id())
            {
                total_rate_of_book += all_goodreads_review_info[j].get_rating();
                number_of_each_book_rate += 1;
            }
        }

        if(number_of_each_book_rate == 0)
        {
            max_average_rate_new = 0;
        }
        else
        {
            max_average_rate_new = float(round(float(static_cast<float> (total_rate_of_book) / static_cast<float> (number_of_each_book_rate)) * 100) / 100);
        }


        total_rate_of_book = 0;
        number_of_each_book_rate = 0;
        if(max_average_rate < max_average_rate_new)
        {
            max_average_rate = max_average_rate_new;
            best_book = all_goodreads_book_info[i];
        }
    }

    cout << "id: " << best_book.get_id() << endl;
    cout << "Title: " << best_book.get_name() << endl;
    cout << "Genre: " << best_book.get_genre() << endl;
    for(int j = 0 ; j < all_goodreads_author_info.size() ; j++)
    {
        if (all_goodreads_author_info[j].get_id() == best_book.get_author_id())
        {
            cout << "Author: " << all_goodreads_author_info[j].get_name() << endl;
        }
    }
    cout << "Average Rating: " << max_average_rate << endl;
}

void goodreads::find_best_reviewer()
{
    int number_of_likes = 0;
    int new_number_of_likes = 0;
    user_info best_reviewer;

    for(int i = 0 ; i < all_goodreads_user_info.size() ; i++)
    {
        for(int j = 0 ; j < all_goodreads_review_info.size() ; j++)
        {
            if(all_goodreads_user_info[i].get_id() == all_goodreads_review_info[j].get_user_id())
            {
                new_number_of_likes += all_goodreads_review_info[j].get_number_of_likes();
            }
        }
        if(new_number_of_likes > number_of_likes)
        {
            number_of_likes = new_number_of_likes;
            best_reviewer = all_goodreads_user_info[i];
        }
        new_number_of_likes = 0;
    }

    cout << "id: " << best_reviewer.get_id() << endl;
    cout << "Name: " << best_reviewer.get_name() << endl;
    cout <<  "Place of Birth: " << best_reviewer.get_place_of_birth() << endl;
    cout << "Member Since: "; best_reviewer.get_member_since().print_info();
    cout << "Favorite Genres: ";
    for(int j = 0 ; j < best_reviewer.get_favorite_genres().size() ; j++)
    {
        cout << best_reviewer.get_favorite_genres()[j];
        if(j != (best_reviewer.get_favorite_genres().size()-1))
            cout << ",";
    }
    cout << endl;


    cout << "Favorite Authors: ";
    vector<int> copy_of_favorite_authors_id = best_reviewer.get_favorite_authors();

    sort(copy_of_favorite_authors_id.begin() , copy_of_favorite_authors_id.end() , compare_id);

    for(int a = 0 ; a < copy_of_favorite_authors_id.size() ; a++)
    {
        for(int i = 0 ; i < all_goodreads_author_info.size() ; i++)
        {
            if(copy_of_favorite_authors_id[a] == all_goodreads_author_info[i].get_id())
            {
                cout << all_goodreads_author_info[i].get_name();
                if(a != copy_of_favorite_authors_id.size()-1)
                {
                cout << ", ";
                }
            }
        }

    }
    cout << endl;

    cout << "Number of Books in Read Shelf: " << best_reviewer.get_read().size() << endl;
    cout << "Number of Books in Want to Read Shelf: " << best_reviewer.get_want_to_read().size() << endl;
    cout << "Number of Books in Currently Reading Shelf: " << best_reviewer.get_currently_reading().size() << endl;
    cout << "Number of Likes: " << number_of_likes << endl;

}

void goodreads::find_recommended_first_approach(int user_id)
{
    float credit;
    float credit_multiply_rate;
    float total_book_credit = 0;
    float rating;
    int genre_score = 0;
    float score = 0;
    float new_score = 0;
    int number_of_reviews_of_book = 0;
    book_info recommended_book_first_approach;
    user_info user;

    for(int i = 0 ; i < all_goodreads_user_info.size() ; i++)
    {
        if(user_id == all_goodreads_user_info[i].get_id())
        {
            user = all_goodreads_user_info[i];
            break;
        }
    }


    for(int i = 0 ; i < all_goodreads_book_info.size() ; i++)
    {
        for(int j = 0 ; j < all_goodreads_review_info.size() ; j++)
        {
            if(all_goodreads_book_info[i].get_id() == all_goodreads_review_info[j].get_book_id())
            {
                credit = calculate_credit(all_goodreads_review_info[j].get_user_id());
                credit_multiply_rate = credit * static_cast<float>(all_goodreads_review_info[j].get_rating());

                total_book_credit += credit_multiply_rate;
                number_of_reviews_of_book += 1;
            }

        }

        for(int k = 0 ; k < user.get_favorite_genres().size() ; k++)
        {
            if(user.get_favorite_genres()[k] == all_goodreads_book_info[i].get_genre())
            {
                genre_score = 5;
                break;
            }
        }
        rating = float(static_cast<float>(total_book_credit) / static_cast<float>(number_of_reviews_of_book));
        new_score = float(rating + static_cast<float>(genre_score));
        if(new_score > score)
        {
            score = new_score;

            recommended_book_first_approach = all_goodreads_book_info[i];
        }

        total_book_credit = 0;
        number_of_reviews_of_book = 0;
        genre_score = 0;
    }

    cout << "id: " << recommended_book_first_approach.get_id() << endl;
    cout << "Title: " << recommended_book_first_approach.get_name() << endl;
    cout << "Genre: " << recommended_book_first_approach.get_genre() << endl;
    for(int j = 0 ; j < all_goodreads_author_info.size() ; j++)
    {
        if (all_goodreads_author_info[j].get_id() == recommended_book_first_approach.get_author_id())
        {
            cout << "Author: " << all_goodreads_author_info[j].get_name() << endl;
        }
    }
    cout << "Reviews:" << endl;
    for(int i = 0 ; i < all_goodreads_review_info.size() ; i++)
    {
        if(recommended_book_first_approach.get_id() == all_goodreads_review_info[i].get_book_id())
        {
            cout << "id: " << all_goodreads_review_info[i].get_id()<< " " << "Rating: " << all_goodreads_review_info[i].get_rating() << " ";
            cout << "Likes: " << all_goodreads_review_info[i].get_number_of_likes() << " " << "Date: ";
            all_goodreads_review_info[i].get_date_of_review().print_info();
        }
    }
}





vector<user_info> goodreads::find_follower_path(vector<user_info> follower_path , int user_id)
{

    follower_info user;
    int check = 0;
    for(int i = 0 ; i < all_goodreads_follower_info.size() ; i++)
    {
        if(user_id == all_goodreads_follower_info[i].get_user_id())
        {
            user = all_goodreads_follower_info[i];
            break;
        }
    }

    for(int i = 0 ; i < user.get_followings().size() ; i++)
    {
        for(int j = 0 ; j < all_goodreads_user_info.size() ; j++)
        {
            if(user.get_followings()[i] == all_goodreads_user_info[j].get_id())
            {
                for(int k = 0 ; k < follower_path.size() ; k++)
                {
                    if(follower_path[k].get_id() == all_goodreads_user_info[j].get_id())
                    {
                        check = 1;
                    }
                }
                if(check == 1)
                {
                    check = 0;
                    continue;
                }
                else
                {
                    follower_path.push_back(all_goodreads_user_info[j]);
                    follower_path = find_follower_path(follower_path , all_goodreads_user_info[j].get_id());
                }
            }

        }
    }

    return follower_path;
}


vector<book_info> goodreads::find_best_three_book_of_following(vector<book_info> chosen_books , vector<user_info> follower_path)
{

    float new_score = 0;
    float first_score = 0;
    float second_score = 0;
    float third_score = 0;
    book_info first_book;
    book_info second_book;
    book_info third_book;
    follower_info user_in_following_list;

    for(int top = 0 ; top < follower_path.size() ; top++) {
        for (int i = 0; i < follower_path[top].get_read().size(); i++) {
            for (int j = 0; j < all_goodreads_book_info.size(); j++) {
                if (follower_path[top].get_read()[i] == all_goodreads_book_info[j].get_id()) {
                    new_score = float(static_cast<float>(all_goodreads_book_info[j].get_rating()));
                }

                if (new_score > first_score) {
                    third_score = second_score;
                    second_score = first_score;
                    first_score = new_score;
                    third_book = second_book;
                    second_book = first_book;
                    first_book = all_goodreads_book_info[j];

                } else if ((new_score < first_score) && (new_score > second_score)) {
                    third_score = second_score;
                    second_score = new_score;
                    third_book = second_book;
                    second_book = all_goodreads_book_info[j];

                } else if ((new_score < first_score) && (new_score < second_score) && (new_score > third_score)) {
                    third_score = new_score;
                    third_book = all_goodreads_book_info[j];
                }
            }

        }


        chosen_books.push_back(first_book);
        chosen_books.push_back(second_book);
        chosen_books.push_back(third_book);

        new_score = 0;
        first_score = 0;
        second_score = 0;
        third_score = 0;
    }

    return chosen_books;
}




void goodreads::find_recommend_second_approach(int user_id)
{
    float credit;
    float credit_multiply_rate;
    float total_book_credit = 0;
    float rating;
    int number_of_reviews_of_book = 0;
    follower_info user;
    vector<book_info> chosen_books;
    vector<user_info> follower_path;

    int count = 1;
    int max_count = 0;
    book_info selected_book;



    for (int i = 0; i < all_goodreads_book_info.size(); i++)
    {
        for (int j = 0; j < all_goodreads_review_info.size(); j++)
        {
            if (all_goodreads_book_info[i].get_id() == all_goodreads_review_info[j].get_book_id())
            {
                credit = calculate_credit(all_goodreads_review_info[j].get_user_id());
                credit_multiply_rate = credit * static_cast<float>(all_goodreads_review_info[j].get_rating());

                total_book_credit += credit_multiply_rate;
                number_of_reviews_of_book += 1;
            }

        }
        rating = float(static_cast<float>(total_book_credit) / static_cast<float>(number_of_reviews_of_book));
        all_goodreads_book_info[i].set_rating(rating);
        total_book_credit = 0;
        number_of_reviews_of_book = 0;
    }


    follower_path = find_follower_path(follower_path , user_id);
    chosen_books = find_best_three_book_of_following(chosen_books , follower_path);
    sort(chosen_books.begin() , chosen_books.end() , compare_genres);


    for(int i = 0 ; i < (chosen_books.size()-1) ; i++)
    {
        if(chosen_books[i].get_id() == chosen_books[i+1].get_id())
        {
            count += 1;
        }
        else
        {
            if(count > max_count)
            {
                max_count = count;
                selected_book = chosen_books[i];

            }
            count = 1;
        }

    }

    cout << "id: " << selected_book.get_id() << endl;
    cout << "Title: " << selected_book.get_name() << endl;
    cout << "Genre: " << selected_book.get_genre() << endl;
    for(int j = 0 ; j < all_goodreads_author_info.size() ; j++)
    {
        if (all_goodreads_author_info[j].get_id() == selected_book.get_author_id())
        {
            cout << "Author: " << all_goodreads_author_info[j].get_name() << endl;
        }
    }
    cout << "Reviews:" << endl;
    for(int i = 0 ; i < all_goodreads_review_info.size() ; i++)
    {
        if(selected_book.get_id() == all_goodreads_review_info[i].get_book_id())
        {
            cout << "id: " << all_goodreads_review_info[i].get_id()<< " " << "Rating: " << all_goodreads_review_info[i].get_rating() << " ";
            cout << "Likes: " << all_goodreads_review_info[i].get_number_of_likes() << " " << "Date: ";
            all_goodreads_review_info[i].get_date_of_review().print_info();
        }
    }

}



