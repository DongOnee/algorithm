/**
 * 19.1.1. x
 * 19.1.2.
 */
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N;
pair<int, int> data[100001];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        scanf("%d %d", &data[i].second, &data[i].first);
    }

    sort(data, data+N);
    // puts("");
    // for (int i=0; i<N; i++) printf("%d %d\n", data[i].second, data[i].first);
    // puts("");
    int cur=0, mx=0;
    for (int i=0; i<N; i++)
    {
        if (cur <= data[i].second)
        {
            cur = data[i].first;
            mx++;
        }
    }
    printf("%d\n", mx);
    return 0;
}
