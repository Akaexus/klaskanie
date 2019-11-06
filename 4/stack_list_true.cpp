#include <cstdio>
#include <cstdlib>


struct StackElement {
    int value;
    struct StackElement* prev;
};


class Stack {
protected:
    struct StackElement* elem;
    int stackElementSize;
public:
    Stack() {
        this->elem = nullptr;
        this->stackElementSize = sizeof(struct StackElement);
    }
    ~Stack() {
        free(this->elem);
    }

    void push(int value) {
        struct StackElement* previousAddress = this->elem;
        this->elem = (struct StackElement*)malloc(this->stackElementSize);
        (*this->elem).value = value;
        (*this->elem).prev = previousAddress;
    }

    int pop() {
        if (this->elem != nullptr) {
            int value = (*this->elem).value;
            this->elem = (*this->elem).prev;
            return value;
        } else {
            return 0;
        }
    }
};

int main(){
    Stack s = Stack();
    s.push(6);
    int v = s.pop();
    printf("%d\n", v);
    s.push(5);
    v = s.pop();
    printf("%d\n", v);
}