#include <stdio.h>

int main(void) {
    int N;
    scanf("%d", &N);
    if(N==1) {
        printf("*\n");
        return 0;
    }
    for(int i=0; i<N-1; i++) printf(" ");
    printf("*\n");
    for(int i=1; i<N-1; i++) {
        for(int j=0; j<N-i-1; j++) printf(" ");
        printf("*");
        for(int k=0; k<i+i-1; k++) printf(" ");
        printf("*");
        printf("\n");
    }
    for(int i=1; i<N+N; i++) printf("*");
    printf("\n");
    return 0;
}