#include <stdio.h>
#include <stdlib.h>

void Reverse(int arr[], int size) {
    printf("The elements in reverse order are:\n");
    for (int i = size - 1; i >= 0; i--) {
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
        printf("Enter element %d: ", i + 1);
        scanf("%d", &ptr[i]);
    }

    Reverse(ptr, n);

    free(ptr);
    return 0;
}
