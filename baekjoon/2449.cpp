/**
 * 19.1.31.
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int N, K;
int map[200];
int dp[200][200];
/**
 * dp[A][B] : map[A] ~ map[B] 까지 같은 불빛일때 전구의 색을 바꾼 횟수의 최소값
 * map[A] 의 색으로 통일됬을때..? << 가정
 */

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);
    for (int i=0; i<N; i++)
    {
        scanf("%d", map+i);
        dp[i][i]=0;
        for (int j=i-1; 0<=j; j--)
        {
            dp[j][i] = 1e9;
            for (int k=j; k<i; k++)
            {
                dp[j][i] = min(dp[j][i], dp[j][k] + (map[j] != map[k+1]) + dp[k+1][i]);
            }
        }
    }

    printf("%d\n", dp[0][N-1]);
    return 0;
}