#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows: ");
    scanf("%d", &n);

    // Upper part 
    for(int i = 1; i <= n; i++) {
        // spaces
        for(int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // stars
        for(int j = 1; j <= 2*i - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    // Lower part 
    for(int i = 1; i <= n - 1; i++) {
        // spaces
        for(int j = 1; j <= i; j++) {
            printf(" ");
        }
        // stars
        for(int j = 1; j <= 2*(n-i) - 1; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    int n, rows, stars, spaces;

    printf("Enter n: ");
    scanf("%d", &n);

    rows = 2 * n - 1;

    for(int i = 1; i <= rows; i++) {

        if(i <= n) {
            stars = 2 * i - 1;
            spaces = n - i;
        } else {
            stars = 2 * (2*n - i) - 1;
            spaces = i - n;
        }

        // Print spaces
        for(int j = 1; j <= spaces; j++)
            printf(" ");

        // Print stars
        for(int j = 1; j <= stars; j++)
            printf("*");

        printf("\n");
    }

    return 0;
}