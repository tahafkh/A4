#include"Book.hpp"
#include<iostream>
using namespace std;
void Book::compute_rating(vector<double> users_credits){
    double sum=0;
    for(int i=0;i<book_reviews.size();i++){
        sum+=(book_reviews[i]->get_rating()*users_credits[i]);
    }
    rating=sum/book_reviews.size();
}
double Book::compute_average_rating(){
    int total_rating=0;
    for(int i=0;i<book_reviews.size();i++){
        total_rating+=book_reviews[i]->get_rating();
    }
    return (double)total_rating/book_reviews.size();
}
void Book::print_info(){
    cout<<"id: "<<id<<endl;
    cout<<"Title: "<<title<<endl;
    cout<<"Genre: "<<genre<<endl;
    cout<<"Author: "<<author_name<<endl;
}