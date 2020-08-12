#include"GoodReads.hpp"
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<sstream>
#define ZERO 0
#define ROUNDING_NUMBER_2 2
#define COMMON 5
#define BEST_BOOKS 3
#define NOT_FOUND -1
#define MINOR_SEPERATOR '$'
using namespace std;
void GoodReads::sort_books_by_rating(Books &books){
    for(int i=0;i<books.size();i++){
        for(int j=i+1;j<books.size();j++){
            if(books[i]->get_rating()<books[j]->get_rating()){
                swap(books[i],books[j]);
            }
            else if(books[i]->get_rating()==books[j]->get_rating()){
                if(books[i]->get_id()>books[j]->get_id()){
                    swap(books[i],books[j]);
                }
            }
        }
    }
}
Book* GoodReads::show_most_frequent_book(const Books &books){
    int max_frequency=0,frequency=0;
    Book *most_frequent_book=NULL;
    for(int i=0;i<books.size();i++){
        frequency=count(books.begin(),books.end(),books[i]);
        if(frequency>max_frequency){
            max_frequency=frequency;
            most_frequent_book=books[i];
        }
        else if(frequency==max_frequency && most_frequent_book->get_id()>books[i]->get_id()){
            most_frequent_book=books[i];
        }
    }
    return most_frequent_book;
}
void GoodReads::choose_best_books(User *chosen_user,Books &chosen_books,vector<User*> &chosen_users){
    int chosen=0;
    Books best_books=chosen_user->get_read_books();
    vector<User*> chosen_user_followings=chosen_user->get_followings();
    sort_books_by_rating(best_books);
    if(best_books.size()<BEST_BOOKS){
        chosen_books.insert(chosen_books.end(),best_books.begin(),best_books.end());
    }
    else{
        chosen_books.insert(chosen_books.end(),best_books.begin(),best_books.begin()+BEST_BOOKS);
    }
    for(int i=0;i<chosen_user_followings.size();i++){
        for(int j=0;j<chosen_users.size();j++){
            if(chosen_users[j]==chosen_user_followings[i]){
                chosen=1;
                break;
            }
        }
        if(chosen!=1){
            chosen_users.push_back(chosen_user_followings[i]);
            choose_best_books(chosen_user_followings[i],chosen_books,chosen_users);
        }
        chosen=0;
    }
    return;
}
void GoodReads::show_second_approach(int user_id){
    int index=find_user_by_id(user_id),chosen=0;
    if(index==NOT_FOUND){
        cerr<<"NOT_FOUND!"<<endl;
        return;
    }
    vector<User*> chosen_users,user_followings=gd_users[index].get_followings();
    Books chosen_books;
    for(int i=0;i<user_followings.size();i++){
        for(int j=0;j<chosen_users.size();j++){
            if(chosen_users[j]==user_followings[i]){
                chosen=1;
                break;
            }
        }
        if(chosen!=1){
            chosen_users.push_back(user_followings[i]);
            choose_best_books(user_followings[i],chosen_books,chosen_users);
        }
    }
    Book *recommended_book=show_most_frequent_book(chosen_books);
    recommended_book->print_info();
    Reviews book_reviews=recommended_book->get_reviews();
    cout<<"Reviews:"<<endl;
    for(int i=0;i<book_reviews.size();i++){
        book_reviews[i]->print_info();
    }
}
void GoodReads::update_user_follow_infos(string user_id,string followings,string followers){
    int index=find_user_by_id(stoi(user_id)),follow_index=0;
    stringstream followings_info(followings),followers_info(followers);
    string following,follower;
    if(followings!=""){
        for(int i=0;i<=count(followings.begin(),followings.end(),MINOR_SEPERATOR);i++){
            getline(followings_info,following,MINOR_SEPERATOR);
            follow_index=find_user_by_id(stoi(following));
            gd_users[index].add_following(&(gd_users[follow_index]));
        }
    }
    if(followers!=""){
        for(int i=0;i<=count(followers.begin(),followers.end(),MINOR_SEPERATOR);i++){
            getline(followers_info,follower,MINOR_SEPERATOR);
            follow_index=find_user_by_id(stoi(follower));
            gd_users[index].add_follower(&(gd_users[follow_index]));
        }
    }
}
void GoodReads::sort_reviews_by_id(){
    for(int i=0;i<gd_reviews.size();i++){
        for(int j=i+1;j<gd_reviews.size();j++){
            if(gd_reviews[i].get_id()>gd_reviews[j].get_id()){
                swap(gd_reviews[i],gd_reviews[j]);
            }
        }
    }
}
void GoodReads::sort_books_by_id(){
    for(int i=0;i<gd_books.size();i++){
        for(int j=i+1;j<gd_books.size();j++){
            if(gd_books[i].get_id()>gd_books[j].get_id()){
                swap(gd_books[i],gd_books[j]);
            }
        }
    }
}
void GoodReads::sort_users_by_id(){
    for(int i=0;i<gd_users.size();i++){
        for(int j=i+1;j<gd_users.size();j++){
            if(gd_users[i].get_id()>gd_users[j].get_id()){
                swap(gd_users[i],gd_users[j]);
            }
        }
    }
}
void GoodReads::sort_authors_by_id(){
    for(int i=0;i<gd_authors.size();i++){
        for(int j=i+1;j<gd_authors.size();j++){
            if(gd_authors[i].get_id()>gd_authors[j].get_id()){
                swap(gd_authors[i],gd_authors[j]);
            }
        }
    }
}
int GoodReads::common_genres(Genres favorite_genres,Genre book_genre){
    for(int i=0;i<favorite_genres.size();i++){
        if(favorite_genres[i]==book_genre){
            return COMMON;
        }
    }
    return ZERO;
}
void GoodReads::show_first_approach(int user_id){
    int index=find_user_by_id(user_id);
    if(index==NOT_FOUND){
        cerr<<"NOT_FOUND!"<<endl;
        return;
    }
    double max_score=0,book_score;
    Book *recommended_book;
    for(int i=0;i<gd_books.size();i++){
        book_score=gd_books[i].get_rating()+common_genres(gd_users[index].show_genres(),gd_books[i].get_genre());
        if(book_score>max_score){
            max_score=book_score;
            recommended_book=&(gd_books[i]);
        }
    }
    recommended_book->print_info();
    Reviews book_reviews=recommended_book->get_reviews();
    cout<<"Reviews:"<<endl;
    for(int i=0;i<book_reviews.size();i++){
        book_reviews[i]->print_info();
    }
}
void GoodReads::update_books_rating(){
    for(int i=0;i<gd_books.size();i++){
        vector<double> users_credits;
        Reviews book_reviews=gd_books[i].get_reviews();
        for(int j=0;j<book_reviews.size();j++){
            for(int k=0;k<gd_users.size();k++){
                if(gd_users[k].get_id()==book_reviews[j]->get_user_id()){
                    users_credits.push_back(gd_users[k].get_credit());
                    break;
                }
            }
        }
        gd_books[i].compute_rating(users_credits);
    }
}
void GoodReads::show_best_reviewer(){
    int max_user_likes=0,user_likes=0;
    User *best_reviewer;
    for(int i=0;i<gd_users.size();i++){
        user_likes=gd_users[i].compute_likes();
        if(user_likes>max_user_likes){
            max_user_likes=user_likes;
            best_reviewer=&(gd_users[i]);
        }
    }
    best_reviewer->print_info();
    cout<<"Number of Likes: "<<max_user_likes<<endl;
}
void GoodReads::show_best_book(){
    double max_average_rating=0;
    Book* best_book;
    for(int i=0;i<gd_books.size();i++){
        if(gd_books[i].compute_average_rating()>max_average_rating){
            max_average_rating=gd_books[i].compute_average_rating();
            best_book=&(gd_books[i]);
        }
    }
    best_book->print_info();
    cout<<"Average Rating: ";
    cout<<fixed<<showpoint;
    cout<<setprecision(ROUNDING_NUMBER_2);
    cout<<max_average_rating<<endl;
}
void GoodReads::compute_total_likes(){
    int likes=0;
    for(int i=0;i<gd_reviews.size();i++){
        likes+=gd_reviews[i].get_likes();
    }
    total_likes=likes;
}
void GoodReads::update_users_credits(){
    for(int i=0;i<gd_users.size();i++){
        gd_users[i].compute_credit(total_likes,gd_reviews.size());
    }
}

