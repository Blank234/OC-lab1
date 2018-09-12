#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

void add(Node **head, int data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

void createSpis(Node **head, int *arr, size_t size) {
    size_t i = size - 1;
    if (arr == NULL || size == 0) {
        return;
    }
    do {
        add(head, arr[i]);
    } while(i--!=0);
}

void print(const Node *head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}


Node* getN(Node* head, int n) {
    int counter = 0;
    while (counter < n && head) {
        head = head->next;
        counter++;
    }
    return head;
}

int removeN(Node **head, int n) {
       Node *prev = getN(*head, n-1);
        Node *elm  = prev->next;
        int val = elm->value;

        prev->next = elm->next;
        free(elm);
        return val;

}

int delem(Node **head) {
    Node* prev = NULL;
    int val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}

void remov(Node **head) {
    while ((*head)->next) {
        delem(head);
        *head = (*head)->next;
    }
    free(*head);
    *head=NULL;
}

int main()
{
    Node* head = NULL;
    int mass[] = {1,2,3,4,5,6,7,8,9,10};
    int varik;
    createSpis(&head, mass, 10);

    print(head);

    printf("\n Vibor elementa\n\n");
    scanf("%d", &varik);
    removeN(&head, varik-1);

    print(head);
    remov(&head);
    print(head);

    getch();
    return 0;
}
