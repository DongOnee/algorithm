#include <cstdio>

int n, a[100], m;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i<n; i++) scanf("%d", a+i);

    int sum = 0, answer = 0;;
    for (int i=0; i<n; i++)
    {
        sum += a[i];
        for (int j=i+1; j<n && sum <= m; j++)
        {
            sum += a[j];
            for (int k=j+1; k<n && sum <= m; k++)
            {
                if (sum + a[k] <= m) answer = answer>(sum+a[k])?answer:(sum+a[k]);
            }
            sum -= a[j];
        }
        sum -= a[i];
    }

    printf("%d\n", answer);

    return 0;
}
