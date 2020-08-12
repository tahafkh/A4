#include"Date.hpp"
#include<iostream>
#include<sstream>
#define SPACE_SEPERATOR ' '
using namespace std;
void Date::print_date(){
    cout<<month<<" "<<day<<" "<<year<<endl;
}
void Date::string_to_date(string date){
    string date_info_section;
    stringstream date_sections(date);
    getline(date_sections,date_info_section,SPACE_SEPERATOR);
    month=date_info_section;
    getline(date_sections,date_info_section,SPACE_SEPERATOR);
    day=stoi(date_info_section);
    getline(date_sections,date_info_section);
    year=stoi(date_info_section);
}