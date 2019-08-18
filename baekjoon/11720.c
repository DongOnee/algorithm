#include <stdio.h>

int main(void) {
    int T;
    scanf("%d", &T);
    int res=0;
    int tmp;
    while(T--) {
        scanf("%1d", &tmp);
        res += tmp;
    }
    printf("%d\n", res);

    return 0;
}