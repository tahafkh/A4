#include"Review.hpp"
#include<iostream>
using namespace std;
void Review::print_info(){
    cout<<"id: "<<id<<" Rating: "<<rating<<" Likes: "<<number_of_likes<<" Date: ";
    date.print_date();
}