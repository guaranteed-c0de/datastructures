#include "csv.hpp"
using namespace std; 

string make_csv(std::span<const Person*> people) { //people is the name of the parameter.
    string out;

    
    out += "role,id,name,email,grad_year,office,courses,teaches\n"; //This is the superset header.     
    for (auto p : people) { //These write the rows.
        out += p->csv_row();  //This uses polymorphism
        out += "\n"; 
    }
    return out;
} //End of csv.cpp
