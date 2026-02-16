#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int i = 0, j = strlen(s) - 1;
    int palindrome = 1;

    while (i < j) {
        if (s[i] != s[j]) {
            palindrome = 0;
            break;
        }
        i++;
        j--;
    }

    if (palindrome)
        printf("YES");
    else
        printf("NO");
