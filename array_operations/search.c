#include <stdio.h>
#include <stdlib.h>

int Search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int i, n, target, *ptr;

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

    printf("Enter the element to search:\n");
    scanf("%d", &target);

    int pos = Search(ptr, n, target);

    if (pos != -1) {
        printf("Element %d found at position %d.\n", target, pos);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    free(ptr);
    return 0;
}
