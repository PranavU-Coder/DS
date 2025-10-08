#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void createList(int n) {
    int data;
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        struct Node* newNode = createNode(data);
        if (head == NULL) {
            head = newNode;
        } else {
            struct Node* temp = head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    printf("List created with %d nodes.\n", n);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("List contents: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int getLength() {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtPosition(int pos, int data) {
    int len = getLength();
    if (pos < 1 || pos > len + 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* newNode = createNode(data);

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1; i++)
            temp = temp->next;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL)
            temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("Inserted %d at position %d.\n", data, pos);
}

void deleteAtPosition(int pos) {
    int len = getLength();
    if (pos < 1 || pos > len) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* temp = head;

    if (pos == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("Deleted %d from position 1.\n", temp->data);
        free(temp);
    } else {
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        if (temp->next != NULL)
            temp->next->prev = temp->prev;
        printf("Deleted %d from position %d.\n", temp->data, pos);
        free(temp);
    }
}

void reverseList() {
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        head = temp->prev;

    printf("List reversed.\n");
}

int main() {
    int choice, n, data, pos;

    while (1) {
        printf("\nSelect Operations:\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Calculate Length\n");
        printf("4. Insert at Position\n");
        printf("5. Delete at Position\n");
        printf("6. Reverse List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes to create: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                printf("Length of list: %d\n", getLength());
                break;
            case 4:
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(pos, data);
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 6:
                reverseList();
                break;
            case 7:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
