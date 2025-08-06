#include <stdio.h>
#include <stdlib.h>

void Display(int arr[], int size) {
    printf("The elements in the array are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
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
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &ptr[i]);
    }

    Display(ptr, n);

    free(ptr);
    return 0;
}
