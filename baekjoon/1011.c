#include <stdio.h>

int main(int argc, char const *argv[]) {
    int t;
    scanf("%d", &t);
    for (int test_case = 0; test_case<t; test_case++)
    {
        int x,y ;
        scanf("%d %d", &x, &y);

        long long distance = y - x;

        long long i = 0;
        long long pawi;
        while (++i)
        {
            pawi = i * i;
            long long pre_end = pawi -i;
            long long end = pawi + i;
            if (pre_end < distance && distance <= end) break;
        }
        if(distance <= pawi) printf("%lld\n", 2*i-1);
        else printf("%lld\n", 2*i);

    }
    return 0;
}
