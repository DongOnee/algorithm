/**
 * 19.4.3.
 */
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
#define MAX_COST 10001
using namespace std;

int n, m, cost[1001][1001];
bool connected[1001];
int connectedCnt;

pair<int, int> min_;
vector<int> vt;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) cost[i][j] = MAX_COST;
    int minCost = MAX_COST;
    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        cost[a][b] = c;
        cost[b][a] = c;
        if (c<minCost)
        {
            min_= {a, b};
            minCost = c;
        }
    }

    connectedCnt = 2;
    vt.push_back(min_.first);
    vt.push_back(min_.second);
    connected[min_.first]=true;
    connected[min_.second]=true;
    int sol = minCost;
    cost[min_.first][min_.second] = MAX_COST;
    cost[min_.second][min_.first] = MAX_COST;

    while (connectedCnt<n)
    {
        vector<int> tmp(vt);
        minCost = MAX_COST;
        int newFace = 0;
        for (auto x : tmp)
            for (int i=1; i<=n; i++)
                if (cost[x][i]<minCost && connected[i]==false)
                {
                    minCost = cost[x][i];
                    min_={x, i};
                    newFace = i;
                }
        sol += minCost;
        for (auto x : tmp)
        {
            cost[x][newFace] = MAX_COST;
            cost[newFace][x] = MAX_COST;
        }
        vt.push_back(newFace);
        connected[newFace] = true;
        connectedCnt++;
    }

    printf("%d\n", sol);

    return 0;
}
