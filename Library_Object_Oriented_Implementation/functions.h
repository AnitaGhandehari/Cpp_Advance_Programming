#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "user_info.h"
#include "author_info.h"
#include "book_info.h"
#include "review_info.h"
#include "follower_info.h"

#ifndef A4_FUNCTIONS_H
#define A4_FUNCTIONS_H

bool compare_genres(book_info a, book_info b);
bool compare_id(int a, int b);
std::vector<std::string> convert_string_of_names_into_vector(std::string string_of_names);
std::vector<int> convert_string_of_ints_into_vector(std::string string_of_ints);
date classify_each_user_date(std::string string_of_date);
user_info classify_each_user_info(std::vector<std::string> all_users_info);
std::vector<user_info> read_users_file(char *argv[]);
author_info classify_each_author_info(std::vector<std::string> all_author_info);
std::vector<author_info> read_author_file(char *argv[]);
book_info classify_each_book_info(std::vector<std::string> all_book_info);
std::vector<book_info> read_books_file(char *argv[]);
review_info classify_each_review_info(std::vector<std::string> all_review_info);
std::vector<review_info> read_review_file(char *argv[]);
follower_info classify_each_follower_info(std::vector<std::string> all_follower_info);
std::vector<follower_info> read_follower_file(char *argv[]);





#endif //A4_FUNCTIONS_H
