#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", (int)((n*n*n*0.166666667)-n*n-1+(1.83333333*n)));
}