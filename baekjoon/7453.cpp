/**
 * 19.4.12.
 */
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int n;
long long sol;
int arr[4][4001], sumArr[2][16000001];

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) for (int j=0; j<4; j++) scanf("%d", arr[j]+i);

    for (int i=0; i<2; i++)
        for (int x=0; x<n; x++)
            for (int y=0; y<n; y++)
                sumArr[i][x*n+y] = arr[2*i][x] + arr[2*i+1][y];

    sort(sumArr[0], sumArr[0]+n*n, greater<int>()); // 큰거부터
    sort(sumArr[1], sumArr[1]+n*n); // 작은거부터

    // for (int i=0; i<36; i++) printf("%d %d\n", sumArr[0][i], sumArr[1][i]);

    long long ans = 0;
    for (int i=0; i<n*n; i++)
    {
        auto target = sumArr[0][i];
        auto lo = lower_bound(sumArr[1], sumArr[1]+n*n, -target);
        auto hi = upper_bound(sumArr[1], sumArr[1]+n*n, -target);
        ans += hi - lo;
    }

    printf("%lld\n", ans);
    return 0;

    for (int i=0, j=0; i<n*n && j<n*n;)
    {
        if (sumArr[0][i] + sumArr[1][j] == 0)
        {
            int cnti=0, cntj=0;
            while (sumArr[0][i] == sumArr[0][i+cnti] && i+cnti < n*n) cnti++;
            while (sumArr[1][j] == sumArr[1][j+cntj] && j+cntj < n*n) cntj++;
            sol += cnti*cntj;
            i += cnti;
            j += cntj;
        }
        else if (sumArr[0][i] + sumArr[1][j] > 0) i++;
        else j++;
    }

    printf("%lld\n", sol);
    return 0;
}
