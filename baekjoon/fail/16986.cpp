#include <cstdio>
using namespace std;

int map[11][11];
int arr[2][20];
int idx[2];
int wincnts[2];
int n, m;
bool ans;


int simul()
{
    return (map[arr[0][idx[0]++]][arr[1][idx[1]++]] == 2 ? 0:1);
}

void unsimul() { idx[0]--, idx[1]--; }

void dfs(int cnt, int wincnt, int idxChallenger)
{
    int chal = arr[idxChallenger][idx[idxChallenger]++];
    
    for (int i =1; i<=n && !ans; i++)
    {
        if (map[0][i] == 1) continue;
        map[0][i] = 1;

        if (map[i][chal] == 2) // 지우 win
        {
            if (wincnt +1 == m) // 끝내기
            {
                ans = true; break;
            }
            dfs(cnt+1, wincnt+1, (idxChallenger+1)%2);
        }
        else // 지우 lose
        {
            if (wincnts[idxChallenger] +1 != m)
            {
                int winneridx = simul();
                if (wincnts[winneridx] +1 != m) 
                {
                    wincnts[idxChallenger]++, wincnts[winneridx]++;
                    dfs(cnt+1, wincnt, winneridx);
                    wincnts[idxChallenger]--, wincnts[winneridx]--;
                }
                unsimul();
            }
        }
        map[0][i] = 0;
    }
    idx[idxChallenger]--;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) for (int j=1; j<=n; j++) scanf("%d", map[i] +j);
    for (int i=0; i<2; i++) for (int j=0; j<20; j++) scanf("%d", arr[i] +j);

    dfs(0, 0, 0);

    printf("%d\n", ans);

    return 0;
}


/*
3 2
1 0 2
2 1 0
0 2 1
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
*/