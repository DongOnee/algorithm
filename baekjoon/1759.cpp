#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<char, bool>> vt;
vector<char> vt2;
int cnts[2];

void dfs(int s, int cnt)
{
    if (cnt == n)
    {
        // printf("%d %d\n", cnts[0], cnts[1]);
        if (cnts[0] < 2 || cnts[1] < 1) return;
        for (int x : vt2) printf("%c", x);
        printf("\n");
    }
    else
    {
        for (int i=s; i<m; i++)
        {
            vt2.push_back(vt[i].first);
            cnts[vt[i].second]++;
            dfs(i+1, cnt+1);
            cnts[vt[i].second]--;
            vt2.pop_back();
        }
    }
    
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0, b; i<m;)
    {
        char a;
        scanf("%c", &a);
        if (a == ' ' || a == '\n') continue;
        if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u') b = true;
        else b = false;
        vt.push_back({a, b});
        i++;
    }

    sort(vt.begin(), vt.end());

    dfs(0, 0);

    return 0;
}
