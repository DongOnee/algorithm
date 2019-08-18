#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    while(T--){
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        printf("%d\n", A+B);
    }
    
    return 0;
}