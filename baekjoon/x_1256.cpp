/**
 * 19.3.29.
 */
#include <cstdio>

int a, z, k;
long long dp[101][101]; // dp[i][j] : 'a' 가 i 개 'z' 가 j 개 있을때 조합의 수

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &a, &z, &k);
    for (int i=1; i<=a; i++) dp[i][0] = 1;
    for (int j=1; j<=z; j++) dp[0][j] = 1;

    for (int i=1; i<=a; i++) for (int j=1; j<=z; j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    if (dp[a][z] < k) printf("-1\n");
    else
    {
        while (k)
        {
            // printf("\n------a: %d\tz:%d\tk: %d------", a, z, k);
            if (a*z==0)
            {
                while (a--)printf("a");
                while (z--)printf("z");
                k=0;
            }
            else if (dp[a-1][z] < k)
            {
                k -= dp[a-1][z];
                z--;
                printf("z");
            }
            else
            {
                a--;
                printf("a");
            }
        }
    }

    return 0;
}


/*
0 1  1  1  1 1 1 1 1 1 1 1 1 1 1 1 
1 2  3  4  5 6 7 8 9 
1 3  6 10 15
1 4 10 20 35
zzzzaaa-35
zzzazaa-34
zzzaaza-33
zzzaaaz-32
zzazzaa-31
zzazaza-30

zzaza
k = 29    a=3     z=4
dp[a-1][z] = dp[2][4] = 15
if (dp[a-1][z] < k)
{
    k -= dp[a-1][z];
    z--;
    printf("z");
}
k = 14    a=3     z=3
dp[a-1][z] = dp[2][3] = 10
if (dp[a-1][z] < k)
{
    k -= dp[a-1][z];
    z--;
    printf("z");
}
k=4     a=3     z=2
dp[a-1][z] = dp[2][2] = 6
if (dp[a-1][z] > k)
{
    a--;
    printf("a")
}
k=4     a=2     z=2
dp[a-1][z] = dp[1][2] = 3
if (dp[a-1][z] < k)
{
    k -= dp[a-1][z];
    z--;
    printf("z");
}
k=1     a=2     z=1
dp[a-1][z] = dp[1][1] = 2
if (dp[a-1][z] > k)
{
    a--;
    printf("a")
}
k=1     a=1     z=1
dp[a-1][z] = dp[0][1] = 1;
if (dp[a-1][z] =< k)
{
    k -= dp[a-1][z];
    z--;
    printf("z");
}
k=0     a=1     z=0
dp[a-1][z] = dp[0][0] = 0;
if (k==0)
{

}

k=3     a=2     z=2
dp[a][z-1] = dp[2][1] = 3
if (dp[a][z-1] == 3)
{
    for (z--) printf("z");
    for (a--) printf("a");
}






5
aaaazzz -1 5-1 4
aaazazz -3 4-3 1
aazaazz -6 

1
1
1
1
1
1
1
1
1
1
dp[i][j] = dp[i-1][j] + dp[i][j-1];

*/