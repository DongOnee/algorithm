#include <iostream>
#include <algorithm>
#define MAXN 131072
#define MAXK 30
using namespace std;

int n, k, cnt, maxlen;
bool map[MAXN*2][MAXK];

int search(int s, int e)
{
    int se = s, es = e, ret = 0;
    int lens = 1, lene = 1;
    s += MAXN, e+= MAXN;
    while (se + lens < es)
    {
        se += lens;
        lens <<= 1;
    }
    while (es )

}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int test_case = 1; test_case <= T; test_case++)
    {
        cin >> n >> k;
        cnt = 0, maxlen = 0;
        for (int i=0; i<n; i++) for (int j=0; j<k; j++) cin >> map[MAXN+i][j];

        for (int idx = MAXN/2; 1 < idx; idx /= 2)
        {
            for (int i=0; i<idx; i++)
            {
                for (int j=0; j<k; j++) map[idx+i][j] = map[2*(idx+i)][j] + map[2*(idx+i)+1][j];
            }
        }
        
        cout << '#' << test_case << ' ' << maxlen << ' ' << cnt << '\n';
    }
    return 0;
}
