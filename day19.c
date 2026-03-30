#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    qsort(arr, n, sizeof(int), cmp);

    int l = 0, r = n - 1;
    int min = INT_MAX, a, b;

    while(l < r) {
        int sum = arr[l] + arr[r];

        if(abs(sum) < abs(min)) {
            min = sum;
            a = arr[l];
            b = arr[r];
        }

        if(sum < 0) l++;
        else r--;
    }

    printf("%d %d", a, b);

    return 0;
}
