#include <stdio.h>

int main(int argc, char const *argv[]) {
    int t; scanf("%d", &t);
    for (int test_case = 0; test_case<t; test_case++)
    {
        int h, w, n;
        scanf("%d %d %d", &h, &w, &n);
        printf("%d%02d\n", (n-1)%h+1, (n-1)/h+1);
    }
    return 0;
}
