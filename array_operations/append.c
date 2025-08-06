#include <stdio.h>
#include <stdlib.h>

int* append(int arr[], int *size, int element) {
    int *newArr = (int *)realloc(arr, (*size + 1) * sizeof(int));
    if (newArr == NULL) {
        printf0("Memory reallocation failed.\n");
        exit(0);
    }

    newArr[*size] = element;
    (*size)++;
    return newArr;
}

int main()
{
    int i, n, *ptr;

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

    int newElement;
    printf("Enter an element to append:\n");
    scanf("%d", &newElement);
    ptr = append(ptr, &n, newElement);

    printf("New Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;`
}
