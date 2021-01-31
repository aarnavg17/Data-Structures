#include <iostream>
#include <string>
#include "MyStack.h"
#include "ListNode.h"
using namespace std;

int precedence(char sym) {
    switch (sym) {
        case '#':
            return 0;
            break;
        case '(':
            return 1;
            break;
        case '+':
            return 2;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 3;
            break;
        case '^':
            return 4;
            break;
        default:
            return 0;
            break;
    }
}

int main() {
    MyStack in_exp;
    MyStack post_exp;
    string expression;
    char s;
    in_exp.Push('#');
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    //cout << expression;
    for (char sym : expression) {
        //cout << sym;
        //cin >> sym;
        if (sym == '\n' || sym == '\0') break;
        else if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z')) post_exp.Push(sym);
        else if (sym == ')') {
            //ListNode* temp = in_exp.Top;
             do {
                s = in_exp.Pop();
                post_exp.Push(s);
            } while(in_exp.Top_Value() != '(');
            in_exp.Pop();
        }
        else if (sym == '(') in_exp.Push('(');
        else {
            while (precedence(in_exp.Top_Value()) > precedence(sym)) {
                s = in_exp.Pop();
                post_exp.Push(s);
            }
            in_exp.Push(sym);
        }
    }
    while(in_exp.Top_Value() != '#') {
        s = in_exp.Pop();
        if (s != '(') post_exp.Push(s);
    }
    post_exp.display();
    //exp.display();
}
