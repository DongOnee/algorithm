/**
 * 19.06.24. 21:38 ~ 23:14
 * Heap...?
 */
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> r_pq;
priority_queue<int, vector<int>, less<int>> l_pq;

int main(int argc, char const *argv[])
{
    int n; scanf("%d", &n);
    int k; scanf("%d", &k);
    l_pq.push(k);
    printf("%d\n", k);
    for (int i=1, a; i<n; i++)
    {
        scanf("%d", &a);
        if (r_pq.size() == l_pq.size()) l_pq.push(a);
        else r_pq.push(a);

        if (l_pq.top() > r_pq.top())
        {
            int tp = r_pq.top(); r_pq.pop();
            r_pq.push(l_pq.top());
            l_pq.pop();
            l_pq.push(tp);
        }
        printf("%d\n", l_pq.top());
    }

    return 0;
}

