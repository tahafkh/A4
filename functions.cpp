#include"functions.hpp"
#include<iostream>
#include<sstream>
#include<fstream>
#define MAJOR_SEPERATOR ','
#define SPACE_SEPERATOR ' '
using namespace std;
void save_books_info(string books_file_path,GoodReads& gd){
    ifstream books_file(books_file_path);
    string books_info,books_info_section,temperory;
    getline(books_file,temperory);
    while(getline(books_file,books_info)){
        Book new_book;
        stringstream books_info_sections(books_info);
        getline(books_info_sections,books_info_section,MAJOR_SEPERATOR);
        new_book.set_id(stoi(books_info_section));
        getline(books_info_sections,books_info_section,MAJOR_SEPERATOR);
        new_book.set_title(books_info_section);
        getline(books_info_sections,books_info_section,MAJOR_SEPERATOR);
        new_book.set_author_id(stoi(books_info_section));
        getline(books_info_sections,books_info_section,MAJOR_SEPERATOR);
        new_book.set_genre(books_info_section);
        new_book.set_author_name(" ");
        gd.add_books(new_book);
    }
    gd.sort_books_by_id();
}
void save_authors_info(string authors_file_path,GoodReads &gd){
    ifstream authors_file(authors_file_path);
    string authors_info,authors_info_section,temperory;
    getline(authors_file,temperory);
    while(getline(authors_file,authors_info)){
        Author new_author;
        stringstream authors_info_sections(authors_info);
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_id(stoi(authors_info_section));
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_name(authors_info_section);
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_gender(authors_info_section);
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_date(authors_info_section);
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_birth_year(stoi(authors_info_section));
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        new_author.set_birth_place(authors_info_section);
        getline(authors_info_sections,authors_info_section,MAJOR_SEPERATOR);
        gd.save_author_genres(new_author,authors_info_section);
        new_author.sort_genres_alphabatically();
        gd.save_author_books(new_author);
        gd.add_authors(new_author);
    }
    gd.sort_authors_by_id();
}
void save_users_info(string users_file_path,GoodReads &gd){
    ifstream users_file(users_file_path);
    string users_info,users_info_section,temperory;
    getline(users_file,temperory);
    while(getline(users_file,users_info)){
        User new_user;
        stringstream users_info_sections(users_info);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        new_user.set_id(stoi(users_info_section));
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        new_user.set_name(users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        new_user.set_birth_place(users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        new_user.set_date(users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        gd.save_user_favorite_authors(new_user,users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        gd.save_user_genres(new_user,users_info_section);
        new_user.sort_genres_alphabatically();
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        gd.save_user_want_to_read_books(new_user,users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        gd.save_user_currently_reading_books(new_user,users_info_section);
        getline(users_info_sections,users_info_section,MAJOR_SEPERATOR);
        gd.save_user_read_books(new_user,users_info_section);
        gd.add_users(new_user);
    }
    gd.sort_users_by_id();
}
void save_reviews_info(string reviews_file_path,GoodReads &gd){
    ifstream reviews_file(reviews_file_path);
    string reviews_info,reviews_info_section,temperory;
    getline(reviews_file,temperory);
    while(getline(reviews_file,reviews_info)){
        Review new_review;
        stringstream reviews_info_sections(reviews_info);
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_id(stoi(reviews_info_section));
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_book_id(stoi(reviews_info_section));
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_user_id(stoi(reviews_info_section));
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_rating(stoi(reviews_info_section));
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_date(reviews_info_section);
        getline(reviews_info_sections,reviews_info_section,MAJOR_SEPERATOR);
        new_review.set_likes(stoi(reviews_info_section));
        gd.add_reviews(new_review);
    }
    gd.sort_reviews_by_id();
    gd.find_reviews_details();
}
void save_follow_edges_info(string follow_file_path,GoodReads &gd){
    ifstream follows_file(follow_file_path);
    string follows_info,user_id,followings,followers,temperory;
    getline(follows_file,temperory);
    while(getline(follows_file,follows_info)){
        stringstream follows_info_sections(follows_info);
        getline(follows_info_sections,user_id,MAJOR_SEPERATOR);
        getline(follows_info_sections,followings,MAJOR_SEPERATOR);
        getline(follows_info_sections,followers);
        gd.update_user_follow_infos(user_id,followings,followers);
    }
}
void command_checker(GoodReads &gd){
    string command,command_type;
    while(getline(cin,command)){
        stringstream command_sections(command);
        getline(command_sections,command_type,SPACE_SEPERATOR);
        if(command_type=="show_author_info"){
            string author_id;
            getline(command_sections,author_id);
            gd.print_author_info(stoi(author_id));
        }
        else if(command_type=="show_sorted_shelf"){
            string shelf_type,user_id;
            Genre genre;
            getline(command_sections,user_id,SPACE_SEPERATOR);
            getline(command_sections,shelf_type,SPACE_SEPERATOR);
            getline(command_sections,genre);
            gd.show_user_sorted_shelf(stoi(user_id),shelf_type,genre);
        }
        else if(command_type=="credit"){
            string user_id;
            getline(command_sections,user_id);
            gd.show_user_credit(stoi(user_id));
        }
        else if(command_type=="best_book"){
            gd.show_best_book();
        }
        else if(command_type=="best_reviewer"){
            gd.show_best_reviewer();
        }
        else if(command_type=="recommend_first_approach"){
            string user_id;
            getline(command_sections,user_id);
            gd.show_first_approach(stoi(user_id));
        }
        else if(command_type=="recommend_second_approach"){
            string user_id;
            getline(command_sections,user_id);
            gd.show_second_approach(stoi(user_id));
        }
        else{
            cerr<<"INCORRECT COMMAND!"<<endl;
        }
    }
}
string file_path_maker(string folder_name,string file_name){
    stringstream file_path;
    file_path<<folder_name<<"/"<<file_name;
    return file_path.str();
}