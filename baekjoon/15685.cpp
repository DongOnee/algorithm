/**
 * 18.12.9. 일요일.
 */
#include <cstdio>
#include <utility>
using namespace std;

int dir[4][2] = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };

int map[101][101][20];
int N;
pair<int, int> center;

bool chk(pair<int, int> point) {return 0<=point.first&&point.first<101&&0<=point.second&&point.second<101;}
void set_map(pair<int, int> point, int gen, int index) {map[point.first][point.second][index]=gen;}
int get_map(pair<int, int> point, int index) {return map[point.first][point.second][index];}

bool chk2(pair<int, int> point, int index) {
    for (int i=0; i<index; i++) if (get_map(point, i) != 0) return true;
    return false;
}

pair<int, int> getnext(pair<int, int> point) {
    pair<int, int> diff = make_pair(point.first-center.first, point.second-center.second);
    return make_pair(center.first-diff.second, center.second+diff.first);
}

void turn(pair<int, int> point, int index, int gen) {
    pair<int, int> next_point = getnext(point);
    if (!chk(next_point)) return;
    if (get_map(next_point, index)==gen)
    {
        set_map(point, gen+1, index);
        turn(next_point, index, gen);
    }
    else
    {
        set_map(point, gen+1, index);
        set_map(next_point, gen+1, index);
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int dc=0; dc<N; dc++)
    {
        int x, y, d, g;
        scanf("%d %d %d %d", &x, &y, &d, &g);
        center = make_pair(x+dir[d][0], y+dir[d][1]);
        set_map({x, y}, 1, dc);
        set_map(center, 1, dc);

        for (int generation=1; generation<=g; generation++)
        {
            for (int _x=0; _x<101; _x++)
            {
                for (int _y=0; _y<101; _y++)
                {
                    if (map[_x][_y][dc]==generation) turn({_x, _y}, dc, generation);
                }
            }
            center = getnext({x, y});
        }
    }

    int ret=0;
    for (int _x=0; _x<100; _x++)
    {
        for (int _y=0; _y<100; _y++)
        {
            if (chk2({_x, _y}, N)&&chk2({_x+1, _y}, N)&&chk2({_x, _y+1}, N)&&chk2({_x+1, _y+1}, N)) ret++;
        }
    }
    printf("%d\n", ret);
    return 0;
}
