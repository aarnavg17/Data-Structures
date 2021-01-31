#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode(int data, ListNode* next) {
        this->data = data;
        this->next = next;
    }

    int data;
    ListNode *next{};
};

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
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    MyStack MS;
    MS.Push(5);
    MS.Push(10);
    MS.Push(15);
    MS.display();
    cout << MS.Pop() << endl;
    MS.display();
    cout << MS.Pop() << endl;
    cout << MS.Pop() << endl;
    cout << MS.IsEmpty() << endl;
}