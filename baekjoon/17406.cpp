#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 987654321

typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }
pii operator-(const pii& a, const pii& b) { return {a.first-b.first, a.second-b.second}; }

int n, m, map[50][50];
int k, ans = INF;
bool visited[6];
pii dir[4] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

vector<ppiii> operators;

void turn(const pii center, const int len)
{
    pii point = center - make_pair(len, len);
    int tmp = map[point.first][point.second];
    for (int i=0; i<4; i++)
    {
        int loop = len*2;
        while (loop--)
        {
            pii nxt_point = point + dir[i];
            map[point.first][point.second] = map[nxt_point.first][nxt_point.second];
            point = nxt_point;
        }
    }
    map[center.first-len][center.second-len+1] = tmp;
}

void uturn(pii center, int len)
{
    pii point = center - make_pair(len, len);
    int tmp = map[point.first][point.second];
    for (int i=3; i>=0; i--)
    {
        int loop = len*2;
        while (loop--)
        {
            pii nxt_point = point - dir[i];
            map[point.first][point.second] = map[nxt_point.first][nxt_point.second];
            point = nxt_point;
        }
    }
    map[center.first-len+1][center.second-len] = tmp;
}

void dfs(int cnt)
{
    if (cnt == k)
    {
        for (int i=0; i<n; i++)
        {
            int sum = 0;
            for (int j=0; j<m; j++) sum += map[i][j];
            ans = ans<sum?ans:sum;
        }
    }
    else
    {
        for (int i=0; i<k; i++)
        {
            if (visited[i]) continue;
            visited[i] = true;
            for (int len = 1; len <= operators[i].second; len++) turn(operators[i].first, len);
            dfs(cnt+1);
            for (int len = 1; len <= operators[i].second; len++) uturn(operators[i].first, len);
            visited[i] = false;
        }
    }
    
}

int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", map[i]+j);
    for (int i=0, a, b, c; i<k; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        operators.push_back({{a-1, b-1}, c});
    }

    dfs(0);

    printf("%d\n", ans);
    return 0;
}
