/**
 * 2018.10.5. 07`46``
*/
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

typedef struct node{
    pair<int, int> p;
    bool chance;
    int count;
}Node;

int** map; // 0 : road, 1 : wall
int** visited[2]; // [0] : chance, [1] : no chance
queue<Node> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void bfs(Node front, int N, int M) {
    int x = front.p.first;
    int y = front.p.second;
    bool chance = front.chance;
    int count = front.count;
    if (map[x][y] == 1)
    {
        if (chance) chance = false;
        else return;
    }
    int cat;
    if (chance) cat=0;
    else cat=1;
    for (int i=0; i<4; i++)
    {
        int next_x = x+dir[i][0];
        int next_y = y+dir[i][1];
        int next_count = count+1;
        if (-1<next_x && next_x<N && -1<next_y && next_y<M)
        {
            if (visited[cat][next_x][next_y] == 0)
            {
                Node tmp;
                tmp.p = make_pair(next_x, next_y);
                tmp.chance = chance;
                tmp.count = next_count;
                q.push(tmp);
                visited[cat][next_x][next_y] = next_count;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    map = new int*[N];
    visited[0] = new int*[N];
    visited[1] = new int*[N];
    for (int row=0; row < N; row++)
    {
        *(map+row) = new int[M];
        *(visited[0]+row) = new int[M];
        *(visited[1]+row) = new int[M];
        int input;
        scanf("%d", &input);
        for (int col=M-1; -1<col; col--)
        {
            map[row][col] = input%10;
            visited[0][row][col] = 0;
            visited[1][row][col] = 0;
            input /= 10;
        }
    }
    Node init_node;
    init_node.p=make_pair(0, 0);
    init_node.chance=true;
    init_node.count=1;
    q.push(init_node);
    visited[0][0][0]=1;

    while(!q.empty())
    {
        Node front = q.front();
        q.pop();
        if (front.p == make_pair(N-1, M-1)) break;
        bfs(front, N, M);
    }
    if (visited[0][N-1][M-1] == 0 && visited[1][N-1][M-1] == 0) printf("-1\n");
    else if (visited[0][N-1][M-1] == 0) printf("%d\n", visited[1][N-1][M-1]);
    else if (visited[1][N-1][M-1] == 0) printf("%d\n", visited[0][N-1][M-1]);
    else
    {
        if (visited[0][N-1][M-1] < visited[1][N-1][M-1]) printf("%d\n", visited[0][N-1][M-1]);
        else printf("%d\n", visited[1][N-1][M-1]);
    }

    return 0;
}
