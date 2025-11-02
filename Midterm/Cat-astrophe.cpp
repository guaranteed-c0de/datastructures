#include <iostream>

using namespace std;

class Cat {
public:
        virtual void scratch(Cat* c) {
            cout << "scrathy scratch\n"; }
        virtual void meow(Cat* c) {cout << "meow\n"; }
};

class Siamese : public Cat {
public:
    void scratch(Cat* c) override {
        cout << "big scratch\n"; }
    void scratch(Siamese* s) {cout << "fat scratch\n";
    }
    void scratch(class Calico* c); //defined later
    void meow(Cat* c) override {cout << "purr\n"; }
};

class Calico : public Cat {
    public:
        void scratch(Cat* c) override { cout << "regular scratch\n"; }
        void scratch(Calico* c) {
            cout << "light scratch\n"; }
        void meow(Siamese* s) {cout << "meep\n";}
};

//Siamese scratch(Calico*) defined here
void Siamese::scratch(Calico* c) {
    cout << "fighting scratch\n";
}