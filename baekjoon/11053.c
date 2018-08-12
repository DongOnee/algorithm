#include <stdio.h>

int main(int argc, char const *argv[])
{
    // data
    int n;
    int a[2001];

    // input data
    scanf("%d", &n);
    for (int i = 0; i<n; i++) 
    {
        scanf("%d", &a[i]);
    }

    // algorithm
    int sol = 0;
    int d[n];

    for (int i = n-1; 0<=i; i--)
    {
        int tmp = 1;
        for (int j = i+1; j<n; j++)
        {
            if (a[i] < a[j] && tmp <= d[j])
            {
                tmp = d[j]+1;
            }
        }
        d[i] = tmp;
        if (sol < d[i])
        {
            sol = d[i];
        }
    }

    printf("%d\n", sol);
    return 0;
}
