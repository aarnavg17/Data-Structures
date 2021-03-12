//
//  main.cpp
//  Postfix
//
//  Created by Aarnav Gupta on 11/03/21.
//

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    stack <int> exp;
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);
    for (char sym : expression) {
        if (sym == ' ')
            continue;
        if (sym == '\n' || sym == '\0')
            break;
        else if (sym >= '0' && sym <= '9')
            exp.push((int)sym - '0');
        else {
            int a, b;
            a = exp.top();
            exp.pop();
            b = exp.top();
            exp.pop();
            switch(sym) {
                case '+':
                    exp.push(b+a);
                    break;
                case '-':
                    exp.push(b-a);
                    break;
                case '*':
                    exp.push(b*a);
                    break;
            }
        }
    }
}
