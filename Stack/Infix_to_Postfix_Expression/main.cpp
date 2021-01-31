#include <iostream>
#include <string>
#include "MyStack.h"
#include "ListNode.h"
using namespace std;

int main() {
    MyStack in_exp;
    MyStack post_exp;
    string expression;
    char s;
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    //cout << expression;
    for (char sym : expression) {
        //cout << sym;
        //cin >> sym;
        if (sym == '\n' || sym == '\0') break;
        else if (sym >= '0' && sym <= '9') post_exp.Push(sym);
        else if (sym == ')') {
            ListNode* temp = in_exp.Top;
            while(temp -> next -> data != '(') {
                s = in_exp.Pop();
                post_exp.Push(s);
            }
        }
        else in_exp.Push(sym);
    }
    while(!in_exp.IsEmpty()) {
        s = in_exp.Pop();
        if (s != '(') post_exp.Push(s);
    }
    post_exp.display();
    //exp.display();
}