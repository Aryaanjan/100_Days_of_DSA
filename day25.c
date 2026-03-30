#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, key, value;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    scanf("%d", &n);

    if (n <= 0) {
        printf("0\n");
        return 0;
    }

    scanf("%d", &value);
    head = createNode(value);
    temp = head;

    for (int i = 1; i < n; i++) {
        scanf("%d", &value);
        newNode = createNode(value);
        temp->next = newNode;
        temp = newNode;
    }
    scanf("%d", &key);
    int count = 0;
    temp = head;
    while (temp != NULL) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }
    printf("%d\n", count);

    return 0;
}
