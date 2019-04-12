/**
 * 19.4.10. 16:27~17:44
 */
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int map[10][10];
int sol, cur;
vector<pair<int, pair<int, int>>> vt;
int paper[6]= {0, 5, 5, 5, 5, 5};

bool searchSquare(int row, int col, int len)
{
    if (row+len-1<10 && col+len-1<10)
    {
        for (int iii=0; iii<len; iii++)
            for (int jjj=0; jjj<len; jjj++)
                if (map[row+iii][col+jjj]==0) return false;
    }
    else return false;
    return true;
}

void dfs(int row, int col, int cnt)
{
    // printf("%d %d\n", row, col);
    for (int i=row, jj=col; i<10; i++, jj=0)
    {
        for (int j = jj; j<10; j++)
        {
            if (map[i][j] == 0) continue;
            for (int length=1; length<=5; length++)
            {
                if (paper[length] == 0) continue;
                if (searchSquare(i, j, length))
                {
                    for (int iii=0; iii<length; iii++)
                        for (int jjj=0; jjj<length; jjj++)
                            map[i+iii][j+jjj] = 0;
                    paper[length]--;
                    dfs(i, j+length, cnt+1);
                    for (int iii=0; iii<length; iii++)
                        for (int jjj=0; jjj<length; jjj++)
                            map[i+iii][j+jjj] = 1;
                    paper[length]++;
                }
            }
            return;
        }
    }
    bool rel= true;
    for (int n=0; n<10; n++) for (int m=0; m<10; m++) if (map[n][m] == 1)
    {
        rel = false;
        n = 10;
        break;
    }
    if (rel) sol = min(sol, cnt);
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<10; i++) for (int j=0; j<10; j++) scanf("%d", map[i]+j);
    sol = 101;
    cur = 0;

    dfs(0, 0, 0);

    printf("%d\n", (sol<100?sol:-1));

    return 0;
}
