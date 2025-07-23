#include <stdio.h>

void sort(int *arr, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main(void) {
    int num;
    printf("Enter number of elements: ");
    scanf("%d", &num);

    int arr[num];
    for (int i = 0; i < num; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    sort(arr, num);

    printf("Sorted elements are: ");
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
