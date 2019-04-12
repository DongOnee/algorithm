/**
 * 19.4.9. 21:54~22:23
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, map[21][21], sol;
bool team[21];

void dfs(int index, int cnt)
{
    if (cnt*2 == n)
    {
        int sum = 0;
        for (int i=0; i<n; i++)
        {
            int sum_ = 0;
            for (int j=0; j<n; j++)
            {
                if (team[i] == team[j]) 
                sum_ += map[i][j];
            }
            if (team[i]) sum+=sum_;
            else sum-=sum_;
        }
        sol = min(sol, abs(sum));
        return;
    }
    for (int i=index+1; i<n; i++)
    {
        team[i] = true;
        dfs(i, cnt+1);
        team[i] = false;
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d", map[i]+j);
    sol = 987654321;

    for (int i=0; i*2<n; i++)
    {
        team[i]=true;
        dfs(i, 1);
        team[i]=false;
    }

    printf("%d\n", sol);

    return 0;
}
