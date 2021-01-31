#include <iostream>
using namespace std;
class Stack {
public:
    Stack (int initCap = 100);
    Stack (const Stack& rhs);
    ~Stack();

    void push(Item x);
    void pop(Item& x);

private:
    void realloc(int newCap);
    Item* data;
    int size;
    int cap;
};

void Stack::push(Item x) {

}
