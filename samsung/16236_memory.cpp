#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int, pair<int, int>> fish_info;

int n, map[21][21];
bool visited[21][21];

int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

pair<int, int> babyShark;
int age, feed;
vector<fish_info> fishes;

bool chk(int row, int col) { return 0<=row&&row<n&&0<=col&&col<n; }

queue<pair<int, int>> qu;
void bfs(pair<int, int> point)
{
    visited[point.first][point.second] = true;
    for (int i=0; i<4; i++)
    {
        int newRow = point.first+dir[i][0];
        int newCol = point.second+dir[i][1];
        if (!chk(newRow, newCol)) continue;
        if (visited[newRow][newCol]) continue;
        if (map[newRow][newCol] > age) continue;
        qu.push({newRow, newCol});
    }
}

int calc(pair<int, int> fish)
{
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) visited[i][j] = false;
    int ti= 0;
    while(!qu.empty())
    {
        long sz = qu.size();
        while(sz--)
        {
            pair<int, int> f = qu.front();
            qu.pop();
            if (f == fish)
            {
                queue<pair<int, int>> emptyQu;
                swap(emptyQu, qu);
                return ti;
            }
            bfs(f);
        }
        ti++;
    }
    return 987654321;
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
            else
            {
                if (tmp != 0) fishes.push_back({tmp, {i, j}});
                map[i][j] = tmp;
            }
        }
    }

    int time = 0;
    while (!fishes.empty())
    {
        sort(fishes.begin(), fishes.end());
        int maxIndex=0, canEatDist = 987654320, index=-1;
        for (; maxIndex<fishes.size(); maxIndex++) 
        {
            if (age <= fishes[maxIndex].first) break;
            qu.push(babyShark);
            int dist = calc(fishes[maxIndex].second);
            if (dist < canEatDist)
            {
                index=maxIndex;
                canEatDist = dist;
            }
            else if (dist == canEatDist)
            {
                if (fishes[maxIndex].second.first < fishes[index].second.first) index=maxIndex;
                else if (fishes[maxIndex].second.first == fishes[index].second.first)
                    if (fishes[maxIndex].second.second < fishes[index].second.second) index=maxIndex;
            }
        }
        if (index == -1) break;
        babyShark = fishes[index].second;
        map[fishes[index].second.first][fishes[index].second.second] = 0;

        if (--feed == 0)
        {
            age++;
            feed = age;
        }
        fishes.erase(fishes.begin()+index);
        time += canEatDist;
    }

    printf("%d\n", time);


    return 0;
}
