#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 987654321

typedef pair<int, int> pii;

pii matrix[501];
int cntMatrix, dp[501][501], sum[501][501];

void run()
{
    for (int gap=1; gap<cntMatrix; gap++)
    {
        for (int i=1; i+gap<=cntMatrix; i++)
        {
            int j = i + gap;
            dp[i][j] = INF;
            for (int k=i; k<j; k++) dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+matrix[i].first*matrix[k].second*matrix[j].second);
        }
    }
}

void init()
{
    scanf("%d", &cntMatrix);
    for (int j=1; j<=cntMatrix; j++) 
    {
        scanf("%d%d", &matrix[j].first, &matrix[j].second);
        // dp[j][j] = 0;
    }
}

int main(int argc, char const *argv[])
{
    init();
    run();

    printf("%d\n", dp[1][cntMatrix]);
    return 0;
}
