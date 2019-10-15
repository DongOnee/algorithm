#include <cstdio>
#include <list>
using namespace std;

int n, m;

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    while (t--)
    {
        list<int> lst;
        scanf("%d%d", &n, &m);
        for (int i=1; i<=n; i++) lst.push_back(i);
        for (int i=0, a; i<m; i++)
        {
            scanf("%d", &a);
            list<int>::iterator itr = lst.begin();
            int ans = 0;
            while (*itr != a)
            {
                itr++;
                ans++;
            }
            printf("%d ", ans);
            lst.erase(itr);
            lst.push_front(a);
        }
        printf("\n");
    }
    return 0;
}
