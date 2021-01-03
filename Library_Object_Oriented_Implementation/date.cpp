#include "date.h"
#include <iostream>

using namespace std;

date::date (std::string in_month , int in_day , int in_year)
{
    month = in_month;
    day =in_day;
    year = in_year;
}

void date::print_info()
{
    cout << month << " " << day << " " << year << endl;
}