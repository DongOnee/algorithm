#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    int a;
    scanf("%d", &a);
    int min =a;
    int max =a;
    T--;
    while(T--) {
        scanf("%d", &a);
        if(a<min) min =a;
        if(max<a) max = a;
    }

    printf("%d %d\n", min, max);
    return 0;
}