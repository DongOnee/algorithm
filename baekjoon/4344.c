#include <stdio.h>

int main(int argc, char const *argv[])
{
    int t;
    scanf("%d", &t);

    for (int test_case=0; test_case <t; test_case++)
    {
        int n;
        scanf("%d", &n);

        int d[n];
        double avg=0;
        for (int j=0; j<n; j++)
        {
            scanf("%d", &d[j]);
            avg += d[j];
        }
        avg /= n;
        int count=0;
        for (int j=0; j<n; j++) if (avg<d[j]) count++;

        printf("%.3f%%\n", count*100.0/n);
    }
    return 0;
}
