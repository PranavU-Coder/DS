#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    int *st;
};

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


int isMatching(int open, int close) {
    return (open == 40 && close == 41) || (open == 123 && close == 125) || (open == 91 && close == 93);
}

int isBalance(char *exp) {
    struct stack st;
    int len = strlen(exp);
    st.size = len;
    st.top = -1;
    st.st = (int *)malloc(st.size * sizeof(int));

    if (st.st == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    for (int i = 0; exp[i] != '\0'; i++) {
        int ch = (int)exp[i];
        if (ch == 40 || ch == 123 || ch == 91) {
            push(&st, ch);
        } else if (ch == 41 || ch == 125 || ch == 93) {
            if (isEmpty(st)) {
                free(st.st);
                return 0;
            }
            int popped = Pop(&st);
            if (!isMatching(popped, ch)) {
                free(st.st);
                return 0;
            }
        }
    }

    int balanced = isEmpty(st);
    free(st.st);
    return balanced;
}

int main() {
    char expr[1000];

    printf("Enter an expression: ");
    fgets(expr, sizeof(expr), stdin);

    int len = strlen(expr);
    if (len > 0 && expr[len - 1] == '\n') {
        expr[len - 1] = '\0';
    }

    if (isBalance(expr))
        printf("The Expression is balanced.\n");
    else
        printf("The Expression is imbalanced.\n");

    return 0;
}
