/**
 * 19.2.15.
 */
#include <cstdio>
#include <vector>
using namespace std;

int N;
vector<int> vt[100001];
int p[100001];

void dfs(int par)
{
    for (auto a : vt[par])
    {
        if (p[a] == 0)
        {
            p[a]=par;
            dfs(a);
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i=1, A, B; i<N; i++)
    {
        scanf("%d %d", &A, &B);
        vt[A].push_back(B);
        vt[B].push_back(A);
    }

    dfs(1);

    for (int i=1; i<N; i++) printf("%d\n", p[i+1]);
    return 0;
}
