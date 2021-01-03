#include <iostream>
#include "author_info.h"

using namespace std;

void author_info::set_id(int in_id)
{
    id = in_id;
}

void author_info::set_name(std::string in_name)
{
    name = in_name;
}

void author_info::set_gender(std::string in_gender)
{
    gender = in_gender;
}

void author_info::set_member_since(date in_member_since)
{
    member_since = in_member_since;
}

void author_info::set_year_of_birth(int in_year_of_birth)
{
    year_of_birth = in_year_of_birth;
}

void author_info::set_place_of_birth(std::string in_place_of_birth)
{
    place_of_birth = in_place_of_birth;
}


void author_info::set_genres(std::vector<std::string> in_genres)
{
    genres = in_genres;
}


