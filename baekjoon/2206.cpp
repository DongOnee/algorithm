#include <utility>
#include <queue>
#include <cstdio>
using namespace std;

int **map;
pair<int, int> **visited;

typedef struct node{
    pair<int, int> p;
    bool chance;
    int count;
}Node;

queue<Node> q;
int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

void bfs(Node node, int N, int M) {
    int row = node.p.first;
    int col = node.p.second;
    bool ischance = node.chance;
    int count = node.count;
    printf("%d %d %d\n", row, col, count);
    if (map[row][col] == 1)
    {
        if(ischance) ischance = false;
        else return;
    }
    if(ischance)
    {
        if(visited[row][col].first != -1 && visited[row][col].first < count) return;
        visited[row][col].first = count;
    }
    else
    {
        if(visited[row][col].second != -1 && visited[row][col].second < count) return;
        visited[row][col].second = count;
    }
    for (int i=0; i<4; i++)
    {
        int next_row = row+dir[i][0];
        int next_col = col+dir[i][0];
        if (-1<next_row && next_row <N && -1<next_col && next_col<M)
        {
            Node tmp;
            tmp.p.first = next_row;
            tmp.p.second = next_col;
            tmp.chance = ischance;
            tmp.count = count+1;
            q.push(tmp);
        }
    }
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    map = new int*[N];
    visited = new pair<int, int>*[N];
    for (int row=0; row < N; row++)
    {
        *(map+row) = new int[M];
        *(visited+row) = new pair<int, int>[M];
        int input;
        scanf("%d", &input);
        for (int col=M-1; -1<col; col--)
        {
            map[row][col] = input%10;
            visited[row][col].first = -1;
            visited[row][col].second = -1;
            input /= 10;
        }
    }

    Node init_node;
    init_node.p.first = 0;
    init_node.p.second = 0;
    init_node.chance = true;
    init_node.count = 1;
    q.push(init_node);
    visited[0][0].first = 1;

    while(!q.empty())
    {
        Node tmp = q.front();
        q.pop();
        bfs(tmp, N, M);
    }

    printf("%d\n", visited[N-1][M-1].first);
    return 0;
}