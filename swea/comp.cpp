/**
 *
 */
#include <cstdio>
// #include <algorithm>
#include <queue>
// #include <utility>
using namespace std;

int n, m, t;
int map[1001][1001];

int full_search()
{
    int ret =0;
    for(int i=0; i<n; i++) for (int j=0; j<n; j++)
    if (map[i][j] == 1) ret++;
    return ret;
}

bool chk(pair<int, int> pt) { return 0<=pt.first&&pt.first<n&&0<=pt.second&&pt.second<n; }
bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }
int getPt(pair<int, int> pt) { return map[pt.first][pt.second]; }
void setPt(pair<int, int> pt, int val) { map[pt.first][pt.second] = val; }

queue<pair<int, int>> q;
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main(int argc, char const *argv[])
{
    /* code */
    scanf("%d", &t);
    for (int tc=1; tc<=t; tc++)
    {
        queue<pair<int, int>> emp;
        swap(emp, q);
        scanf("%d %d", &n, &m);
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) 
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp ==1) q.push(make_pair(i, j));
            map[i][j] = tmp;
        }

        while(m--)
        {
            int size_ = q.size();
            while(size_--)
            {
                pair<int, int> f = q.front();
                q.pop();
                for (int i=0; i<4; i++)
                {
                    pair<int, int> new_pt = make_pair(f.first+dir[i][0], f.second+dir[i][1]);
                    if (!chk(new_pt)) continue;
                    if (getPt(new_pt) == 0)
                    {
                        q.push(new_pt);
                        setPt(new_pt, 1);
                    }
                }
            }
        }

        printf("#%d %d\n", tc, full_search());
    }
    return 0;
}


/*

4 
4 2
0 0 0 1
0 0 0 0
0 0 0 0
0 0 0 0
5 8
0 2 0 0 0
2 0 0 0 1
0 0 0 0 0
0 0 0 0 2
0 0 0 0 1
7 20
0 0 0 0 0 0 0
2 2 2 2 2 2 0
0 0 0 0 0 0 0
0 2 2 2 2 2 2
0 0 0 0 0 0 0
2 2 2 2 2 2 0
1 0 0 0 0 0 0
7 500
0 0 0 0 0 0 0
2 2 2 2 2 2 0 
0 0 0 0 0 0 0
0 2 2 2 2 2 2
0 0 0 0 0 0 0
2 2 2 2 2 2 0
1 0 0 0 0 0 0
*/