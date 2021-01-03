#include "functions.h"
#include <iostream>
#include <string>
#include <vector>
#include "user_info.h"
#include "author_info.h"
#include "book_info.h"
#include "review_info.h"
#include "follower_info.h"

#define EVERY_PART_SEPRATOR ','
#define TYPE_SEPRATOR '$'
#define TIME_SEPRATOR ' '

using namespace std;

bool compare_genres(book_info a, book_info b)
{
    int size = 0;
    if(a.get_name().size() < b.get_name().size())
        size = a.get_name().size();
    else
        size = b.get_name().size();
    for(int i=0 ; i < size ; i++)
    {
        if (int(a.get_name()[i]) == int(b.get_name()[i]))
            continue;
        else
            return (int(a.get_name()[i]) < int(b.get_name()[i]));
    }
    return (int(a.get_name().size()) < int(b.get_name().size()));
}

bool compare_id(int a, int b)
{
    return a < b;
}


date classify_each_user_date(string string_of_date)
{
    string word;
    vector<string> part_of_date;
    stringstream date_info(string_of_date);
    while(getline(date_info, word, TIME_SEPRATOR))
    {
        part_of_date.push_back(word);
    }
    date each_user_classified_date(part_of_date[0], stoi(part_of_date[1]), stoi(part_of_date[2]));

    return each_user_classified_date;
}

vector<int> convert_string_of_ints_into_vector(string string_of_ints)
{
    string word;
    vector<int> vector_of_ints;

    stringstream parts_of_string_of_ints(string_of_ints);
    while (getline(parts_of_string_of_ints, word, TYPE_SEPRATOR))
    {
        vector_of_ints.push_back(stoi(word));
    }

    return vector_of_ints;
}

vector<string> convert_string_of_names_into_vector(string string_of_names)
{
    string word;
    vector<string> vector_of_names;

    stringstream parts_of_string_of_name(string_of_names);
    while (getline(parts_of_string_of_name, word, TYPE_SEPRATOR))
    {
        vector_of_names.push_back(word);
    }

    return vector_of_names;
}

user_info classify_each_user_info(vector<string> all_users_info)
{
    user_info each_user_classified_info;
    each_user_classified_info.set_id(stoi(all_users_info[0]));
    each_user_classified_info.set_name(all_users_info[1]);
    each_user_classified_info.set_place_of_birth(all_users_info[2]);
    each_user_classified_info.set_member_since(classify_each_user_date(all_users_info[3]));
    each_user_classified_info.set_favorite_authors(convert_string_of_ints_into_vector(all_users_info[4]));
    each_user_classified_info.set_favorite_genres(convert_string_of_names_into_vector(all_users_info[5]));
    each_user_classified_info.set_want_to_read(convert_string_of_ints_into_vector(all_users_info[6]));
    each_user_classified_info.set_currently_reading(convert_string_of_ints_into_vector(all_users_info[7]));
    each_user_classified_info.set_read(convert_string_of_ints_into_vector(all_users_info[8]));
    return each_user_classified_info;
}

vector<user_info> read_users_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_users_info;
    vector<user_info> table_of_user_info;
    string file_address;

    file_address =string(argv[1]) + "/users.csv";
    ifstream UsersFile(file_address);
    if(UsersFile.fail())
    {
        cout << "UsersFile Does not Open" << endl;
        exit(1);
    }
    getline(UsersFile, line);
    while (getline(UsersFile, line))
    {

        stringstream all_info(line);
        while (getline(all_info, word, EVERY_PART_SEPRATOR))
        {
            all_users_info.push_back(word);
        }
        table_of_user_info.push_back(classify_each_user_info(all_users_info));
        all_users_info.clear();
    }
    return table_of_user_info;
}

author_info classify_each_author_info(vector<string> all_author_info)
{
    author_info each_author_classified_info;
    each_author_classified_info.set_id(stoi(all_author_info[0]));
    each_author_classified_info.set_name(all_author_info[1]);
    each_author_classified_info.set_gender(all_author_info[2]);
    each_author_classified_info.set_member_since(classify_each_user_date(all_author_info[3]));
    each_author_classified_info.set_year_of_birth(stoi(all_author_info[4]));
    each_author_classified_info.set_place_of_birth(all_author_info[5]);
    each_author_classified_info.set_genres(convert_string_of_names_into_vector(all_author_info[6]));

    return each_author_classified_info;
}

