#include <stdio.h>

#define stacksize 1024


int stack[stacksize];
int pointer = 0;

void push(int a) {
    stack[pointer] = a;
    a++;
}

int pop() {
    return stack[pointer--];
}

int length() {
    return pointer - 1;
}

void empty() {
    pointer = 0;
}

void addMany(int a[], int size) {
    for (int i = 0; i < size; i++) {
        push(a[i]);
    }
}

int main() {
    push(2);
    printf("%d\n", pop());
    int ar[] = {8, 3, 1, 3};
    int arsize = sizeof(ar)/sizeof(int);
    addMany(ar, arsize);
    printf("%d\n", pop());
}
