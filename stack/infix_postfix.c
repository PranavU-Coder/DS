#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack {
    int size;
    int top;
    char *st;
};

int isFull(struct stack st) {
    return st.top == st.size - 1;
}

int isEmpty(struct stack st) {
    return st.top == -1;
}

void push(struct stack *st, char object) {
    if (isFull(*st))
        printf("Stack overflow\n");
    else
        st->st[++st->top] = object;
}

char pop(struct stack *st) {
    if (isEmpty(*st)) {
        printf("Stack underflow\n");
        return '\0';
    } else
        return st->st[st->top--];
}

char peek(struct stack st) {
    if (!isEmpty(st))
        return st.st[st.top];
    return '\0';
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*':
        case '/': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

int isVariable(char ch) {
    return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

void infixToPostfix(char *infix, char *postfix) {
    struct stack st;
    st.size = strlen(infix);
    st.top = -1;
    st.st = (char *)malloc(st.size * sizeof(char));

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isVariable(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(&st, ch);
        } else if (ch == ')') {
            while (!isEmpty(st) && peek(st) != '(')
                postfix[j++] = pop(&st);
            pop(&st); 
        } else if (isOperator(ch)) {
            while (!isEmpty(st) && precedence(peek(st)) >= precedence(ch))
                postfix[j++] = pop(&st);
            push(&st, ch);
        }
        i++;
    }

    while (!isEmpty(st))
        postfix[j++] = pop(&st);

    postfix[j] = '\0';
    free(st.st);
}

int main() {
    char infix[100], postfix[100];
    printf("Enter an expression: ");
    fgets(infix, sizeof(infix), stdin);

    infixToPostfix(infix, postfix);
    printf("Postfix equivalent of the expression is: %s\n", postfix);

    return 0;
}
