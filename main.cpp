#include"functions.hpp"
using namespace std;
int main(int argc,char* argv[]){
    GoodReads goodreads;
    save_books_info(file_path_maker(argv[1],"books.csv"),goodreads);
    save_authors_info(file_path_maker(argv[1],"authors.csv"),goodreads);
    save_users_info(file_path_maker(argv[1],"users.csv"),goodreads);
    save_reviews_info(file_path_maker(argv[1],"reviews.csv"),goodreads);
    save_follow_edges_info(file_path_maker(argv[1],"follow_edges.csv"),goodreads);
    goodreads.compute_total_likes();
    goodreads.update_users_credits();
    goodreads.update_books_rating();
    command_checker(goodreads);
    return 0;
}