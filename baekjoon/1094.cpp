/**
 * 19.3.6.
 */
#include <cstdio>
#include <queue>
using namespace std;

int x;
int cur=64;
priority_queue<int> pq;

int main(int argc, char const *argv[])
{
    scanf("%d", &x);
    pq.push(-64);
    while (cur > x)
    {
        int tp = -pq.top();
        pq.pop();
        if (cur-tp/2 >= x) cur -= tp/2;
        else pq.push(-tp/2);
        pq.push(-tp/2);
    }

    printf("%ld\n", pq.size());
    return 0;
}
