#include <list>
#include <cstdio>

class Stack {
    protected:
        std::list <int> stack;
    public:
        void push(int value) {
            this->stack.push_back(value);
        }

        int pop() {
            int value = this->stack.back();
            this->stack.pop_back();
            return value;
        }

        unsigned long length() {
            return this->stack.size();
        }

        void print() {
            int index = 0;
            for (auto iter = this->stack.begin(); iter != this->stack.end(); iter++, index++ ) {
                printf("%d: %d\n", index, *iter);
            }
        }

        void addMany(int array[], int size) {
            for (int i = 0; i < size; i++) {
                this->push(array[i]);
            }
        }
};

int main() {
    int values[] = {68, 89, 4, 6, 8, 5, 6564, 1, 3, 3, 8, 7, 8, 4, 1, 1, 9, 1, 0, 1, 9, 9, 8, 7, 3, 4};
    Stack x = Stack();
    x.push(2137);
    x.addMany(values, sizeof(values)/sizeof(*values));
    x.pop();
    x.print();
}