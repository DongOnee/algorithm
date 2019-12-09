#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXCOLOR 18

int n;
vector<vector<int>> connected;
int dp[100001][MAXCOLOR];

int runSubTree(int idx, int color, int idxP)
{
    if (dp[idx][color] != 0) return dp[idx][color];
    int ret = color+1;
    for (int nxt : connected[idx])
    {
        if (nxt == idxP) continue;
        int nxtSubTreeSum = 987654321;
        for (int nxtColor=0; nxtColor<MAXCOLOR; nxtColor++)
        {
            if (nxtColor == color) continue;
            nxtSubTreeSum = min(nxtSubTreeSum, runSubTree(nxt, nxtColor, idx));
        }
        ret += nxtSubTreeSum;
    }
    return dp[idx][color] = ret;
}

void init()
{
    scanf("%d", &n);
    connected.resize(n);
    for (int i=1, a, b; i<n; i++)
    {
        scanf("%d%d", &a, &b);
        connected[a-1].push_back(b-1);
        connected[b-1].push_back(a-1);
    }
}

int main(int argc, char const *argv[])
{
    init();

    int answer = 987654321;
    for (int i=0; i<MAXCOLOR; i++) answer = min(answer, runSubTree(0, i, -1));
    printf("%d\n", answer);

    return 0;
}
