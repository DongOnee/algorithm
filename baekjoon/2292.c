#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int i = 1;
    int a = 1;
    while(a<n)
    {
        a = a + i*6;
        i++;
    }
    printf("%d\n", i);
    /* code */
    return 0;
}
