/**
 * 19.2.22.
 */
#include <cstdio>
#include <queue>
using namespace std;

priority_queue<long long> qu;

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
                printf("%lld\n", qu.top());
                qu.pop();
            }
            continue;
        }
        qu.push(cmd);
    }
    return 0;
}