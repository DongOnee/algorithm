/**
 * 19.2.22.
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
bool solved[32001];
vector<int> pre_solv[32001];

void dfs(int prob, int root)
{
    solved[prob] = true;
    sort(pre_solv[prob].begin(), pre_solv[prob].end());
    for (auto a : pre_solv[prob]) // prob 보다 먼저 풀어야될 문제들
        if (!solved[a]) dfs(a, root);

    for (int i=1; i<root; i++) 
        if (!solved[i]) dfs(i, i);

    printf("%d ", prob);
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);
    for (int i=0, a, b; i<M; i++)
    {
        scanf("%d%d", &a, &b); // a문제는 b보다 먼저 풀기
        pre_solv[b].push_back(a);
    }

    for (int i=1; i<=N; i++)
        if (!solved[i]) dfs(i, i);

    return 0;
}
/*
5 3

5 1
3 5
4 2

5
4
.
.
3

3 5 1 4 2
4 2 3 5 1
-----------------------------------
4 2

4 2
3 1

3
4
.
.

3 1 4 2
-----------------------------------

*/