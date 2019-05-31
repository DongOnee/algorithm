/**
 * 18.12.9. 일요일.
 */

#include <cstdio>
#include <utility>
using namespace std;

int map[101][101][20];
int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };

pair<int, int> center;

bool chk(pair<int, int> point) { return 0<=point.first&&point.first<=100&&0<=point.second&&point.second<=100; }

bool chk2(pair<int, int> point, int N) {
    for (int i=0; i<N; i++) if (map[point.first][point.second][i] != 0) return true;
    return false;
}

pair<int, int> turn(pair<int, int> point) {
    pair<int, int> diff = {point.first - center.first, point.second - center.second};
    return {center.first+diff.second, center.second-diff.first};
}

void turn(pair<int, int> point, int gen, int index) {
    map[point.first][point.second][index] = gen;
    if (!chk(new_point)) return;
    pair<int, int> new_point = turn(point);
    map[new_point.first][new_point.second][index] = gen;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);

    for (int i=0; i<N; i++)
    {
        int col, row, d, g;
        scanf("%d %d %d %d", &col, &row, &d, &g);

        center = { row + dir[d][0], col + dir[d][1] };
        
        map[row][col][i] = 1;
        map[center.first][center.second][i] = 1;

        for (int gen=1; gen<=g; gen++)
        {
            for (int row_index=0; row_index<101; row_index++)
            {
                for (int col_index=0; col_index<101; col_index++)
                {
                    if (map[row_index][col_index][i] == gen) turn({row_index, col_index}, gen+1, i);
                }
            }
            center = turn({row, col});
        }
    }

    int ret= 0;
    for (int row_index=0; row_index<100; row_index++)
        for (int col_index=0; col_index<100; col_index++)
            if (chk2({row_index, col_index}, N)&&chk2({row_index+1, col_index}, N)&&chk2({row_index, col_index+1}, N)&&chk2({row_index+1, col_index+1}, N)) ret++;

    printf("%d\n", ret);
    return 0;
}
