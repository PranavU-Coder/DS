#include <stdio.h>
#include <stdlib.h>

int get(int arr[], int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    } else {
        printf("Index out of bounds.\n");
        return -1;
    }
}

int main()
{
    int i, n, index, *ptr;

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

    printf("Enter the index to get (0 to %d):\n", n - 1);
    scanf("%d", &index);

    int value = get(ptr, n, index);

    if (index >= 0 && index < n) {
        printf("Element at index %d is %d.\n", index, value);
    }

    free(ptr);
    return 0;
}
