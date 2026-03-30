#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    if (data == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

typedef struct Queue {
    Node** arr;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int n) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(n * sizeof(Node*));
    q->front = 0;
    q->rear = 0;
    q->size = n;
    return q;
}

void enqueue(Queue* q, Node* node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue* q) {
    return q->arr[q->front++];
}

int isEmpty(Queue* q) {
    return q->front == q->rear;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    
    if (N == 0) return 0;
    
    Node* root = createNode(arr[0]);
    Queue* q = createQueue(N);
    enqueue(q, root);
    int i = 1;
    
    while (i < N) {
        Node* curr = dequeue(q);
        if (i < N) {
            curr->left = createNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
        }
        if (i < N) {
            curr->right = createNode(arr[i++]);
            if (curr->right) enqueue(q, curr->right);
        }
    }
    
    inorder(root);
    printf("\n");
    return 0;
}
