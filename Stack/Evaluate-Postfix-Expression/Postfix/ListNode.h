//
//  ListNode.h
//  Postfix
//
// Created by Aarnav Gupta on 31/01/21.
//

#ifndef POSTFIXEXPRESSION_LISTNODE_H
#define POSTFIXEXPRESSION_LISTNODE_H


class ListNode {
public:
    ListNode(int data, ListNode* next) {
        this->data = data;
        this->next = next;
    }

    int data;
    ListNode *next{};
};


#endif //POSTFIXEXPRESSION_LISTNODE_H
