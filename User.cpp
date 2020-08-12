#include"User.hpp"
#include<iostream>
#include<iomanip>
#define ZERO 0
#define ROUNDING_NUMBER_1 6
using namespace std;
void User::sort_user_authors(){
    for(int i=0;i<favorite_authors.size();i++){
        for(int j=i+1;j<favorite_authors.size();j++){
            if(favorite_authors[i]->get_id()>favorite_authors[j]->get_id()){
                swap(favorite_authors[i],favorite_authors[j]);
            }
        }
    }
}
void User::sort_books_alphabatically(Books& books){
    for(int i=0;i<books.size();i++){
        for(int j=i+1;j<books.size();j++){
            if(books[i]->get_title()>books[j]->get_title()){
                swap(books[i],books[j]);
            }
            if(books[i]->get_title()==books[j]->get_title()){
                if(books[i]->get_id()>books[j]->get_id()){
                    swap(books[i],books[j]);
                }
            }
        }
    }
}
void User::sort_genres_alphabatically(){
    for(int i=0;i<favorite_genres.size();i++){
        for(int j=i+1;j<favorite_genres.size();j++){
            if(favorite_genres[i]>favorite_genres[j]){
                swap(favorite_genres[i],favorite_genres[j]);
            }
        }
    }
}
void User::print_info(){
    cout<<"id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Place of Birth: "<<place_of_birth<<endl;
    cout<<"Member Since: ";
    member_since.print_date();
    cout<<"Favorite Genres: ";
    for(int i=0;i<favorite_genres.size();i++){
        if(i==0){
            cout<<favorite_genres[i];
        }
        else{
            cout<<", "<<favorite_genres[i];
        }
    }
    cout<<endl;
    cout<<"Favorite Authors: ";
    for(int i=0;i<favorite_authors.size();i++){
        if(i==0){
            cout<<favorite_authors[i]->get_name();
        }
        else{
            cout<<", "<<favorite_authors[i]->get_name();
        }
    }
    cout<<endl;
    cout<<"Number of Books in Read Shelf: "<<read.size()<<endl;
    cout<<"Number of Books in Want to Read Shelf: "<<want_to_read.size()<<endl;
    cout<<"Number of Books in Currently Reading Shelf: "<<currently_reading.size()<<endl;
}
int User::compute_likes(){
    int user_likes=0;
    for(int i=0;i<user_reviews.size();i++){
        user_likes+=user_reviews[i]->get_likes();
    }
    return user_likes;
}
void User::compute_credit(int total_likes,int total_reviews){
    int user_likes=compute_likes();
    double like_credit=0,review_credit=0;
    if(total_likes==ZERO){
        like_credit=0;
    }
    else{
        like_credit=(double)user_likes/(double)total_likes;
    }
    if(total_reviews==ZERO){
        review_credit=0;
    }
    else{
        review_credit=(double)user_reviews.size()/(double)total_reviews;
    }
    credit=(like_credit+review_credit)/2;
}
void User::show_credit(){
    cout<<fixed<<showpoint;
    cout<<setprecision(ROUNDING_NUMBER_1);
    cout<<credit<<endl;
}
Books User::show_books_with_specific_genre(const Books &books,Genre specific_genre){
    Books specific_books;
    for(int i=0;i<books.size();i++){
        if(books[i]->get_genre()==specific_genre){
            specific_books.push_back(books[i]);
        }
    }
    return specific_books;
}
Books User::show_books_with_non_specific_genre(const Books &books,const Books &specific_books){
    Books non_specific_books;
    int specific=0;
    for(int i=0;i<books.size();i++){
        for(int j=0;j<specific_books.size();j++){
            if(specific_books[j]->get_genre()==books[i]->get_genre()){
                specific=1;
                break;
            }
        }
        if(specific!=1){
            non_specific_books.push_back(books[i]);
        }
        specific=0;
    }
    return non_specific_books;
}
void User::show_sorted_want_to_read_book(Genre genre){
    Books specific_books=show_books_with_specific_genre(want_to_read,genre);
    Books non_specific_books=show_books_with_non_specific_genre(want_to_read,specific_books);
    sort_books_alphabatically(specific_books);
    sort_books_alphabatically(non_specific_books);
    for(int i=0;i<specific_books.size();i++){
        specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
    for(int i=0;i<non_specific_books.size();i++){
        non_specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
}
void User::show_sorted_reading_book(Genre genre){
    Books specific_books=show_books_with_specific_genre(currently_reading,genre);
    Books non_specific_books=show_books_with_non_specific_genre(currently_reading,specific_books);
    sort_books_alphabatically(specific_books);
    sort_books_alphabatically(non_specific_books);
    for(int i=0;i<specific_books.size();i++){
        specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
    for(int i=0;i<non_specific_books.size();i++){
        non_specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
}
void User::show_sorted_read_book(Genre genre){
    Books specific_books=show_books_with_specific_genre(read,genre);
    Books non_specific_books=show_books_with_non_specific_genre(read,specific_books);
    sort_books_alphabatically(specific_books);
    sort_books_alphabatically(non_specific_books);
    for(int i=0;i<specific_books.size();i++){
        specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
    for(int i=0;i<non_specific_books.size();i++){
        non_specific_books[i]->print_info();
        cout<<"***"<<endl;
    }
}