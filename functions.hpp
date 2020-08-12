#ifndef FUNCTIONS_H
#define FUNCTIONS_H "FUNCTIONS"
#include"GoodReads.hpp"
std::string file_path_maker(std::string folder_name,std::string file_name);
void command_checker(GoodReads &gd);
void save_follow_edges_info(std::string follow_file_path,GoodReads &gd);
void save_reviews_info(std::string reviews_file_path,GoodReads &gd);
void save_users_info(std::string users_file_path,GoodReads &gd);
void save_authors_info(std::string authors_file_path,GoodReads &gd);
void save_books_info(std::string books_file_path,GoodReads& gd);
#endif