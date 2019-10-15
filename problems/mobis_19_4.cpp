#include <string>
#include <vector>
#include <queue>
using namespace std;

pair<int, int> operator+(const pair<int, int>& a, const pair<int, int>& b)
{
    return {a.first+b.first, a.second+b.second};
}

bool chk(int row, int col) { return 0<=row&&row<3&&0<=col&&col<10; }

int simulation(int cnt)
{
    vector<vector<int>> cnt_visit[2];
    cnt_visit[0].assign(3, vector<int>(10, 0));
    cnt_visit[1].assign(3, vector<int>(10, 0));
    cnt_visit[0][1][6]=1;
    
    cnt_visit[0][1][9]=-1;
    cnt_visit[1][1][9]=-1;
    cnt_visit[0][2][7]=-1;
    cnt_visit[1][2][7]=-1;
    cnt_visit[0][2][8]=-1;
    cnt_visit[1][2][8]=-1;
    cnt_visit[0][2][9]=-1;
    cnt_visit[1][2][9]=-1;
    
    vector<pair<int, int>> dir = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
    
    queue<pair<int, int>> points;
    points.push({1, 6});
    
    bool toggle = false;
    while (cnt--)
    {
        long sz = points.size();
        
        vector<vector<bool>> visited;
        visited.assign(3, vector<bool>(10, false));
        
        while (sz--)
        {
            pair<int, int> f = points.front();
            points.pop();
            
            for (auto p : dir)
            {
                pair<int, int> n = f + p;
                if (!chk(n.first, n.second)) continue;
                
                if (cnt_visit[!toggle][n.first][n.second] == -1) continue;
                
                if (!visited[n.first][n.second])
                {
                    visited[n.first][n.second] = true;
                    points.push(n);
                    cnt_visit[!toggle][n.first][n.second] = 0;
                }
                cnt_visit[!toggle][n.first][n.second] += cnt_visit[toggle][f.first][f.second];
                cnt_visit[!toggle][n.first][n.second] %= 1000000007;
            }
        }
        toggle ^= true;
    }
    
    return cnt_visit[0][1][6];
}

int solution(int T) {
    int answer = -1;
    
    // 알고리즘
    if (T%2 == 0) answer = simulation(T);
    else return 0;
    return answer;
}