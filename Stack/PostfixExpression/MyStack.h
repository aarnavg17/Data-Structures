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
    int Pop();
    bool IsEmpty();
    void Push(int);
    ListNode *Top;

    void display();
};

void MyStack::Push(int new_item) {
    ListNode* p;
    p = new ListNode(new_item, Top);
    Top = p;
    std::cout << std::endl << "The new stack is: ";
    this->display();
}

int MyStack::Pop() {
    ListNode* p;
    if (!IsEmpty()) {
        int rtn_value;
        rtn_value = Top -> data;
        Top = Top -> next;
        return rtn_value;
    }
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

#endif //POSTFIXEXPRESSION_MYSTACK_H