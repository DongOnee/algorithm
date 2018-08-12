#include <stdio.h>

typedef struct counts
{
    int count_2;
    int count_5;
} counts;

counts d[501];

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);

    counts sol;
    sol.count_2 = 0;
    sol.count_5 = 0;

    for (int i=1; i<=n; i++)
    {
        if(i%2 == 0)
        {
            d[i] = d[i/2];
            d[i].count_2++;
        }
        else if(i%5 == 0)
        {
            d[i] = d[i/5];
            d[i].count_5++;
        }
        sol.count_2 += d[i].count_2;
        sol.count_5 += d[i].count_5;
    }

    // for(int i =0; i<=n; i++) printf("%d\t%d\n", d[i].count_2, d[i].count_5);
    // printf("---sol---\n"
    //         "%d\t%d\n", sol.count_2, sol.count_5);

    if (sol.count_2 < sol.count_5) printf("%d\n", sol.count_2);
    else printf("%d\n", sol.count_5);

    return 0;
}
