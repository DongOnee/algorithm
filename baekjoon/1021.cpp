/**
 * 2019.3.7.
 */
#include <cstdio>
#include <deque>
using namespace std;

int n, m;
deque<int> dq;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) dq.push_back(i);
    int ret=0;
    for (int i=0, a; i<m; i++)
    {
        scanf("%d", &a);
        int index=0;
        for (auto here : dq)
        {
            if (here == a) break;
            index++;
        }
        if (index*2 < dq.size())
        {
            while (dq.front() != a)
            {
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
                ret++;
            }
        }
        else
        {
            while (dq.front() != a)
            {
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
                ret++;
            }
        }
        dq.pop_front();
    }

    printf("%d\n", ret);
    return 0;
}
