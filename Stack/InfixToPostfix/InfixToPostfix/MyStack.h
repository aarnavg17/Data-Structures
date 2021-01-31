//
// Created by Aarnav Gupta on 31/01/21.
//

#include "ListNode.h"

#ifndef POSTFIXEXPRESSION_MYSTACK_H
#define POSTFIXEXPRESSION_MYSTACK_H


class MyStack {
public:
    MyStack() {
        Top = nullptr;
    }
    char Pop();
    bool IsEmpty();
    void Push(char);
    char Top_Value();
    ListNode *Top;

    void display();
};

void MyStack::Push(char new_item) {
    ListNode* p;
    p = new ListNode(new_item, Top);
    Top = p;
    std::cout << std::endl << "The new stack is: ";
    this->display();
}

char MyStack::Pop() {
    if (!IsEmpty()) {
        char rtn_value;
        rtn_value = Top -> data;
        Top = Top -> next;
        return rtn_value;
    }
    else return '\0';
}

bool MyStack::IsEmpty() {
    return (Top == nullptr);
}

void MyStack::display() {
    ListNode* temp = Top;
    while(temp != nullptr) {
        std::cout << temp -> data << " ";
        temp = temp -> next;
    }
    std::cout << std::endl;
}

char MyStack::Top_Value() {
    return Top -> data;
}

#endif //POSTFIXEXPRESSION_MYSTACK_H