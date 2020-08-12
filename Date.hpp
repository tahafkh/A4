#ifndef DATE_H
#define DATE_H "DATE"
#include<string>
class Date{
public:
    void string_to_date(std::string date);
    int get_year(){ return year;}
    std::string get_month(){ return month;}
    int get_day(){ return day;}
    void print_date();
private:
    int year;
    std::string month;
    int day;
};
#endif