//
//  main.cpp
//  Skip List Implementation
//
//  Created by Aarnav Gupta on 12/06/21.
//

#include <iostream>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* right;
    Node* down;
    Node() {
        this -> right = nullptr;
        this -> down = nullptr;
        this -> data = -1;
    }
    Node(Node* right, Node* down, int data) {
        this -> right = right;
        this -> down = down;
        this -> data = data;
    }
};

class Skiplist {
public:
    Node* head;
    Skiplist() {
        this -> head = new Node();
    }
    
    bool search(int target) {
        Node* temp = this -> head;
        while(temp and temp -> data < target) {
            if(temp -> right and temp -> right -> data <= target) temp = temp -> right;
            else if(temp -> down) temp = temp -> down;
            else return false;
        }
        return true;
    }
    
    void add(int num) {
        Node* temp = this -> head;
        stack<Node*> preLevels;
        while(temp) {
            while(temp -> right) {
                if(temp -> right -> data >= num) {
                    preLevels.push(temp);
                    break;
                }
                else temp = temp -> right;
            }
            temp = temp -> down;
        }
        bool insertUp = true;
        Node* newNode = nullptr;
        while(insertUp and not preLevels.empty()) {
            Node* pre = preLevels.top();
            preLevels.pop();
            newNode = new Node(pre -> right, newNode, num);
            pre -> right = newNode;
            
            insertUp = (rand() & 4) == 0;
        }
        if(insertUp) this -> head = new Node(new Node(nullptr, newNode, num), head, -1);
    }
    
    bool erase(int num) {
        Node* pre = this -> head;
        Node* preUp = nullptr;
        bool result = false;
        while(pre) {
            while(pre -> right) {
                if(pre -> right -> data == num) {
                    if(preUp == nullptr) {
                        preUp = pre -> right;
                        pre -> right = pre-> right -> right;
                        result = true;
                        break;
                    }
                    else if(preUp -> down != pre -> right) pre = pre -> right;
                    else {
                        preUp = pre -> right;
                        pre -> right = pre -> right -> right;
                        result = true;
                        break;
                    }
                }
                else if(pre -> right -> data < num) pre = pre -> right;
                else break;
            }
            pre = pre -> down;
        }
        return result;
    }
};
