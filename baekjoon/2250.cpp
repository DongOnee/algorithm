#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n;
vector<pii> childs;
vector<int> cntLefts[10001];
vector<bool> isChild;

int col;
void dfs(int idx, int lv)
{
    if (childs[idx].first != -1) dfs(childs[idx].first, lv+1);
    cntLefts[lv].push_back(col++);
    if (childs[idx].second != -1) dfs(childs[idx].second, lv+1);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    childs.resize(n+1);
    isChild.resize(n+1);
    int idxRoot = n*(n+1)/2;
    for (int i=0, a, b, c; i<n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        childs[a] = {b, c};
        if (b!=-1) idxRoot -= b;
        if (c!=-1) idxRoot -= c;
    }

    dfs(idxRoot, 1);

    int ansLv = 1, ansWidth = 1;
    for (int i=1; cntLefts[i].size() > 0; i++)
    {
        int wid = cntLefts[i].back() - cntLefts[i][0] +1;
        if (ansWidth < wid)
        {
            ansWidth = wid;
            ansLv = i;
        }
    }

    printf("%d %d\n", ansLv, ansWidth);
    return 0;
}
