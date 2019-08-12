#include <cstdio>
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, pair<int, int>> fish_info;

int n, map[21][21];
bool visited[21][21];

int dir[4][2] = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

pair<int, int> babyShark;
int age, feed;

vector<pair<int, int>> canEats;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

queue<pair<int, int>> sharkMv;
void bfs(pair<int, int> point)
{
    for (int i=0; i<4; i++)
    {
        int newRow = point.first+dir[i][0];
        int newCol = point.second+dir[i][1];
        if (!chk(newRow, newCol)) continue;
        if (visited[newRow][newCol]) continue;
        if (map[newRow][newCol] > age) continue;
        if (0< map[newRow][newCol] && map[newRow][newCol] < age)
        {
            canEats.push_back({newRow, newCol});
        }
        else sharkMv.push({newRow, newCol});
        visited[newRow][newCol] = true;
    }
}

int main(int argc, char const *argv[])
{
    age=2, feed=2;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp == 9)
            {
                babyShark = {i, j};
                map[i][j] = 0;
            }
            else map[i][j] = tmp;
        }
    }

    int time = 0;
    int segTime = 0;
    
    sharkMv.push(babyShark);
    visited[babyShark.first][babyShark.second] = true;
    while (!sharkMv.empty())
    {
        long sz = sharkMv.size();
        int indexRow = 30, indexCol = 30;
        bool canEat = false;
        while (sz--)
        {
            pair<int, int> f = sharkMv.front();
            sharkMv.pop();
            bfs(f);
        }

        segTime++;
        if (canEats.size() != 0)
        {
            sort(canEats.begin(), canEats.end());
            pair<int, int> sibal = canEats[0];
            map[sibal.first][sibal.second] = 0;
            queue<pair<int, int>> emptyQu;
            emptyQu.push(sibal);
            swap(emptyQu, sharkMv);
            time += segTime;
            segTime = 0;
            for (int i=0; i<n; i++) for (int j=0; j<n; j++) visited[i][j] = false;
            visited[sibal.first][sibal.second] = true;
            canEats.clear();
            if (--feed == 0)
            {
                age++;
                feed=age;
            }
            continue;
        }
    }

    printf("%d\n", time);


    return 0;
}
