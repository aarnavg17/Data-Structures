//Infix to Postfix

#include <iostream>
#include <string>
#include <stack>
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
    stack<char> in_exp;
    stack<char> post_exp;
    string expression;
    char s;
    in_exp.push('#');
    cout << "Enter an infix expression: ";
    getline(cin, expression);
    for (char sym : expression) {
        if (sym == '\n' || sym == '\0')
            break;
        else if ((sym >= '0' && sym <= '9') || (sym >= 'A' && sym <= 'Z')) post_exp.push(sym);
        else if (sym == ')') {
             do {
                s = in_exp.top();
                in_exp.pop();
                post_exp.push(s);
            } while(in_exp.top() != '(');
            in_exp.pop();
        }
        else if (sym == '(')
            in_exp.push('(');
        else {
            while (precedence(in_exp.top()) > precedence(sym)) {
                s = in_exp.top();
                in_exp.pop();
                post_exp.push(s);
            }
            in_exp.push(sym);
        }
    }
    while(in_exp.top() != '#') {
        s = in_exp.top();
        in_exp.pop();
        if (s != '(')
            post_exp.push(s);
    }
    stack<char> final_stack;
    while(not post_exp.empty()) {
        char x = post_exp.top();
        post_exp.pop();
        cout << x;
        final_stack.push(x);
    }
    while (!final_stack.empty()) {
        char x = final_stack.top();
        final_stack.pop();
        cout << x << " ";
    }
}
