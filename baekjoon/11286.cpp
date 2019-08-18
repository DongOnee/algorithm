/**
 * 19.2.21.
 */
#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

priority_queue<pair<long long, int>> qu;

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        long long cmd;
        scanf("%lld", &cmd);
        if (cmd == 0)
        {
            if (qu.empty()) printf("0\n");
            else
            {
                printf("%lld\n", (qu.top().second) ? qu.top().first : -qu.top().first);
                qu.pop();
            }
            continue;
        }
        qu.push(make_pair(-abs(cmd), (cmd<0)));
    }
    return 0;
}

