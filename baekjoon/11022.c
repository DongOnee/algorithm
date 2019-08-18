#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    int i=1;
    while(i<=T){
        int A, B;
        scanf("%d", &A);
        scanf("%d", &B);
        printf("Case #%d: %d + %d = %d\n", i++,A, B, A+B);
    }
    
    return 0;
}