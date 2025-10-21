//
//With templates, we minimize rewriting code.
//... Code reuse?
//Runtime vs. compile time?

#include <iostream>
#include <string>
using namespace std;


template <typename T1, typename T2>
class Pair {
    private:
        T1 first;
        T2 second;
    public:
    Pair(T1 f, T2 s) : first(f), second(s) {}
    T1 getFirst() {
        return first;
    }
    T2 getSecond() {
        return second;
    }
};
template <typename T, int Size>
class FixedArray{
T data[Size];
};
template <typename... Args> //So, it can take multiple arguments...
void print(Args... args) {
    cout << ... << args) << endl;
}

template<>
/*const char* max<const char*>(const char* a, const char* b){
    return std::strlen(a) > std::strlen(b) ? a: b; //Strings that use the string class... Strings that are C-based.
}*/ //In the C language.... there are no objects... There are structs... For strings.... the memory has the string. So, the actual address? \0
//Find...
//Special cases? cons
int main() {
    int a = 10;
    int b = 20;
  
   // cout << max(4.5, 3.2) << endl; //What time of error is it? Compiler error, I'm sure...
   // cout << max('a', 'D') << endl;
   // cout << max("Hello", "Hi"); //What errors show up at compile time? Syntax... Syntax => Compile time
    //But how do I know if the syntax is wrong?
    Pair <int, double> p1(10, 20.5); //If the types don't match, that is a compiler error.
    Pair<string, char> p2("Hello", '!');
    Pair<string, float> p3("Hello", 3.14);
    cout << p1.getFirst() << endl;
    cout << p1.getSecond() << endl;
    cout << p2.getFirst() << endl;
    cout << p2.getSecond() << endl;
    cout << p3.getFirst() << endl;
    cout << p3.getSecond() << endl;
    print(1, 2, 3, 4, 5);
    print("Hello ", "World!");
}