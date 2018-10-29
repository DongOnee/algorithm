#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

int **map;
int **d;
int size;
int dir[2][2] = { {1, 0}, {0, 1} };

queue<pair<int, int>> q;

bool chk(int row, int col) { return 0<=row && row<size && 0<=col && col<size; }

void bfs(int row, int col) {

}

void dp() {

}

int main(int argc, char const *argv[])
{
    scanf("%d", &size);
    map = new int*[size];
    d = new int*[size];
    for (int i=0; i<size; i++)
    {
        map[i] = new int[size];
        d[i] = new int[size];
        for (int j=0; j<size; j++)
        {
            scanf("%d", &map[i][j]);
            d[i][j] = 0;
        }
    }

    dp();

    printf("%d\n", d[0][0]);
    return 0;
}
