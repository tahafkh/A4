#ifndef BOOK_H
#define BOOK_H "BOOK"
#include<string>
#include<vector>
#include"Review.hpp"
typedef std::string Genre;
typedef std::vector<Review*> Reviews;
class Book{
public:
    double compute_average_rating();
    void compute_rating(std::vector<double> users_credits);
    void set_id(int id_){ id=id_;}
    void set_title(std::string title_){ title=title_;}
    void set_author_id(int author_id_){ author_id=author_id_;}
    void set_author_name(std::string author_name_){ author_name=author_name_;}
    void set_genre(Genre genre_){ genre=genre_;}
    void add_review(Review* new_review){ book_reviews.push_back(new_review);}
    int get_author_id(){ return author_id;}
    int get_id(){ return id;}
    Reviews get_reviews(){ return book_reviews;}
    std::string get_author_name(){ return author_name;}
    std::string get_title(){ return title;}
    Genre get_genre(){ return genre;}
    void print_info();
    double get_rating(){ return rating;}
private:
    int id;
    std::string title;
    int author_id;
    std::string author_name;
    Genre genre;
    Reviews book_reviews;
    double rating;
};
#endif