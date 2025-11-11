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
int main() {
    Cat* midori = new Cat(); //OK: Cat is not an abstract class. It has virtual methods that can be overridden in derived classes. This line creates a Cat object and stores its pointer in the midori pointer variable.
    Cat* tofu = new Siamese(); //OK: Upcasts from Siamese to Cat. tofu points to a Siamese object, but the compiler will treat it as a Cat pointer.
    Calico* fish = (Calico*) new Cat(); //OK: It's a C-Style cast. It can be dangerous. A Cat object is created on the map, but its pointer is forcibly reinterpreted as a Calico*. There is no Calico object. Only a Cat object. What about Calico* fish = new Cat()? Perhaps a faulty way to downcast...
    Calico* cliff = new Calico(); //OK: No casting, just an allocation in memory.
    Calico* minou = (Calico*) new Siamese(); //OK: Doesn't cause a compiler error. It's a C-Style cast. C-Style casting is very permissive, even for sibling classes. This creates a Siamese object, and then reinterpret its memory address as a pointer to Calico.
    Siamese* luna = new Siamese(); //OK: Pointer and object types match.
    cliff->meow(luna); //Will print "meep."
    ((Cat*) cliff) -> meow(luna); //"meow": cliff is upcasted to a Cat pointer. Now, in C++, any pointer to a derived type can be implicitly converted to a pointer to its base type. So luna can be automatically treated as a Cat*.
    midori->meow(luna); //"meow": luna can be converted to a Cat*.
    ((Cat*)cliff)->scratch(tofu); //Even though we casted cliff to a Cat*, the virtual dispatch system still uses the dynamic type of the actual object (Calico). So the Calico version of scratch(Cat*) executes, not the Cat version. Casting to a base pointer type does not disable virtual dispatch in C++. It only changes which functions are visible to the compiler, but at runtime, the actual object's type determines which version of the virtual function runs.
    midori->scratch(tofu); //midori is a Cat* to a real Cat object. tofu is a Cat* (points to a Siamese), which mathces Cat::scratch (Cat*).
    midori->scratch(cliff); //midori is a Cat* to a Cat object. cliff is a Calico*. There's an implicit upcast from Calico* to Cat* for the paremeter type. So this again calls Cat::scratch(Cat*), with midori being an actual Cat.
    midori->scratch((Calico*) tofu); //This force casts a Siamese* into a Calico*. Technically unsafe, but it compiles. C++ allows C-style casts even if teh types are unrelated - one just gets undefined behavior if they dereference or use it incorrectly. Even though the cast (Calico*)tofu is dangerous, it doesn't change what function is called- it just reinterprets the pointer before the argument is passed up to Cat*.
    //cliff->meow(midori); //When you write cliff->meow(midori), the compiler looks for a matching overload among Calico's meow functions. Calico only defines void meow(Siamese* s). There's no implicit conversion from Cat* to Siamese*, which would be a downcast, and there's no meow(Cat*) in any base class that's visible here. Therefore, this is acompiler error.
    tofu->scratch(midori); //tofu is declared as Cat* but points to a Siamese. midori is a Cat* to a Cat. So the call is to scratch(Cat*, which is virtual. At compile time, the function signature mathces Cat::scratch(Cat*). At runtime, the dynamic type of the caller (tofu) is Siamese. That means Siamese::scratch(Cat*) overrides and executes. "big scratch" is the output. Since the object tofu points to is a Siamese, its override runs.
}