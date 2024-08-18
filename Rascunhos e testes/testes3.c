// Estudando sobre linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
}node;

void insertStart(node **list, int value) {
    node *new = (node*) malloc(sizeof(node));

    if (new != NULL) {
        new->value = value;
        new->next = *list;
        *list = new;
    }
    else
        printf("Memoria insuficiente!\n");
}

void insertEnd(node **list, int value) {
    node *new = (node*) malloc(sizeof(node));

    if (new != NULL) {
        new->value = value;
        new->next = NULL;
        // Se for o primeiro nó
        if (*list == NULL)
            *list = new;
        else {
            node *temp = *list;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new;
        }
    }
    else
        printf("Memoria insuficiente");
}

// void insertFree(node **lista, int value, int position) {
//     if (position == 1)
//         insertStart(lista, value);
//     node *new = (node*) malloc(sizeof(node));

//     if (new != NULL) {

//     }
//     else
//         printf("Memoria insuficiente");

// }

void printList(node *list) {
    while (list) {
        printf("%d ", list->value);
        list = list->next;
    }
}

int main() {

    node *head = NULL;
    insertStart(&head, 10);
    insertStart(&head, 20);
    insertEnd(&head, 30);
    printList(head);


    return 0;
}