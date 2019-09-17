#include <cstdio>

int n, m;
int map[10][10];
int predict[2][20], idx[2];
int cntWins[3];

bool ans;

void solution(int cntJiwoo, bool idxEnemy)
{
    if (cntWins[2] == m)
    {
        ans = true;
        return;
    }
    else if (cntWins[0] >= m || cntWins[1] >= m) return;
    else if (cntJiwoo >= n) return;

    int valEnemy = predict[idxEnemy][idx[idxEnemy]++];
    for (int i=1; i<=n; i++)
    {
        if (map[0][i] == 1) continue;
        map[0][i] = 1;
        // VICTORY~
        if (map[i][valEnemy] == 2)
        {
            cntWins[2]++;
            solution(cntJiwoo+1, !idxEnemy);
            cntWins[2]--;
        }
        // LOSE~~~ T.T
        else
        {
            cntWins[idxEnemy]++;
            bool nextWiner = (map[predict[0][idx[0]++]][predict[1][idx[1]++]] != 2);
            cntWins[nextWiner]++;
            solution(cntJiwoo+1, nextWiner);
            cntWins[nextWiner]--;
            cntWins[idxEnemy]--;
            idx[0]--; 
            idx[1]--;
        }
        map[0][i] = 0;
    }
    idx[idxEnemy]--;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) scanf("%d", map[i] +j);
    for (int i=0; i<2; i++) for (int j=0; j<20; j++) scanf("%d", predict[i] +j);

    solution(0, 0);

    printf("%d\n", ans);

    return 0;
}
