/**
 * 19.2.22.
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> next_solv[32001];
priority_queue<int> pq;
int pre_solve_problem_cnt[32001];

int N, M;

int main(int argc, char const *argv[])
{
    scanf("%d%d", &N, &M);

    for (int i=0, a, b; i<M; i++)
    {
        scanf("%d%d", &a, &b); // a가 b 보다 먼저
        next_solv[a].push_back(b);
        pre_solve_problem_cnt[b]++;
    }

    for (int i=1; i<=N; i++)
        if (!pre_solve_problem_cnt[i]) 
            pq.push(-i);

    while(!pq.empty())
    {
        int t = -pq.top();
        pq.pop();
        printf("%d ", t);
        for(auto a : next_solv[t])
        {
            pre_solve_problem_cnt[a]--;
            if (!pre_solve_problem_cnt[a]) 
                pq.push(-a);
        }
    }

    return 0;
}

/*
5 3

5 1
3 5
4 2

. t
. t
5
2
1 t

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
