#include <stdio.h>

struct rectangle {
    float length;
    float breadth;
};

int main(void) {
    struct rectangle r;

    printf("Enter length and breadth: ");
    scanf("%f %f", &r.length, &r.breadth);

    printf("Area = %f\n", r.length * r.breadth);

    return 0;
}
