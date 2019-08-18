/**
 * 19.4.9. 20:57~21:28
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n, arr[12], sim[4], sol;
int _max = -1000000000, _min = 1000000000;

int calc(int a, int b, int simb)
{
    if (simb == 0) return a+b;
    else if (simb == 1) return a-b;
    else if (simb == 2) return a*b;
    else return a/b;
}

void dfs(int remain, int sums)
{
    if (remain == n)
    {
        _max = max(_max, sums);
        _min = min(_min, sums);
        return;
    }
    for (int i=0; i<4; i++)
    {
        if (0<sim[i])
        {
            sim[i]--;
            dfs(remain+1, calc(sums, arr[remain], i));
            sim[i]++;
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);
    scanf("%d %d %d %d", sim+0, sim+1, sim+2, sim+3);

    dfs(1, arr[0]);

    printf("%d\n%d\n", _max, _min);

    return 0;
}
