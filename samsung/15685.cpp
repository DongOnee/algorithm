#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

int n;
bool map[101][101][20];

int dir[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
int solDir[4][2] = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };

void setMap(pair<int, int> p, int index) { map[p.first][p.second][index] = true; }
bool getSol(int row, int col)
{
    bool ret = true;
    for (int i=0; i<4; i++)
    {
        bool tmp = false;
        for (int j=0; j<n; j++) tmp = tmp || map[row+solDir[i][0]][col+solDir[i][1]][j];
        ret = ret && tmp;
    }
    return ret;
}

pair<int, int> go(pair<int, int> p, pair<int, int> benchmark) {return {benchmark.first-(benchmark.second-p.second), benchmark.second+(benchmark.first-p.first)};}

void dragonCurve(pair<int, int> startPoint, int startDir, int generation, int index)
{
    vector<pair<int, int>> points;
    pair<int, int> benchPoint = {startPoint.first+dir[startDir][0], startPoint.second+dir[startDir][1]};

    for (int gen=1; gen<=generation; gen++)
    {
        for (auto x : points)
        {
            pair<int, int> turnPoint = go(x, benchPoint);
            points.push_back(turnPoint);
            setMap(turnPoint, index);
        }
        points.push_back(benchPoint);
        setMap(benchPoint, index);
        benchPoint = go(startPoint, benchPoint);
    }
    setMap(benchPoint, index);
    setMap(startPoint, index);
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0, x, y, d, g; i<n; i++)
    {
        scanf("%d %d %d %d", &y, &x, &d, &g);
        dragonCurve({x, y}, d, g, i);
    }

    int ret = 0;
    for (int row=0; row<100; row++) for (int col=0; col<100; col++) if (getSol(row, col)) ret++;

    printf("%d\n", ret);
    return 0;
}
