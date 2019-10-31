#include <stdio.h>

int rfib(int n) {
    if (n < 2) {
        return 1;
    } else {
        return rfib(n-1) + rfib(n-2);
    }
}

int f = 0;

void fib(int n) {
    if (n < 2) {
        f = 1;
        return;
    } else {
        int x1 = 1;
        int x2 = 1;
        for (int i = 1; i<n; i++) {
            int tmp = x2;
            x2 += x1;
            x1 = tmp;
        }
        f = x2;
    }
}


int main() {
    for (int i = 0; i < 10; i++) {
        printf("%d\n", rfib(i));
    }
    printf("\n\n\n");
    for (int i = 0; i < 10; i++) {
        fib(i);
        printf("%d\n", f);
    }
}