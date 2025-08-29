#include <iostream>
#include <string>
#include <stdexcept> 
namespace LibSystem {

using std:: string;
struct BookRecord {
string title;
string author;
int id; //Access? Here, all variables are public. 

void setDetails(const string& t, const string& a, int i){
  title = t;
  author = a;
  id = i;
}

}
}
