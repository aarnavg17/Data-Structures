//
//  main.cpp
//  Infix-Evaluate
//
//  Created by Aarnav Gupta on 13/03/21.
//

#include <iostream>
#include <stack>
using namespace std;
 
int precedence(char op) {
    if(op == '+' or op == '-')
        return 1;
    if(op == '*' or op == '/')
        return 2;
    return 0;
}
 
int main() {
    int i;
    stack <int> values;
    stack <char> ops;
    string infix_exp;
    getline(cin, infix_exp);
     
    for(i = 0; i < infix_exp.length(); i++) {
        if(infix_exp[i] == ' ')
            continue;
        else if(infix_exp[i] == '(')
            ops.push(infix_exp[i]);
        else if(isdigit(infix_exp[i])){
            int val = 0;
            while(i < infix_exp.length() and isdigit(infix_exp[i])) {
                val = (val*10) + (infix_exp[i]-'0');
                i++;
            }
            values.push(val);

              i--;
        }
        else if(infix_exp[i] == ')') {
            while(!ops.empty() and ops.top() != '(') {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                switch(op) {
                    case '+':
                        values.push(a+b);
                        break;
                    case '-':
                        values.push(a-b);
                        break;
                    case '*':
                        values.push(a*b);
                        break;
                    case '/':
                        values.push(a/b);
                        break;
                }
            }
            if(not ops.empty())
               ops.pop();
        }
        else {
            while(!ops.empty() and precedence(ops.top()) >= precedence(infix_exp[i])){
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = ops.top();
                ops.pop();
                switch(op) {
                    case '+':
                        values.push(a+b);
                        break;
                    case '-':
                        values.push(a-b);
                        break;
                    case '*':
                        values.push(a*b);
                        break;
                    case '/':
                        values.push(a/b);
                        break;
                }
            }
            ops.push(infix_exp[i]);
        }
    }
    while(!ops.empty()){
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = ops.top();
        ops.pop();
        switch(op) {
            case '+':
                values.push(a+b);
                break;
            case '-':
                values.push(a-b);
                break;
            case '*':
                values.push(a*b);
                break;
            case '/':
                values.push(a/b);
                break;
        }
    }
    return values.top();
}
