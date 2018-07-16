#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    double top=0;
    int d[n];
    for(int i=0; i<n; i++)
    {
        int tmp;
        scanf("%d", &tmp);
        if (top < tmp) top = tmp;
        d[i] = tmp;
    }
    double sol=0;
    for (int i=0; i<n; i++)
    {
        sol += d[i]/top*100;
    }
    printf("%.2f\n", sol/n);
    return 0;
}
