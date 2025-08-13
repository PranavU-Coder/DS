#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    int *st;
};

int isFull(struct stack st) {
    if (st.top == st.size - 1) {
        return 1;
    } else
        return 0;
}

int isEmpty(struct stack st) {
    if (st.top == -1) {
        return 1;
    } else
        return 0;
}

void push(struct stack *st, int object) {
    if (st->top == st->size - 1)
        printf("stack overflow");
    else {
        st->top++;
        st->st[st->top] = object;
    }
}

int Pop(struct stack *st) {
    int object = -1;
    if (st->top == -1)
        printf("stack underflow");
    else {
        object = st->st[st->top];
        st->top--;
    }
    return object;
}

int Peek(struct stack st, int pos) {
    int object = -1;
    if (st.top - pos + 1 < 0)
        printf("\nOut Of Bounds");
    else
        object = st.st[st.top - pos + 1];
    return object;
}

int StackTop(struct stack st) {
    if (st.top == -1)
        return -1;
    else
        return st.st[st.top];
}

int main(void) {
    struct stack st;
    int ch, i;

    printf("Enter size of stack: ");
    scanf("%d", &st.size);
    st.top = -1;
    st.st = (int *)malloc(st.size * sizeof(int));

    if (st.st == NULL) {
    printf("Memory allocation failed\n");
    return 1;
}

    do {
        printf("\nChoices : ");
        printf("\n 1 : Push \n 2 : Pop \n 3 : Display \n 4 : Peek \n 5 : Top Element \n 6 : Exit \n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (!isFull(st)) {
                    printf("Enter a value: ");
                    scanf("%d", &i);
                    push(&st, i);
                } else {
                    printf("Stack overflow");
                }
                break;

            case 2:
                if (!isEmpty(st)) {
                    int del = Pop(&st);
                    printf("Element popped is: %d", del);
                } else {
                    printf("Empty Stack");
                }
                break;

            case 3:
                printf("The content of the stack is: ");
                for (int j = st.top; j >= 0; j--) {
                    printf("%d ", st.st[j]);
                }
                printf("\n");
                break;

            case 4:
                printf("Enter index to be checked: ");
                scanf("%d", &i);
                int peek = Peek(st, i);
                if (peek != -1)
                    printf("Element at position %d is: %d\n", i, peek);
                break;


            case 5:
                printf("Current top element of stack :");
                int element = StackTop(st);
                printf("%d",element);
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (ch != 6);

    free(st.st);
    return 0;
}
