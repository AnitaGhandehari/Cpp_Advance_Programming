#include <iostream>
#include "user_info.h"

using namespace std;

void user_info::set_id(int in_id)
{
    id = in_id;
}

void user_info::set_name(std::string in_name)
{
    name = in_name;
}

void user_info::set_place_of_birth(std::string in_place_of_birth)
{
    place_of_birth = in_place_of_birth;
}

void user_info::set_member_since(date in_member_since)
{
    member_since = in_member_since;
}

void user_info::set_favorite_authors(std::vector<int> in_favorite_authors)
{
    favorite_authors = in_favorite_authors;
}

void user_info::set_favorite_genres(std::vector<std::string> in_favorite_genres)
{
    favorite_genres = in_favorite_genres;
}

void user_info::set_want_to_read(std::vector<int> in_want_to_read)
{
    want_to_read = in_want_to_read;
}

void user_info::set_currently_reading(std::vector<int> in_currently_reading)
{
    currently_reading = in_currently_reading;
}

void user_info::set_read(std::vector<int> in_read)
{
    read = in_read;
}

