#include <stdio.h>
#include <stdlib.h>

int* delete(int arr[], int *size, int pos) {
    if (pos < 0 || pos >= *size) {
        printf("Invalid position.\n");
        return arr;
    }

    for (int i = pos; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    int *newArr = (int *)realloc(arr, (*size - 1) * sizeof(int));
    if (newArr == NULL && *size > 1) {
        printf("Memory reallocation failed.\n");
        exit(0);
    }

    (*size)--;
    return newArr;
}

int main()
{
    int i, n, pos, *ptr;

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

    printf("Enter the position to delete (0 to %d):\n", n - 1);
    scanf("%d", &pos);

    ptr = delete(ptr, &n, pos);

    printf("Updated Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
