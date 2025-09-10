#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int n) {
    struct Node *t, *last;
    int value;

    printf("Enter element 1: ");
    scanf("%d", &value);
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = value;
    first->next = NULL;
    last = first;

    for (int i = 2; i <= n; i++) {
        printf("Enter element %d: ", i);
        scanf("%d", &value);
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = value;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p) {
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int Count(struct Node *p) {
    int count = 0;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

int Add(struct Node *p) {
    int sum = 0;
    while (p != NULL) {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

struct Node* Search(struct Node *p, int key) {
    while (p != NULL) {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

void Sort(struct Node *p) {
    struct Node *q;
    int temp;
    for (p = first; p != NULL; p = p->next) {
        for (q = p->next; q != NULL; q = q->next) {
            if (p->data > q->data) {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
}

void Reverse(struct Node *p) {
    struct Node *prev = NULL, *next = NULL;
    while (p != NULL) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
    }
    first = prev;
}

void Delete(int key) {
    struct Node *p = first;
    struct Node *q = NULL;

    while (p != NULL) {
        if (p->data == key) {
            if (q == NULL) {
                first = p->next;
            } else {
                q->next = p->next;
            }
            free(p);
            printf("Element %d deleted\n", key);
            return;
        }
        q = p;
        p = p->next;
    }
    printf("Element %d not found\n", key);
}

void main() {
    int n, choice, key;
    struct Node *found;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    create(n);

    do {
        printf("\nChoose an operation:\n");
        printf("1. Display all nodes\n");
        printf("2. Count all elements\n");
        printf("3. Add all elements\n");
        printf("4. Search for an element\n");
        printf("5. Sort the elements\n");
        printf("6. Reverse the linked list\n");
        printf("7. Delete an element\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

    switch (choice) {
    
        case 1:
            Display(first);
            break;
        case 2:
            printf("Total Elements: %d\n", Count(first));
            break;
        case 3:
            printf("Sum of Elements: %d\n", Add(first));
            break;
        case 4:
            printf("Enter element to search: ");
            scanf("%d", &key);
            found = Search(first, key);
            if (found)
                printf("Element %d found\n", key);
            else
                printf("Element %d not found\n", key);
            break;
        case 5:
            Sort(first);
            printf("List sorted\n");
            break;
        case 6:
            Reverse(first);
            printf("List reversed\n");
            break;
        case 7:
            printf("Enter element to delete: ");
            scanf("%d", &key);
            Delete(key);
            break;
        case 8:
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
    }
}
