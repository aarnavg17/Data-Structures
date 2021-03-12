//
//  main.cpp
//  Implementation
//
//  Created by Aarnav Gupta on 12/03/21.
//

#include<iostream>
using namespace std;

class BinarySearchTree {
    
    struct node {
        int data;
        node* left;
        node* right;
        node* parent;
    };

    node* root;

    node* clear(node* t) {
        if(t == NULL)
            return NULL;
        clear(t -> left);
        clear(t -> right);
        delete t;
        return NULL;
    }

    node* insert(int x, node* t) {
        if(t == NULL) {
            t = new node;
            t -> data = x;
            t -> left = NULL;
            t -> right = NULL;
            t -> parent = NULL;
        }
        else if(x < t -> data) {
            t -> left = insert(x, t -> left);
            t -> left -> parent = t;
        }
        else if(x > t -> data) {
            t -> right = insert(x, t -> right);
            t -> right -> parent = t;
        }
        return t;
    }

    node* findMin(node* t) {
        if(t == NULL)
            return NULL;
        else if(t -> left == NULL)
            return t;
        else
            return findMin(t -> left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t -> right == NULL)
            return t;
        else
            return findMax(t -> right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t -> data)
            t -> left = remove(x, t -> left);
        else if(x > t -> data)
            t -> right = remove(x, t -> right);
        else if(t -> left && t -> right) {
            temp = findMin(t -> right);
            t -> data = temp -> data;
            t -> right = remove(t -> data, t -> right);
        }
        else {
            temp = t;
            if(t -> left == NULL)
                t = t -> right;
            else if(t -> right == NULL)
                t = t -> left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t -> left);
        cout << t -> data << " ";
        inorder(t -> right);
    }
    
    void preorder(node* t) {
        if (t == NULL)
            return;
        cout << t -> data << " ";
        preorder(t -> left);
        preorder(t -> right);
    }
    
    void postorder(node* t) {
        if (t == NULL)
            return;
        postorder(t -> left);
        postorder(t -> right);
        cout << t -> data << " ";
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        preorder(root);
        postorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }
};

int main() {
    BinarySearchTree t;
}
