#include <iostream>

using namespace std;

const int MAXR = 13;
const int MAXC = 20;

int row_count, col_count, k, ans;
bool board[MAXR][MAXC];

void init()
{
    cin >> row_count >> col_count >> k;
    for (int r = 0; r < row_count; ++r) for (int c = 0; c < col_count; ++c) cin >> board[r][c];
    ans = row_count;
}

bool calc()
{
    for (int c = 0; c < col_count; ++c) {
        int cnt = 1;
        bool cur = board[0][c];
        for (int r = 1; r < row_count; ++r) {
            if (board[r][c] == cur) {
                if (++cnt >= k) break;
            }
            else {
                cur = board[r][c];
                cnt = 1;
            }
        }
        
        if (cnt < k) return false;
    }

    return true;
}

void dfs(int st, int cnt)
{
    if (ans < cnt) return;
    if (calc()) {
        ans = cnt;
        return;
    }


    for (; st < row_count; ++st) {
        bool tmp[MAXC];
        for (int c = 0; c < col_count; ++c) tmp[c] = board[st][c];

        for (int i = 0; i < 2; ++i) {
            for (int c = 0; c < col_count; ++c) board[st][c] = i;
            
            dfs(st+1, cnt+1);
        }
        for (int c = 0; c < col_count; ++c) board[st][c] = tmp[c];
    }
}

void run()
{
    dfs(0,0);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("/Users/macbook/Downloads/sample_input.txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        run();

        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
