#include <stdio.h>

int main(int argc, char const *argv[])
{
    // init data
    unsigned long long p[101];
    p[0] = 0;
    p[1] = 1;
    p[2] = 1;
    p[3] = 1;
    p[4] = 2;
    p[5] = 2;
    int top = 6;

    // input data
    int T;
    scanf("%d", &T);

    // algorithm
    for (int test_case=0; test_case<T; test_case++) 
    {
        int n;
        scanf("%d", &n);

        for (; top<=n; top++)
        {
            p[top] = p[top-1] + p[top -5];
        }

        printf("%llu\n", p[n]);
    }
    
    return 0;
}
