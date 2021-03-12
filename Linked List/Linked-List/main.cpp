#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prv;
    Node() {
        prv = nullptr;
        next = nullptr;
        data = 0;
    }
    Node (int data, Node* next, Node* prv) {
        this -> data = data;
        this -> next = next;
        this -> prv = prv;
    }
};

class LinkedList {
    Node* head;
    Node* tail;
    int len;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        len = 0;
    }

    void append(int data) {
        if (head != nullptr) {
            Node* newNode = new Node(data, nullptr, tail);
            tail -> next = newNode;
            tail = newNode;
        }
        else {
            Node* newNode = new Node(data, nullptr, nullptr);
            tail = newNode;
            head = newNode;
        }
        len++;
    }

    int length() {
        return len;
    }

    void display() {
        Node* x = head;
        if (x == nullptr) {
            cout << "Empty\n";
            return;
        }
        while(x != nullptr) {
            cout << x -> data << " ";
            x = x -> next;
        }
        cout << endl;
    }

    void inserting(int data, int pos) {
        if (pos >= len) append(data);
        else if (pos == 0) {
            Node* newNode = new Node(data, head, nullptr);
            head = newNode;
            len++;
        }
        else if (pos > len/2) {
            Node* x = tail;
            for (int i = len-1; i > pos; i--)
                x = x -> prv;
            Node* store = x;
            x = x -> prv;
            Node* newNode = new Node(data, store, x);
            x -> next = newNode;
            store -> prv = newNode;
            len++;
        }
        else {
            Node* x = head;
            for (int i = 0; i < pos-1; i++)
                x = x -> next;
            Node* store = x;
            x = x -> next;
            Node* newNode = new Node(data, x, store);
            x -> prv = newNode;
            store -> next = newNode;
            len++;
        }
    }

    void deleting(int pos) {
        if (len == 0)
            cout << "List underflow";
        else {
            Node* x = head;
            if (pos == 0) {
                head = head -> next;
                head -> prv = nullptr;
            }
            else if (pos == len-1) {
                x = tail;
                tail = tail -> prv;
                tail -> next = nullptr;
            }
            else {
                if (pos < len/2)
                    for (int i=0; i < pos; i++)
                        x = x -> next;
                else {
                    x = tail;
                    for (int i=0; i < len-pos-1; i++)
                        x = x -> prv;
                }
                x -> prv -> next = x -> next;
                x -> next -> prv = x -> prv;
            }
            delete(x);
            len--;
        }

    }

    void clearing() {
        Node* x = head;
        for (int i = 0; i < len; i++) {
            Node* y = x -> next;
            delete(x);
            Node* x = y;
        }
        head = tail = nullptr;
    }

    bool has(int num) {
        for (Node* x = head; x != tail; x = x -> next)
            if (x -> data == num)
                return true;
        return false;
    }
};

class CircularLinkedList {
    Node* head;

public:
    int len;
    CircularLinkedList() {
        head = nullptr;
        len = 0;
    }

    void append(int data) {
        if (head != nullptr) {
            Node* newNode = new Node(data, head, head -> prv);
            newNode -> prv -> next = newNode;
            head -> prv = newNode;
        }
        else {
            head = new Node(data, head, head);
            head -> next = head;
            head -> prv = head;
        }
        len++;
    }

    int length() {
        return len;
    }

    void display() {
        if (head == nullptr)
            cout << "Empty.";
        else {
            Node* x = head;
            do {
                cout << x -> data << " ";
                x = x -> next;
            } while(x != head);
        }
        cout << endl;
    }

    void inserting(int data, int pos) {
        if (pos > len)
            inserting(data, pos-len);
        if (pos < 0)
            pos += len;
        if (pos == len) {
            append(data);
            return;
        }
        if (pos == 0)
            pos = len;
        Node* x = head;
        for (int i = 0; i < pos-1; i++)
            x = x -> next;
        Node* store = x;
        x = x -> next;
        Node* newNode = new Node(data, x, store);
        x -> prv = newNode;
        store -> next = newNode;
        if (pos == len)
            head = newNode;
        len++;
    }

    void deleting(int pos) {
        if (len == 0)
            cout << "List underflow";
        else {
            Node* x = head;
            if (pos == 0) {
                head -> prv -> next = head -> next;
                head -> next -> prv = head -> prv;
                head = head -> next;
            }
            else {
                for (int i=0; i < pos; i++) {
                    x = x -> next;
                }
                x -> prv -> next = x -> next;
                x -> next -> prv = x -> prv;
            }
            delete(x);
            len--;
        }
    }

    void clearing() {
        Node* x = head;
        for (int i = 0; i < len; i++) {
            Node* y = x -> next;
            delete(x);
            Node* x = y;
        }
        head = nullptr;
    }
};

int main() {

}
