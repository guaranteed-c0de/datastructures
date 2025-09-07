#include "csv.hpp"
#include <span>
#include <string>

using namespace std; 

string make_csv(span<const Person*> people){ //people is the name of the parameter.
    string out;

    
    out += "role,id,name,email,grad_year,office,courses,teaches\n"; //This is the superset header.     
    for (auto p : people) { 
        out += p->csv_row();  //This uses polymorphism
        out += "\n"; 
    }
    return out;
} //End of csv.cpp
