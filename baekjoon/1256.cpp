/**
 * 19.3.29.
 */
#include <cstdio>
#include <vector>
using namespace std;

int a, z, k;
long long dp[101][101]; // dp[i][j] : 'a' 가 i 개 'z' 가 j 개 있을때 조합의 수
vector<char> vt;

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &a, &z, &k);
    for (int i=0; i<=a; i++) dp[i][0] = 1;
    for (int j=1; j<=z; j++) dp[0][j] = 1;
    int jx=1;
    while (0<z)
    {
        // printf("a:%d\tz:%d\tk:%d\n", a, z, k);
        int cnta=0;
        while (dp[cnta][z-1] < k)
        {
            k -= dp[cnta][z-1];
            cnta++;
            for (int j = jx; j<z; j++) dp[cnta][j] = dp[cnta-1][j] + dp[cnta][j-1];
        }
        if (cnta > a )
        {
            printf("-1");
            return 0;
        }
        while (a>cnta)
        {
            vt.push_back('a');
            a--;
        }
        vt.push_back('z');
        z--;
    }
    // while (z--) printf("z");
    while (a--) vt.push_back('a');
    for (auto x:vt) printf("%c", x);
    
    return 0;
}


/*
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
zzzzzzzzzzzzzzazzazzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzazzzzzzzzzzzzzzzzzzzzzzazzzzzazzzzzzzzzzzzazzzz
*/