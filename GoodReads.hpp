#ifndef GOODREADS
#define GOODREADS "GOODREADS"
#include"User.hpp"
typedef std::vector<User> Users_;
typedef std::vector<Author> Authors_;
typedef std::vector<Review> Reviews_;
typedef std::vector<Book> Books_;
class GoodReads{
public:
    int common_genres(Genres favorite_genres,Genre book_genre);
    void show_best_book();
    void show_best_reviewer();
    void show_user_sorted_shelf(int user_id,std::string shelf_type,Genre genre);
    void show_user_credit(int user_id);
    void compute_total_likes();
    void update_users_credits();
    void update_books_rating();
    void choose_best_books(User *chosen_user,Books& chosen_books,std::vector<User*> &chosen_users);
    void update_user_follow_infos(std::string user_id,std::string followings,std::string followers);
    void show_first_approach(int user_id);
    void show_second_approach(int user_id);
    int find_user_by_id(int user_id);
    int  find_author_by_id(int author_id);
    void print_author_info(int author_id);
    void find_reviews_details();
    void save_user_genres(User &new_user,std::string genres);
    void save_author_genres(Author &new_author,std::string genres);
    void save_author_books(Author& new_author);
    void save_user_favorite_authors(User &new_user,std::string favorite_authors);
    void save_user_want_to_read_books(User& new_user,std::string want_to_read );
    void save_user_currently_reading_books(User& new_user,std::string currently_reading);
    void save_user_read_books(User& new_user,std::string read );
    void add_authors(Author new_author){ gd_authors.push_back(new_author);}
    void add_users(User new_user){ gd_users.push_back(new_user);}
    void add_books(Book new_book){ gd_books.push_back(new_book);}
    void add_reviews(Review new_review){ gd_reviews.push_back(new_review);}
    void sort_books_by_rating(Books &books);
    void sort_books_by_id();
    Book* show_most_frequent_book(const Books &books);
    void sort_authors_by_id();
    void sort_users_by_id();
    void sort_reviews_by_id();
private:
    Users_ gd_users;
    Authors_ gd_authors;
    Reviews_ gd_reviews;
    Books_ gd_books;
    int total_likes;
};
#endif