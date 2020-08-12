#ifndef USER_H
#define USER_H "USER"
#include"Author.hpp"
typedef std::vector<Author*> Authors;
class User{
public:
    void compute_credit(int total_likes,int total_reviews);
    int compute_likes();
    void show_sorted_want_to_read_book(Genre genre);
    void show_sorted_reading_book(Genre genre);
    void show_credit();
    void sort_user_authors();
    void sort_genres_alphabatically();
    void sort_books_alphabatically(Books& books);
    void show_sorted_read_book(Genre genre);
    Genres show_genres(){ return favorite_genres;}
    Books show_books_with_specific_genre(const Books &books,Genre specific_genre);
    Books show_books_with_non_specific_genre(const Books &books,const Books &specific_books);
    void set_name(std::string name_){name=name_;}
    void set_id(int id_){id=id_;}
    void set_date(std::string date){ member_since.string_to_date(date);}
    void set_birth_place(std::string birth_place){ place_of_birth=birth_place;}
    void add_genre(Genre new_genre){ favorite_genres.push_back(new_genre);}
    void add_want_to_read_book(Book* new_book){ want_to_read.push_back(new_book);}
    void add_currently_reading_book(Book* new_book){ currently_reading.push_back(new_book);}
    void add_read_book(Book* new_book){ read.push_back(new_book);}
    void add_author(Author* new_author){ favorite_authors.push_back(new_author);}
    void add_review(Review* new_review){ user_reviews.push_back(new_review);}
    void add_follower(User *new_follower){ user_followers.push_back(new_follower);}
    void add_following(User *new_following){ user_followings.push_back(new_following);}
    int get_id(){ return id;}
    std::vector<User*> get_followings(){ return user_followings;}
    Books get_read_books(){ return read;}
    double get_credit(){return credit;}
    void print_info();
private:
    int id;
    std::string name;
    std::string place_of_birth;
    Date member_since;
    Authors favorite_authors;
    Genres favorite_genres;
    Reviews user_reviews;
    double credit;
    Books want_to_read;
    Books currently_reading;
    Books read;
    std::vector<User*> user_followings;
    std::vector<User*> user_followers;
};
#endif