#include <cstdio>
#include <vector>
#define INF 0x0fffffffffffffff
using namespace std;

typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int n, m, src, dest;
vector<ppiii> trip;
vector<long long> value, earn;
vector<vector<bool>> isConnect;

int main(int argc, char const *argv[])
{
    scanf("%d%d%d%d", &n, &src, &dest, &m);
    value.assign(n, -INF);
    isConnect.assign(n, vector<bool>(n, false));
    for (int i=0, a, b, c; i<m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        trip.push_back({{a, b}, c});
        isConnect[a][b] = true;
    }
    for (int i=0; i < n; i++)
    {
        long long a;
        scanf("%lld", &a);
        earn.push_back(a);
    }

    for (int k =0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) 
        if (isConnect[i][k] && isConnect[k][j]) isConnect[i][j] = true;

    bool flag = false;
    value[src] = earn[src];
    for (int loop_cnt = 0; loop_cnt < n; loop_cnt++)
    {
        for (auto x : trip)
        {
            int ssrc = x.first.first;
            int ddest = x.first.second;
            int cost = x.second;
            if (value[ssrc] != -INF && value[ddest] < value[ssrc] - cost + earn[ddest])
            {
                value[ddest] = value[ssrc] - cost + earn[ddest];
                if (loop_cnt == n-1 && isConnect[ddest][dest]) flag = true;
            }
        }
    }

    if (flag) printf("Gee\n");
    else if (value[dest] == -INF) printf("gg\n");
    else printf("%lld\n", value[dest]);
    
    return 0;
}
