#include "Stack.h"
#include <iostream>
using namespace std;
int evaluatePostfix(string, Stack&);
int main()
{
   Stack Basic;
    for (int x = 0; x < 100; x++)
    {
        Basic.push(x + 1);
    }
    for (int y = 0; y < 100; y++)
    {
        cout << Basic.pop() << endl;
    } 
 // cout << evaluatePostfix("231*+4-", Basic) << endl;
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