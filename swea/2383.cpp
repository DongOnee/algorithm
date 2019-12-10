#include <cstdio>
#include <cstdlib>
#include <queue>
using namespace std;
#define MAXN 10
#define INF 987654321

typedef pair<int ,int> pii;
typedef pair<pii, int> ppiii;

int map[MAXN][MAXN], n;
ppiii infoExit[3];
pii ptrPerson[10];
bool useExit[10];
int cntPerson, ans;

void init()
{
    cntPerson = 0, ans = INF;
    int cntExit = 0;
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0, a; j<n; j++)
    {
        scanf("%d", &a);
        map[i][j] = a;
        if (a > 1) infoExit[++cntExit] = {{i, j}, a};
        else if (a == 1) ptrPerson[cntPerson++] = {i, j};
    }
}

priority_queue<pii> pq;
void simulation()
{
    // 최초 작업
    for (int i=0; i<cntPerson; i++)
    {
        int idxExit = useExit[i]+1;
        int tm = abs(infoExit[idxExit].first.first-ptrPerson[i].first);
        tm += abs(infoExit[idxExit].first.second-ptrPerson[i].second);
        pq.push({-tm, -idxExit});
    }
    int useCntExit[3] = {0, 0, 0}, waitExit[3] = {0, 0, 0}, curTm=0;
    while (!pq.empty())
    {
        int tm = -pq.top().first, st = pq.top().second;
        if (curTm < tm) 
        {
            curTm = tm;
            continue;
        }
        pq.pop();
        if (st > 0) // 계단을 다 내려갔다.
        {
            useCntExit[st]--; // 계단 내려가.
            // 머기 하고 있는 사람 있으면?
            if (waitExit[st] > 0)
            {
                // 이사람도 내려가야지
                pq.push({-curTm-infoExit[st].second, st});
                useCntExit[st]++;   // 내려가는사람 추가
                waitExit[st]--;     // 머기 끝
            }
        }
        else
        {
            st *= -1;
            if (useCntExit[st] == 3) waitExit[st]++;    // 3명이 계단 이용중이면 머기
            else // 아니면 그냥 내려가.
            {
                useCntExit[st]++;
                pq.push({-curTm-infoExit[st].second, st});
            }
        }
    }
    ans = ans<curTm?ans:curTm;
}

void dfs(int cnt)
{
    if (cnt == cntPerson)
    {
        simulation();
    }
    else
    {
        dfs(cnt+1);
        useExit[cnt] = true;
        dfs(cnt+1);
        useExit[cnt] = false;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("2383_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case=1; test_case<=t; test_case++)
    {
        init();
        dfs(0);

        printf("#%d %d\n", test_case, ans+1);
    }
    return 0;
}
