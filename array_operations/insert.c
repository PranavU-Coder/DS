#include <stdio.h>
#include <stdlib.h>

int* insert(int arr[], int *size, int pos, int element) {
    if (pos < 0 || pos > *size) {
        printf("Invalid position -> Out Of Bounds\n");
        return arr;
    }

    int *newArr = (int *)realloc(arr, (*size + 1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory reallocation failed.\n");
        exit(0);
    }

    for (int i = *size; i > pos; i--) {
        newArr[i] = newArr[i - 1];
    }

    newArr[pos] = element;
    (*size)++;

    return newArr;
}

int main()
{
    int i, n, pos, newElement, *ptr;

    printf("Enter the number of elements to add:\n");
    scanf("%d", &n);

    ptr = (int *)malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    printf("Enter the position to insert (0 to %d):\n", n);
    scanf("%d", &pos);

    printf("Enter the element to insert:\n");
    scanf("%d", &newElement);

    ptr = insertAtPosition(ptr, &n, pos, newElement);

    printf("Updated Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
