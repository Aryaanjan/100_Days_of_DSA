#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

int output[MAX];   // to store pop outputs
int outIndex = 0;

void push(int value) {
    if (top != MAX - 1) {
        stack[++top] = value;
    }
}

void pop() {
    if (top == -1) {
        output[outIndex++] = -9999;   // special value for underflow
    } else {
        output[outIndex++] = stack[top--];
    }
}

void display() {
    if (top == -1) {
        output[outIndex++] = -9999;   // special value
    } else {
        // store display elements temporarily
        for (int i = top; i >= 0; i--) {
            output[outIndex++] = stack[i];
        }
        output[outIndex++] = -1111;   // separator marker
    }
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if (type == 2) {
            pop();
        }
        else if (type == 3) {
            display();
        }
    }

    // Now print everything AFTER input
    for (int i = 0; i < outIndex; i++) {
        if (output[i] == -9999) {
            printf("Stack Underflow\n");
        }
        else if (output[i] == -1111) {
            printf("\n");
        }
        else {
            printf("%d ", output[i]);
        }
    }

    return 0;
}
