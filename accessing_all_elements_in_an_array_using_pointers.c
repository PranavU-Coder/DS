#include <stdio.h>

int main(void) {
    int num;
    printf("Enter number of elements to be inserted in an array: ");
    scanf("%d", &num);
    
    int arr[num]; // Declare an array of size 'num'
    int *ptr = arr; // Point 'ptr' to the array's first element

    printf("Enter the respective elements: ");
    for(int i = 0; i < num; i++) {
        scanf("%d", ptr + i);
    }

    printf("The elements are: ");
    for(int i = 0; i < num; i++) {
        printf("%d ", *(ptr + i)); 
    }
    
    printf("\n");
    return 0;
}
