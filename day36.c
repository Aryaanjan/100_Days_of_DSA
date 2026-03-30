#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);

    int q[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &q[i]);

    scanf("%d", &m);

    int front = 0;

    // simulate dequeue operations by moving front
    front = (front + m) % n;

    // print circular order
    for(int i = 0; i < n; i++) {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}
