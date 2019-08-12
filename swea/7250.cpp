/**
 * 19.4.13. 16:28~
 */
#include <cstdio>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int t, n, m, k, tt, sol;
char map[1001][1001];
bool visited[1001][1001][2]; // 0: fire 1: hero 2: enemy
int visitedHero[1001][1001];

int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

queue<pair<int, pair<int, int>>> hero;
queue<pair<int, int>> enemys;
queue<pair<int, int>> fires;

void clesrfunc()
{
    queue<pair<int, pair<int, int>>> heroTmp;
    queue<pair<int, int>> enemysTmp;
    queue<pair<int, int>> firesTmp;
    swap(hero, heroTmp);
    swap(enemys, enemysTmp);
    swap(fires, firesTmp);
}

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<m; }

int main(int argc, char const *argv[])
{
    scanf("%d\n", &t);
    for (int tc=1; tc<=t; tc++)
    {
        sol = 987654321;
        scanf("%d %d %d\n", &n, &m, &k);
        for (int i=0; i<n; i++) 
        {
            scanf("%s", map[i]);
            for (int j=0; j<m; j++)
            {
                for (int z=0; z<2; z++) visited[i][j][z] = false;
                visitedHero[i][j] = -1;
                if (map[i][j] == 'F') // Fire
                {
                    fires.push({i, j});
                    visited[i][j][0] = true;
                }
                else if (map[i][j] == 'S') // Hero
                {
                    hero.push({k, {i, j}});
                    map[i][j] = 'A';
                    visitedHero[i][j] = k;
                }
                else if (map[i][j] == 'V') // Enemy
                {
                    enemys.push({i, j});
                    map[i][j] = 'A';
                    visited[i][j][1] = true;
                }
            }
        }

        tt = 0;
        while (++tt)
        {
            for (int i=0; i<n; i++) 
            {
                for (int j=0; j<m; j++) printf("%c ", map[i][j]);
                printf("\n");
            }
            long szFire = fires.size();
            while (szFire--)
            {
                pair<int, int> f = fires.front(); fires.pop();
                for (int i=0; i<4; i++)
                {
                    int newFireRow = f.first+dir[i][0];
                    int newFireCol = f.second+dir[i][1];

                    if (!chk(newFireRow,newFireCol)) continue;
                    if (map[newFireRow][newFireCol] != 'A' || map[newFireRow][newFireCol] == 'E') continue;
                    if (visited[newFireRow][newFireCol][0]) continue;

                    visited[newFireRow][newFireCol][0] = true;
                    map[newFireRow][newFireCol] = 'F';
                    fires.push({newFireRow, newFireCol});
                }
            }

            long szEnemy = enemys.size();
            while (szEnemy--)
            {
                pair<int, int> f = enemys.front(); enemys.pop();
                for (int i=0; i<4; i++)
                {
                    int newEnemyRow = f.first+dir[i][0];
                    int newEnemyCol = f.second+dir[i][1];

                    if (!chk(newEnemyRow,newEnemyCol)) continue;
                    if (map[newEnemyRow][newEnemyCol] == 'X' || map[newEnemyRow][newEnemyCol] == 'W') continue;
                    
                    if (map[newEnemyRow][newEnemyCol] == 'E')
                    {
                        clesrfunc();
                        szEnemy = 0;
                        break;
                    }

                    if (visited[newEnemyRow][newEnemyCol][1]) continue;
                    visited[newEnemyRow][newEnemyCol][1] = true;
                    enemys.push({newEnemyRow, newEnemyCol});
                }
            }

            long szHero = hero.size();
            if (szHero==0) break;
            while (szHero--)
            {
                pair<int, pair<int, int>> f = hero.front(); hero.pop();
                for (int i=0; i<4; i++)
                {
                    int newHeroRow = f.second.first+dir[i][0];
                    int newHeroCol = f.second.second+dir[i][1];
                    int newHeroSmall = f.first-1;

                    if (!chk(newHeroRow,newHeroCol)) continue;
                    if (map[newHeroRow][newHeroCol] == 'X' || map[newHeroRow][newHeroCol] == 'F') continue;
                    else if (map[newHeroRow][newHeroCol] == 'A') newHeroSmall = k;
                    else if (map[newHeroRow][newHeroCol] == 'W' && newHeroSmall < 0) continue;
                    else if (map[newHeroRow][newHeroCol] == 'E')
                    {
                        sol = tt;
                        clesrfunc();
                        szHero = 0;
                        break;
                    }

                    if (visitedHero[newHeroRow][newHeroCol]>=newHeroSmall) continue;
                    visitedHero[newHeroRow][newHeroCol] = newHeroSmall;
                    hero.push({newHeroSmall, {newHeroRow, newHeroCol}});
                }
            }
            if (hero.size() == 0) break;
        }
        clesrfunc();
        printf("#%d %d\n", tc, (sol==987654321?-1:sol));
    }
    return 0;
}
