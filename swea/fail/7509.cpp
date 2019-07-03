#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int h, w, q;
int map[10001][4];
vector<pair<pair<int, int>, pair<int, int>>> problem;

int dir[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<row&&row<=h&&0<col&&col<=w; }
bool chk(pair<int, int> point) { return 0<point.first&&point.first<=h&&0<point.second&&point.second<=w; }


int main(int argc, char** argv)
{
	int T;
	// freopen("input_7509.txt", "r", stdin);
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        problem.clear();
        int ans = 0;
        scanf("%d%d%d", &h, &w, &q);
        for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) scanf("%d", map[i]+j);
        for (int i=0, a, b, c, d; i<q; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);
            problem.push_back({{a, b}, {c, d}});
        }

        for (auto x : problem)
        {
            pair<int, int> start_point = x.first, end_point = x.second;
            priority_queue<pair<int, pair<int, int>>> pq;
            pq.push({-map[start_point.first][start_point.second], start_point});
            bool visited[h+1][w+1];
            for (int i=1; i<=h; i++) for (int j=1; j<=w; j++) visited[i][j] = false;
            while (!pq.empty())
            {
                pair<int, pair<int, int>> tp = pq.top(); pq.pop();
                if (tp.second == end_point)
                {
                    ans -= tp.first;
                    // printf("(%d %d) ~ (%d %d) : %d\n", start_point.first, start_point.second, end_point.first, end_point.second, ans);
                    break;
                }
                if (visited[tp.second.first][tp.second.second]) continue;
                visited[tp.second.first][tp.second.second] = true;
                for (int i=0; i<4; i++)
                {
                    int _next_row = tp.second.first + dir[i][0];
                    int _next_col = tp.second.second + dir[i][1];
                    if (!chk(_next_row, _next_col)) continue;
                    pq.push({tp.first-map[_next_row][_next_col], {_next_row, _next_col}});
                }
            }
        }

        printf("#%d %d\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}