vector<author_info> read_author_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_author_info;
    vector<author_info> table_of_author_info;
    string file_address;
    file_address = string(argv[1]) + "/authors.csv";

    ifstream AuthorFile(file_address);
    if(AuthorFile.fail())
    {
        cout << "AuthorFile Does not Open" << endl;
        exit(1);
    }
    getline(AuthorFile, line);
    while (getline(AuthorFile, line))
    {

        stringstream all_info(line);
        while (getline(all_info, word, EVERY_PART_SEPRATOR))
        {
            all_author_info.push_back(word);
        }
        table_of_author_info.push_back(classify_each_author_info(all_author_info));
        all_author_info.clear();
    }
    return table_of_author_info;
}

book_info classify_each_book_info(vector<string> all_book_info)
{
    book_info each_book_classified_info;
    each_book_classified_info.set_id(stoi(all_book_info[0]));
    each_book_classified_info.set_name(all_book_info[1]);
    each_book_classified_info.set_author_id(stoi(all_book_info[2]));
    each_book_classified_info.set_genre(all_book_info[3]);

    return each_book_classified_info;
}

vector<book_info> read_books_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_book_info;
    vector<book_info> table_of_book_info;
    string file_address;
    file_address = string(argv[1]) + "/books.csv";

    ifstream BookFile(file_address);
    if(BookFile.fail())
    {
        cout << "BookFile Does not Open" << endl;
        exit(1);
    }
    getline(BookFile, line);
    while (getline(BookFile, line))
    {

        stringstream all_info(line);
        while (getline(all_info, word, EVERY_PART_SEPRATOR))
        {
            all_book_info.push_back(word);
        }
        table_of_book_info.push_back(classify_each_book_info(all_book_info));
        all_book_info.clear();
    }
    return table_of_book_info;
}

review_info classify_each_review_info(vector<string> all_review_info)
{
    review_info each_review_classified_info;
    each_review_classified_info.set_id(stoi(all_review_info[0]));
    each_review_classified_info.set_book_id(stoi(all_review_info[1]));
    each_review_classified_info.set_user_id(stoi(all_review_info[2]));
    each_review_classified_info.set_rating(stoi(all_review_info[3]));
    each_review_classified_info.set_date_of_review(classify_each_user_date(all_review_info[4]));
    each_review_classified_info.set_number_of_likes(stoi(all_review_info[5]));

    return each_review_classified_info;
}

vector<review_info> read_review_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_review_info;
    vector<review_info> table_of_review_info;
    string file_address;
    file_address = string(argv[1]) + "/reviews.csv";

    ifstream ReviewFile(file_address);
    if(ReviewFile.fail())
    {
        cout << "ReviewFile Does not Open" << endl;
        exit(1);
    }
    getline(ReviewFile, line);
    while (getline(ReviewFile, line))
    {

        stringstream all_info(line);
        while (getline(all_info, word, EVERY_PART_SEPRATOR))
        {
            all_review_info.push_back(word);
        }
        table_of_review_info.push_back(classify_each_review_info(all_review_info));
        all_review_info.clear();
    }
    return table_of_review_info;
}

follower_info classify_each_follower_info(vector<string> all_follower_info)
{
    follower_info each_follower_classified_info;
    each_follower_classified_info.set_user_id(stoi(all_follower_info[0]));
    each_follower_classified_info.set_followings(convert_string_of_ints_into_vector(all_follower_info[1]));
    if(all_follower_info.size() == 3)
        each_follower_classified_info.set_followers(convert_string_of_ints_into_vector(all_follower_info[2]));

    return each_follower_classified_info;
}

vector<follower_info> read_follower_file(char *argv[])
{
    string line;
    string word;
    vector<string> all_follower_info;
    vector<follower_info> table_of_follower_info;
    string file_address;
    file_address = string(argv[1]) + "/follow_edges.csv";
    ifstream FollowerFile(file_address);
    if(FollowerFile.fail())
    {
        cout << "FollowerFile Does not Open" << endl;
        exit(1);
    }
    getline(FollowerFile, line);
    while (getline(FollowerFile, line))
    {

        stringstream all_info(line);
        while (getline(all_info, word, EVERY_PART_SEPRATOR))
        {
            all_follower_info.push_back(word);
        }
        table_of_follower_info.push_back(classify_each_follower_info(all_follower_info));
        all_follower_info.clear();
    }
    return table_of_follower_info;
}
