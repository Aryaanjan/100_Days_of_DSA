#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);
    int queue[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }
    
    int stack[N];
    int top = -1;
    for (int i = 0; i < N; i++) {
        stack[++top] = queue[i];
    }
    
    for (int i = 0; i < N; i++) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}
