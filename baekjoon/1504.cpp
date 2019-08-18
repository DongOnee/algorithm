/**
 * 2019.10.25. 22:27 ~ 2019.10.26. 11:05
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, e, map[801][801], point[2];
vector<int> linked[801];
int dp[4][801]; // dp[a][b] : a condition 에 있고, b번 정점에 서 출발하여 n 번 정점에 가는 경로의 길이
// a = 0 : 아무것도 안지남, a = 1 : point[0] 만 지남, a = 2 : point[1] 만 지남, a = 3 : 둘다 지남.
queue<pair<int, int>> qu;
 
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &e);
    for (int i=0, a, b, c; i<e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
        map[b][a] = c;
        linked[a].push_back(b);
        linked[b].push_back(a);
    }
    scanf("%d %d", point, point+1);

    int first_condition;
    if (n == point[0]) first_condition = 1;
    else if (n == point[1]) first_condition = 2;
    else first_condition = 0;

    qu.push({first_condition, n});
    while (!qu.empty())
    {
        int cond = qu.front().first;
        int start = qu.front().second;
        qu.pop();
        for (int new_start : linked[start])
        {
            int new_cond = cond;
            if (cond == 0)
            {
                if (new_start == point[0]) new_cond = 1;
                else if (new_start == point[1]) new_cond = 2;
            }
            else if (cond == 1 && new_start == point[1]) new_cond = 3;
            else if (cond == 2 && new_start == point[0]) new_cond = 3;

            if (dp[new_cond][new_start] == 0 || dp[new_cond][new_start] > dp[cond][start] + map[new_start][start])
            {
                dp[new_cond][new_start] = dp[cond][start] + map[new_start][start];
                qu.push({new_cond, new_start});
            }
        }
    }
    
    printf("%d\n", (dp[3][1] == 0 ? -1: dp[3][1]));

    return 0;
}
