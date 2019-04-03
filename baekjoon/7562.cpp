/**
 * 19.2.21.
 */
#include <cstdio>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int l;
pair<int, int> start;
pair<int, int> goal;
bool visited[300][300];


pair<int, int> dir[8] = { {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

bool chk(int row, int col) { return 0<=row&&row<l&&0<=col&&col<l; }
bool chk(pair<int, int> input) { return 0<=input.first&&input.first<l&&0<=input.second&&input.second<l; }

int main(int argc, char const *argv[])
{
    scanf("%d", &T);
    for (int test_case = 0; test_case<T; test_case++)
    {
        scanf("%d %d %d %d %d", &l, &start.first, &start.second, &goal.first, &goal.second);
        for (int i=0; i<l; i++) for (int j=0; j<l; j++) visited[i][j] = false;

        queue<pair<int, int>> q;
        q.push(start);
        visited[start.first][start.second] = true;

        int cnt=-1;
        bool gooooal = false;
        while(!q.empty())
        {
            cnt++;
            int size = q.size();
            while(size--)
            {
                pair<int, int> fr = q.front();
                q.pop();

                if (fr == goal)
                {
                    // q 비우기
                    queue<pair<int, int>> empty_q;
                    swap(q, empty_q);
                    gooooal = true;
                    break;
                }
                else
                    for (int i=0; i<8; i++)
                    {
                        pair<int, int> next_point = make_pair(fr.first+dir[i].first, fr.second+dir[i].second);
                        if (!chk(next_point)) continue;
                        if (visited[next_point.first][next_point.second]) continue;
                        q.push(next_point);
                        visited[next_point.first][next_point.second]= true;
                    }
            }
        }

        if (gooooal) printf("%d\n", cnt);
        else printf("0\n");
    }
    return 0;
}
