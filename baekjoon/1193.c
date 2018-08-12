#include <stdio.h>

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    int i = 1;
    int a = 1;
    while(a<n)
    {
        i++;
        a = a + i;
    }
    int diff = a - n;
    if (i%2 == 0)
    {
        // 1/i start
        printf("%d/%d\n", i-diff, 1+diff);
    }
    else
    {
        // i/1 start
        printf("%d/%d\n", 1+diff, i-diff);
    }
    /* code */
    return 0;
}
