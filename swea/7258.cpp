/**
 * 2019.07.29. 21:39 ~
 */
#include <cstdio>
using namespace std;

char map[21][21];
bool visit[20][20][16][4];
int R, C;
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool dfs(int row, int col, int dirs, int mems)
{
    int new_dir = dirs;
    if (map[row][col] == '<') new_dir = 0;
    else if (map[row][col] == '>') new_dir = 1;
    else if (map[row][col] == '^') new_dir = 2;
    else if (map[row][col] == 'v') new_dir = 3;
    else if (map[row][col] == '_') new_dir = (mems == 0 ? 1 : 0);
    else if (map[row][col] == '|') new_dir = (mems == 0 ? 3 : 2);
    else if (map[row][col] == '@') return true;
    else if (map[row][col] == '.') ;
    else if (map[row][col] == '+') mems+=1;
    else if (map[row][col] == '-') mems+=15;
    else if (0 <= map[row][col]-'0' && map[row][col]-'0' < 10) mems = map[row][col] - '0';
    mems %= 16;
    
    if (visit[row][col][mems][new_dir]) return false;
    visit[row][col][mems][new_dir] = true;

    int nrow = row + (dir[new_dir][0]+R);
    nrow %= R;
    int ncol = col + (dir[new_dir][1]+C);
    ncol %= C;

    if (map[row][col] == '?') for (int i=0; i<4; i++)
    {
        visit[row][col][mems][i] = true;
        int nrow = row + (dir[i][0]+R);
        int ncol = col + (dir[i][1]+C);
        if(dfs(nrow%R, ncol%C, i, mems)) return true;
    }

    else return dfs(nrow, ncol, new_dir, mems);

    return false;
}

int main(int argc, char const *argv[])
{
    int t; scanf("%d", &t);
    for (int tc=1; tc<=t; tc++)
    {
        scanf("%d%d", &R, &C);
        for (int i=0; i<R; i++) 
        {
            scanf("%s", map[i]);
            for (int j=0; j<C; j++) for (int k=0; k<16; k++) for(int v=0; v<4; v++) visit[i][j][k][v] = false;
        }
        
        printf("#%d %s\n", tc, dfs(0, 0, 1, 0)?"YES":"NO");
    }
    return 0;
}

/**
static boolean dfs(int x, int y, int dir) {
    if ('0' <= map[x][y] && map[x][y] <= '9' ) memory = map[x][y] - 48;
    else if (map[x][y] == '>' || map[x][y] == '_' && memory == 0) dir = 0;
    else if (map[x][y] == '<' || map[x][y] == '_' && memory != 0) dir = 1;
    else if (map[x][y] == 'v' || map[x][y] == '|' && memory == 0) dir = 2;
    else if (map[x][y] == '^' || map[x][y] == '|' && memory != 0) dir = 3;
    else if (map[x][y] == '+' ) memory = (memory+1) % 15;
    else if (map[x][y] == '-' && memory == 0) memory = 15;
    else if (map[x][y] == '-') memory -=1;
    else if (map[x][y] == '@') return true;
    
    if (visited[x][y][dir][memory]) return false; //한 번 지나간 길은 다시 지나지 않음 -> 무한 루프 방지 
    visited[x][y][dir][memory] = true;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if (nx == 0) nx = R; // 양 끝단에 다다르면 다른 방향으로 간다. 
    else if (nx == R+1) nx = 0;

    if (ny == 0) ny = C;
    else if (ny == C+1) ny = 0;

    if (map[x][y] == '?') { //네 방향 모두 탐색해줌 
        for (int i = 0; i < 4; i++) {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx == 0) nx = R;
            else if (nx == R+1) nx = 0;

            if (ny == 0) ny = C;
            else if (ny == C+1) ny = 0;

            return dfs(nx, ny, i);
        }
    }
    else //?이 아닌 경우에는 위에서 설정한 규칙에 맞게 탐색한다. 
        return dfs(nx, ny, dir);

    return false;
}
 */