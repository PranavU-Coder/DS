#include <stdio.h>
#include <string.h>

int main(void) {
    int num;
    int MAX_NAME_LENGTH = 100;
    printf("Enter number of names: ");
    scanf("%d", &num);
    getchar();
    char c[num][MAX_NAME_LENGTH];

    for (int i = 0; i < num; i++) {
        printf("Enter name %d: ", i + 1);
        fgets(c[i], MAX_NAME_LENGTH, stdin);

        c[i][strcspn(c[i], "\n")] = 0;
    }

    printf("The names are:\n");
    for (int i = 0; i < num; i++) {
        printf("%d : %s \n",i+1,c[i]);
    }

    return 0;
}
