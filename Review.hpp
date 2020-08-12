#ifndef REVIEW_H
#define REVIEW_H "REVIEW"
#include "Date.hpp"
class Review{
public:
    void set_id(int id_){ id=id_;}
    void set_book_id(int book_id_){ book_id=book_id_;}
    void set_user_id(int user_id_){ user_id=user_id_;}
    void set_rating(int rating_){ rating=rating_;}
    void set_date(std::string date_){ date.string_to_date(date_);}
    void set_likes(int likes){ number_of_likes=likes;}
    int get_book_id(){ return book_id;}
    int get_user_id(){ return user_id;}
    int get_likes(){ return number_of_likes;}
    int get_rating(){ return rating;}
    int get_id(){ return id;}
    void print_info();
private:
    int id;
    int book_id;
    int user_id;
    int rating;
    Date date;
    int number_of_likes;  
};
#endif