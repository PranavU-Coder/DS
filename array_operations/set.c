#include <stdio.h>
#include <stdlib.h>

void set(int arr[], int size, int index, int newValue) {
    if (index >= 0 && index < size) {
        arr[index] = newValue;
        printf("Element at index %d updated to %d.\n", index, newValue);
    } else {
        printf("Index out of bounds.\n");
    }
}

int main()
{
    int i, n, index, newValue, *ptr;

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

    printf("Enter the index to update (0 to %d):\n", n - 1);
    scanf("%d", &index);

    printf("Enter the new value to set at index %d:\n", index);
    scanf("%d", &newValue);

    set(ptr, n, index, newValue);

    printf("Updated Array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
