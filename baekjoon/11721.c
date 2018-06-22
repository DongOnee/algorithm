#include <stdio.h>

int main(void) {
    char in[100];
    while (scanf("%10s", in)==1) printf("%s\n", in);

    return 0;
}