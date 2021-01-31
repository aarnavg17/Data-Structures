#include <iostream>
using namespace std;

class MyStack {
public:
    MyStack(int);
    bool IsEmpty();
    bool IsFull();
    void push(int);
    void pop();
    void top_value();
    void display();

private:
    int* data;
    int top;
    int MAXSize;


};

MyStack::MyStack(int size) {
    data = new int[size];
    top = -1;
    MAXSize = size;
}

bool MyStack::IsEmpty() {
    return (top == -1);
}

bool MyStack::IsFull() {
    return (top == MAXSize - 1);
}

void MyStack::push(int x) {
    if (!IsFull()) {
        top++;
        data[top] = x;
    }
    else cout << "Stack is full.";
}

void MyStack::pop() {
    if (!IsEmpty()) {
        cout << data[top];
        top--;
    }
    else cout << "Nothing to pop.";
}

void MyStack::top_value() {
    if (!IsEmpty()) cout << data[top];
    else cout << "Nothing to return.";
}

void MyStack::display() {
    if (!IsEmpty()) for (int i = top; i >= 0; i--) cout << data[i] << " ";
    else cout << "Nothing to display.";
}

int main() {
    MyStack* TS = new MyStack(100);
    TS->push(10);
    TS->push(50);
    TS->pop();
    cout << "\n";
    TS->push(70);
    TS->push(80);
    TS->top_value();
    cout << "\n";
    TS->display();
}