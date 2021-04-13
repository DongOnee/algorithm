#include<iostream>
#include <string.h>

using namespace std;

const int dirs[4][2] = {{1,-1},{1,1},{-1,1},{-1,-1}};
const int MAXN = 20;
const int MAXM = 100;

int board[MAXN][MAXN];
int board_size, ans;
bool visited[MAXM + 1];

bool chk(int r, int c) { return 0<=r&&r<board_size&&0<=c&&c<board_size; }

void init()
{
    ans = -1;
    cin >> board_size;
    for (int r = 0; r < board_size; ++r) for (int c = 0; c < board_size; ++c) cin >> board[r][c];
}

void desert(int r, int c, int a1, int a2)
{
    memset(visited, 0, sizeof(visited));
    int d = 0;

    for (int k = 0; k < 2; ++k) {
        for (int i = 0; i < a1; ++i) {
            if(visited[board[r][c]]) return ;
            visited[board[r][c]] = true;
            r += dirs[d][0], c += dirs[d][1];
        }
        ++d;

        for (int i = 0; i < a2; ++i) {
            if(visited[board[r][c]]) return ;
            visited[board[r][c]] = true;
            r += dirs[d][0], c += dirs[d][1];
        }
        ++d;
    }

    ans = max(ans, 2*(a1+a2));
}

void run()
{
    for (int r = 0; r < board_size - 2; ++r) {
        for (int c = 1; c < board_size -1; ++c) {
            int a1, a2;
            for (a1 = 1;  a1 <= c; ++a1) {
                // for (a2 = 1; a1 + a2 < board_size && ans < 2*(a1 + a2); ++a2) {
                for (a2 = 1; 
                        c + a2 < board_size 
                        && r + a1 + a2 < board_size ; ++a2) {
                    if (ans < 2*(a1+a2)) desert(r, c, a1, a2);
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("/Users/macbook/Downloads/input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        run();

        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;
}