int GoodReads::find_author_by_id(int author_id){
    for(int i=0;i<gd_authors.size();i++){
        if(author_id==gd_authors[i].get_id()){
            return i;
        }
    }
    return NOT_FOUND;
}
int GoodReads::find_user_by_id(int user_id){
    for(int i=0;i<gd_users.size();i++){
        if(user_id==gd_users[i].get_id()){
            return i;
        }
    }
    return NOT_FOUND;
}
void GoodReads::show_user_credit(int user_id){
    int index=find_user_by_id(user_id);
    if(index==NOT_FOUND){
        cerr<<"NOT_FOUND!"<<endl;
        return;
    }
    gd_users[index].show_credit();    
}
void GoodReads::show_user_sorted_shelf(int user_id,string shelf_type,Genre genre){
    int index=find_user_by_id(user_id);
    if(index==NOT_FOUND){
        cerr<<"NOT_FOUND!"<<endl;
        return;
    }
    if(shelf_type=="want to read"){
        gd_users[index].show_sorted_want_to_read_book(genre);
    }
    else if(shelf_type=="currently_reading"){
        gd_users[index].show_sorted_reading_book(genre);
    }
    else if(shelf_type=="read"){
        gd_users[index].show_sorted_read_book(genre);
    }
    else{
        cerr<<"NOT_FOUND!"<<endl;
    }
}
void GoodReads::print_author_info(int author_id){
    int index=find_author_by_id(author_id);
    if(index==NOT_FOUND){
        cerr<<"NOT_FOUND!"<<endl;
        return;
    }
    gd_authors[index].print_info();
}
void GoodReads::save_author_genres(Author &new_author,string genres){
    Genre new_genre;
    stringstream genres_section(genres);
    for(int i=0;i<=count(genres.begin(),genres.end(),MINOR_SEPERATOR);i++){
        getline(genres_section,new_genre,MINOR_SEPERATOR);
        new_author.add_genre(new_genre);
    }
}
void GoodReads::save_author_books(Author& new_author){
    for(int i=0;i<gd_books.size();i++){
        if(new_author.get_id()==gd_books[i].get_author_id()){
            new_author.add_book(&(gd_books[i]));
            if(gd_books[i].get_author_name()==" "){
                gd_books[i].set_author_name(new_author.get_name());
            }
        }
    }
}
void GoodReads::save_user_favorite_authors(User &new_user,string favorite_authors){
    string author;
    stringstream fv_authors(favorite_authors);
    for(int i=0;i<=count(favorite_authors.begin(),favorite_authors.end(),MINOR_SEPERATOR);i++){
        getline(fv_authors,author,MINOR_SEPERATOR);
        for(int j=0;j<gd_authors.size();j++){
            if(stoi(author)==gd_authors[j].get_id()){
                new_user.add_author(&(gd_authors[j]));
                break;
            }
        }
    }
    new_user.sort_user_authors();
}
void GoodReads::save_user_genres(User &new_user,string genres){
    Genre new_genre;
    stringstream genres_section(genres);
    for(int i=0;i<=count(genres.begin(),genres.end(),MINOR_SEPERATOR);i++){
        getline(genres_section,new_genre,MINOR_SEPERATOR);
        new_user.add_genre(new_genre);
    }
}
void GoodReads::save_user_want_to_read_books(User& new_user,string want_to_read ){
    string book;
    stringstream want_books(want_to_read);
    for(int i=0;i<=count(want_to_read.begin(),want_to_read.end(),MINOR_SEPERATOR);i++){
        getline(want_books,book,MINOR_SEPERATOR);
        for(int j=0;j<gd_books.size();j++){
            if(stoi(book)==gd_books[j].get_id()){
                new_user.add_want_to_read_book(&(gd_books[j]));
                break;
            }
        }
    }
}
void GoodReads::save_user_currently_reading_books(User& new_user,string currently_reading ){
    string book;
    stringstream current_books(currently_reading);
    for(int i=0;i<=count(currently_reading.begin(),currently_reading.end(),MINOR_SEPERATOR);i++){
        getline(current_books,book,MINOR_SEPERATOR);
        for(int j=0;j<gd_books.size();j++){
            if(stoi(book)==gd_books[j].get_id()){
                new_user.add_currently_reading_book(&(gd_books[j]));
                break;
            }
        }
    }
}
void GoodReads::save_user_read_books(User& new_user,string read ){
    string book;
    stringstream former_books(read);
    for(int i=0;i<=count(read.begin(),read.end(),MINOR_SEPERATOR);i++){
        getline(former_books,book,MINOR_SEPERATOR);
        for(int j=0;j<gd_books.size();j++){
            if(stoi(book)==gd_books[j].get_id()){
                new_user.add_read_book(&(gd_books[j]));
                break;
            }
        }
    }
}
void GoodReads::find_reviews_details(){
    for(int k=0;k<gd_reviews.size();k++){
        for(int i=0;i<gd_users.size();i++){
            if(gd_reviews[k].get_user_id()==gd_users[i].get_id()){
                gd_users[i].add_review(&(gd_reviews[k]));
                break;
            }
        }
        for(int i=0;i<gd_books.size();i++){
            if(gd_reviews[k].get_book_id()==gd_books[i].get_id()){
                gd_books[i].add_review(&(gd_reviews[k]));
                break;
            }
        }
    }
}