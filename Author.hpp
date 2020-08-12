#ifndef AUTHOR_H
#define AUTHOR_H "AUTHOR"
#include"Book.hpp"
typedef std::vector<Book*> Books;
typedef std::string Genre;
typedef std::vector<Genre> Genres;
class Author{
public:
    void sort_genres_alphabatically();
    void set_id(int id_){ id=id_;}
    void set_name(std::string name_){ name=name_;}
    void set_gender(std::string gender_){ gender=gender_;}
    void set_date(std::string date){ member_since.string_to_date(date);}
    void set_birth_year(int birth_year){ year_of_birth=birth_year;}
    void set_birth_place(std::string birth_place){ place_of_birth=birth_place;}
    void add_genre(Genre new_genre){ author_genres.push_back(new_genre);}
    void add_book(Book* new_book){ author_books.push_back(new_book);}
    int get_id(){ return id;}
    std::string get_name(){ return name;}
    void print_info();
private:
    int id;
    std::string name;
    std::string gender;
    Date member_since;
    int year_of_birth;
    std::string place_of_birth;
    Genres author_genres;
    Books author_books;
};
#endif