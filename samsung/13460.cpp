/**
 * 19.4.8.
 */
#include <cstdio>
#include <utility>
using namespace std;

typedef pair<int, int> point;

int n, m, sol;
char map[10][12];
point goal;

int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

void changeMap(point p, char c) {map[p.first][p.second] = c;}

point slide(point ball, int d)
{
    while (true)
    {
        ball.first += dir[d][0];
        ball.second += dir[d][1];
        if (map[ball.first][ball.second] == '.') continue;
        else if (map[ball.first][ball.second] == 'O') return {ball.first, ball.second};
        else break;
    }
    return {ball.first - dir[d][0], ball.second - dir[d][1]};
}

void dfs(point r, point b, int cnt)
{
    if (cnt >= sol) return;
    if (cnt == 10)
    {
        if (b == goal) return;
        if (r == goal) sol = cnt;
        return;
    }
    for (int i=0; i<4; i++)
    {
        point new_b, new_r;
        if (r.first*dir[i][0]+r.second*dir[i][1] < b.first*dir[i][0]+b.second*dir[i][1])
        {
            new_b = slide(b, i);
            char tmp = map[new_b.first][new_b.second];
            if (tmp == '.') changeMap(new_b, 'B');
            new_r = slide(r, i);
            changeMap(new_b, tmp);
        }
        else 
        {
            new_r = slide(r, i);
            char tmp = map[new_r.first][new_r.second];
            if (tmp == '.') changeMap(new_r, 'R');
            new_b = slide(b, i);
            changeMap(new_r, tmp);
        }
        if (new_b == goal) continue;
        if (new_r == goal) sol = min(sol, cnt+1);
        else dfs(new_r, new_b, cnt+1);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d %d\n", &n, &m);
    point ball[2];
    sol = 11;
    for (int i=0; i<n; i++) for (int j=0; j<=m; j++)
    {
        scanf("%c" , map[i]+ j);
        if (map[i][j] == 'R') ball[0] = {i, j};
        else if (map[i][j] == 'B') ball[1] = {i, j};
        else if (map[i][j] == 'O') goal = {i, j};
    }

    // for (int i=0; i<n; i++) printf("%s", map[i]);

    changeMap(ball[0], '.');
    changeMap(ball[1], '.');

    dfs(ball[0], ball[1], 0);

    printf("%d\n", (sol<11?sol:-1));


    return 0;
}
