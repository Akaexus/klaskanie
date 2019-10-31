#include <cstdio>

class Stack {
public:
    int stacksize;
    int* stack;
    int pointer = 0;


public:
    Stack(int size) {
        this->stacksize = size;
        this->stack = new int[size];
    }

    void push(int a) {
        this->stack[this->pointer] = a;
        this->pointer += 1;
    }
    int pop() {
        int value = this->stack[--this->pointer];
        return value;
    }

    int length() {
        return this->pointer - 1;
    }

    void empty() {
        this->pointer = 0;
    }

    void addMany(int a[], int size) {
        for (int i = 0; i < size; i++) {
            this->push(a[i]);
        }
    }
    void print() {
        for (int i=0; i<this->pointer; i++) {
            printf("%d: %d\n", i, this->stack[i]);
        }
    }
};

int main() {
    Stack s = Stack(1024);
    s.push(5);
    int ar[] = {123, 45, 67, 8, 9, 555};
    s.addMany(ar, sizeof(ar)/sizeof(*ar));
    printf("%d\n", s.pop());
    s.print();
}