#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;

int n, k, target;
int buildTime[1000], cntPrev[1000];
vector<int> nextBuild[1000];

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &k);

        for (int i=0; i<n; i++)
        {
            cntPrev[i]=0;
            nextBuild[i].clear();
            scanf("%d", buildTime+i);
        }

        for (int i=0, a, b; i<k; i++)
        {
            scanf("%d%d", &a, &b);
            nextBuild[a-1].push_back(b-1);
            cntPrev[b-1]++;
        }

        scanf("%d", &target);

        priority_queue<pii> qu;
        for (int i=0; i<n; i++) if (cntPrev[i] == 0) qu.push({-buildTime[i], i});

        bool flag = true;
        while(flag)
        {
            pii tp = qu.top(); qu.pop();
            
            for (int nxt : nextBuild[tp.second])
                if (--cntPrev[nxt] == 0)
                {
                    if (nxt == target-1) 
                    {
                        printf("%d\n", buildTime[nxt]-tp.first);
                        flag = false;
                        break;
                    }
                    else qu.push({tp.first-buildTime[nxt], nxt});
                }
        }
    }
    return 0;
}
