/**
 * 2019.07.29. 21:39 ~
 */
#include <cstdio>
#include <cstdlib>
using namespace std;

char map[21][21];
bool visit[20][20][16][4];
int R, C, mem, cur_r, cur_c, cur_dir;
int dir[4][2] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };

bool dfs(int row, int col, int dirs, int mems)
{
    if (map[row][col] == '<') dirs = 0;
    else if (map[row][col] == '>') dirs = 1;
    else if (map[row][col] == '^') dirs = 2;
    else if (map[row][col] == 'v') dirs = 3;
    else if (map[row][col] == '_') dirs = (mems == 0 ? 1 : 0);
    else if (map[row][col] == '|') dirs = (mems == 0 ? 3 : 2);
    else if (map[row][col] == '@') return true;
    else if (map[row][col] == '.') ;
    else if (map[row][col] == '+') mems+=1;
    else if (map[row][col] == '-') mems+=15;
    else if (map[row][col] == '?') for (int i=0; i<4; i++) dfs(row+dir[i][0], col+dir[i][1], i, mems);
    else mems = map[row][col] - '0';
    mem %= 16;
    
    if (visit[row][col][mems][dirs]) return false;
    visit[row][col][mems][dirs] = true;
    
    cur_r += (dir[cur_dir][0]+R);
    cur_r %= R;
    cur_c += (dir[cur_dir][1]+C);
    cur_c %= C;
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
        cur_r = 0, cur_c = 0, cur_dir = 1;

        bool flag = true;
        while(1)
        {
            if (visit[cur_r][cur_c][mem][cur_dir])
            {
                flag = false;
                break;
            }
            visit[cur_r][cur_c][mem][cur_dir] = true;
            if (map[cur_r][cur_c] == '<') cur_dir = 0;
            else if (map[cur_r][cur_c] == '>') cur_dir = 1;
            else if (map[cur_r][cur_c] == '^') cur_dir = 2;
            else if (map[cur_r][cur_c] == 'v') cur_dir = 3;
            else if (map[cur_r][cur_c] == '_') cur_dir = (mem == 0 ? 1 : 0);
            else if (map[cur_r][cur_c] == '|') cur_dir = (mem == 0 ? 3 : 2);
            else if (map[cur_r][cur_c] == '@') break;
            else if (map[cur_r][cur_c] == '.') ;
            else if (map[cur_r][cur_c] == '+') mem+=1;
            else if (map[cur_r][cur_c] == '-') mem+=15;
            else if (map[cur_r][cur_c] == '?') cur_dir = (rand() % 4);
            else mem = map[cur_r][cur_c] - '0';
            mem %= 16;
            
            cur_r += (dir[cur_dir][0]+R);
            cur_r %= R;
            cur_c += (dir[cur_dir][1]+C);
            cur_c %= C;
        }

        printf("#%d %s\n", tc, flag?"YES":"NO");
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