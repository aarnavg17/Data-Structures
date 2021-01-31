#include<iostream>
#include<cstring>
using namespace std;

class Stack {
private:
    int *p;
    int top, length;
public:
    Stack(int = 0);
    ~Stack();

    void push(int);
    void pop();
    void display();
};

Stack::Stack(int size) {
    top = -1;
    length = size;
    while (length <= 0) {
        cout << "Invalid size" << endl;
        cout << "Enter new length: ";
        cin >> length;
    }
    p = new int[length];
}

Stack::~Stack() {
    delete [] p;
}

void Stack::push(int elem) {
    if(top == (length-1)) {
        int *pTemp = new int[length + 1];
        memcpy(pTemp, p, length);
        delete[] p;
        p = pTemp;
    }
    top++;
    p[top] = elem;
}

void Stack::pop() {
    if (top == -1) cout << "Empty stack";
    else {
        int rtn_value = p[top];
        top--;
        cout << rtn_value << endl;
    }
}

void Stack::display() {
    for (int i = 0; i <= top; ++i) cout << p[i] << " ";
    cout << endl;
}

int main() {
    int len, num;
    cout << "Enter the size of the stack: ";
    cin >> len;
    Stack s1(len);
    cout << "Enter numbers: ";
    for (int i = 0; i < len; i++) {
        cin >> num;
        s1.push(num);
    }
    s1.display();
    s1.pop();
    s1.display();
    s1.push(4);
    s1.display();
    s1.push(8);
    s1.display();
}
