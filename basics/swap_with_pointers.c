#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int c, d;

    printf("Enter any two numbers: ");
    scanf("%d %d", &c, &d);
    swap(&c, &d);
    printf("The swap is: %d %d\n\n", c, d);

    return 0;
}
