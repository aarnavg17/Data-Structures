#include <iostream>
#include <string>
#include "MyStack.h"
using namespace std;

int main() {
    MyStack exp;
    string expression;
    char sym;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);
    //cout << expression;
    for (char sym : expression) {
        //cout << sym;
        //cin >> sym;
        if (sym == '\n' || sym == '\0') break;
        else if (sym >= '0' && sym <= '9') exp.Push((int)sym - '0');
        else {
            int a, b;
            a = exp.Pop();
            b = exp.Pop();
            switch(sym) {
                case '+':
                    exp.Push(b+a);
                    break;
                case '-':
                    exp.Push(b-a);
                    break;
                case '*':
                    exp.Push(b*a);
                    break;
            }
        }
    }
    //exp.display();
}