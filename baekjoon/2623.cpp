#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int n, k;
vector<int> cntPrev, ans;
vector<vector<int>> connect;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    connect.resize(n);
    cntPrev.resize(n);
    for (int i=0, cntInput; i<k; i++)
    {
        scanf("%d", &cntInput);
        int x, y;
        for (int j=0; j<cntInput; j++)
        {
            if (!j) scanf("%d", &x);
            else
            {
                scanf("%d", &y);
                connect[x-1].push_back(y-1);
                cntPrev[y-1]++;
                x = y;
            }
        }
    }

    priority_queue<int> pq;
    for (int i=0; i<n; i++) if (cntPrev[i] == 0) pq.push(i);

    while(!pq.empty())
    {
        int tp = pq.top(); pq.pop();
        ans.push_back(tp+1);
        for (int nxt : connect[tp])
        {
            if (--cntPrev[nxt] == 0) pq.push(nxt);
        }
    }

    if (ans.size() < n) printf("0\n");
    else for (int x : ans) printf("%d\n", x);



    return 0;
}
