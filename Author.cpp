#include"Author.hpp"
#include<iostream>
using namespace std;
void Author::sort_genres_alphabatically(){
    for(int i=0;i<author_genres.size();i++){
        for(int j=i+1;j<author_genres.size();j++){
            if(author_genres[i]>author_genres[j]){
                swap(author_genres[i],author_genres[j]);
            }
        }
    }
}
void Author::print_info(){
    cout<<"id: "<<id<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Year of Birth: "<<year_of_birth<<endl;
    cout<<"Place of Birth: "<<place_of_birth<<endl;
    cout<<"Member Since: ";
    member_since.print_date();
    cout<<"Genres:";
    for(int i=0;i<author_genres.size();i++){
        if(i==0){
            cout<<" "<<author_genres[i];
        }
        else{
             cout<<", "<<author_genres[i];
        }
    }
    cout<<endl;
    cout<<"Books:"<<endl;
    for(int i=0;i<author_books.size();i++){
        cout<<"id: "<<author_books[i]->get_id()<<" Title: "<<author_books[i]->get_title()<<endl;
    }
}