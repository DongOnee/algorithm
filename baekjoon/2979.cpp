#include <cstdio>
#include <queue>
using namespace std;

typedef pair<int, bool> pib;

int pay[4], ans;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", pay+1, pay+2, pay+3);

    priority_queue<pib> pq;
    for (int i=0, st, en; i<3; i++)
    {
        scanf("%d%d", &st, &en);
        pq.push({en, true});
        pq.push({st, false});
    }

    int cur = pq.top().first, cnt = 1;
    pq.pop();

    while (!pq.empty())
    {
        pib tp = pq.top(); pq.pop();
        ans += cnt * pay[cnt] * (cur-tp.first);
        if (tp.second) cnt++;
        else cnt--;
        cur = tp.first;
    }

    printf("%d\n", ans);
    return 0;
}
