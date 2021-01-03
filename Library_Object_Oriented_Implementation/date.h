
#ifndef A4_DATE_H
#define A4_DATE_H

#include <string>

class date{
private:
    std::string month;
    int day;
    int year;
public:
    date (std::string in_month = "January" , int in_day = 1 , int in_year = 1900);
    void print_info();
};

#endif //A4_DATE_H
