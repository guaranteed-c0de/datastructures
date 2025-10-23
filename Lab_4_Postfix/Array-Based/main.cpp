#include <iostream>
#include <string>
#include <cctype>
using namespace std;
#include "Stack.h"
int evaluatePostfix(string, Stack&);
int main() {
    
    Stack Plain;
   cout << Plain.peek() << endl;
   cout << Plain.pop() << endl;

    for (int i = 1; i<= 10; i++) //Push 10 elements (1-10)
    {
        Plain.push(i);
    }

    for (int i = 1; i <= 5; i++)
    {
        cout << Plain.pop();
        cout << endl;
    }
  while (true)
   {
    int x = 3;
     if (Plain.isFull())
    {
        Plain.push(x);
        break;
    }
    Plain.push(x);
    x++;
   
   } 
  //cout << Plain.pop();
  //cout << Plain.peek();

 // cout << evaluatePostfix("", Plain);

  //cout << evaluatePostfix("12-3*4+5-6*7+8/", Plain);

  cout << endl;
    return 0;
}
int evaluatePostfix(string expr, Stack& stack) {
for (char i: expr) {
    if(isdigit(i)) {
        stack.push(i - '0');
    }
    else if(i == '*' || i == '+' || i == '-' || i == '/')
    {
        int b = stack.pop();
        int a = stack.pop();
        if(i == '*')
        stack.push(a*b);
        else if (i == '+')
        stack.push(a+b);
        else if (i == '-')
        stack.push(a - b);
        else if (i == '/')
        stack.push(a/b);
    }
    else {
        return -999;
    }
}
return stack.pop();
}