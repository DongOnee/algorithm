#include <cstdio>
#include <vector>
using namespace std;

int g, p, par[100001];
vector<int> cmds;

int findFunc(int input)
{
    if (input == par[input]) return input;
    return par[input] = findFunc(par[input]);
}

bool unionFunc(int input)
{
    int x = findFunc(input);
    if (x == 0) return true;
    par[x] = par[x-1];
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &g);
    for (int i=1; i<=g; i++) par[i] = i;
    scanf("%d", &p);
    while (p--)
    {
        int tmp; scanf("%d", &tmp);
        cmds.push_back(tmp);
    }

    int ans = 0;
    for (int x : cmds)
    {
        if (unionFunc(x)) break;
        ans ++;
    }

    printf("%d\n", ans);

    return 0;
}
