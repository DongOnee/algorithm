/**
 * 19.4.3.
 */
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int n, m;
int map[1001][1001];
bool chkMap[1001];

vector<int> vt;
priority_queue<pair<int, pair<int, int>>> pq;

int main(int argc, char const *argv[])
{
    scanf("%d\n%d", &n, &m);
    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
        pq.push(make_pair(-c, make_pair(a, b)));
    }

    int sol=0;
    int indexNetwork=1;
    while (!pq.empty())
    {
        pair<int, pair<int, int>> tp = pq.top();
        pq.pop();
        int a=tp.second.first;
        int b=tp.second.second;
        int cost = -tp.first;
    }

    printf("%d\n", sol);
    return 0;
}
