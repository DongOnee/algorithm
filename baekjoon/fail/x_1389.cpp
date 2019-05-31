/**
 * 19.2.26.
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
int relation[101][101];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);

    for (int i=0, a, b; i<M; i++)
    {
        scanf("%d %d", &a, &b);
        relation[a][b] = 1;
        relation[b][a] = 1;
    }

    for (int i=1; i<=N; i++)
        for (int j=1; j<=N; j++)
            if (!relation[i][j]) relation[i][j]=(i == j ? 1e9 : 0);

    for (int k=1; k<=N; k++) 
        for (int i=1; i<=N; i++)
        {
            if (relation[i][0]) continue;
            vector<int> vt;
            if (relation[i][k] == 0) continue;
            for (int j=1; j<=N; j++) if (relation[i][j] == 0) vt.push_back(j);
            if (vt.empty()) relation[i][0] = 1;
            while(!vt.empty()) // i 에서 갈수없는 j 들.
            {
                int j = vt.back();
                vt.pop_back();
                if (relation[k][j] == 0) continue;
                relation[i][j] = relation[i][k] + relation[k][j];
            }
        }

    int min_ = 987654321;
    int min_index = 0;
    for (int i=1; i<=N; i++)
    {
        int sum_=0;
        for (int j=1; j<=N; j++)
        {
            // printf("%d ", relation[i][j]);
            if (i == j) continue;
            sum_ += relation[i][j];
        }
        // puts("");
        if (sum_ < min_)
        {
            min_ = sum_;
            min_index = i;
        }
    }
        // puts("");
        // puts("");

    printf("%d\n", min_index);
    return 0;
}
