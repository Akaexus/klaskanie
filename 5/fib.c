#include <stdio.h>

int fa(x) {
    int sum = 0;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < i; j++) {
            sum += 1;
        }
    }
    return sum;
}

int fb(x) {
    int sum = 0;
    for (int i=1; i<=x; i++) {
        sum += i;
    }
    return sum;
}

int main() {
    printf("fa: %d\n", fa(6));
    printf("fb: %d\n", fa(6));
}