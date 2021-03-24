#include <iostream>
#include <queue>
#include <utility>

using namespace std;

const int MAXA = 8;
const int MAXN = 10;
const int MAXM = 100;
const int dirs[5][2] = {{0,0},{-1,0},{0,1},{1,0},{0,-1}};

vector<int> board[MAXN][MAXN];
int perfomance[MAXA];
int bc_cnt, ans;
int movement[MAXM][2];
int move_cnt;
int cust[2][2];


bool chk(int r, int c) {return 0<=r&&r<10&&0<=c&&c<10;}


void bfs(int r, int c, int idx, int k) 
{
    queue<pair<int,int>> qu;
    qu.emplace(r,c);
    board[r][c].emplace_back(idx);

    while (k--) {
        long sz = qu.size();
        while (sz--) {
            pair<int,int> f = qu.front(); qu.pop();

            for (int d = 1; d < 5; ++d) {
                int nr = f.first+dirs[d][0];
                int nc = f.second+dirs[d][1];

                if (!chk(nr,nc)) continue;
                if (!board[nr][nc].empty()) 
                    if (board[nr][nc].back() == idx) continue;

                board[nr][nc].emplace_back(idx);
                qu.emplace(nr,nc);
            }
        }
    }
}


void init()
{
    for (int r = 0; r < 10; ++r) for (int c = 0; c < 10; ++c) board[r][c].clear();
    ans = 0;
    cust[0][0] = cust[0][1] = 0;
    cust[1][0] = cust[1][1] = 9;

    cin >> move_cnt >> bc_cnt;
    for (int person = 0; person < 2; ++person) {
        for (int i = 0; i < move_cnt; ++i) {
            cin >> movement[i][person];
        }
    }

    for (int i = 0, r, c, k, p; i < bc_cnt; ++i) {
        cin >> r >> c >> k >> p;
        perfomance[i] = p;
        bfs(c-1, r-1, i, k);
    }
}


void calc()
{
    int ar = cust[0][0];
    int ac = cust[0][1];
    int br = cust[1][0];
    int bc = cust[1][1];

    int mx = 0;

    int sza = board[ar][ac].size();
    int szb = board[br][bc].size();

    for (int ia = 0; ia <= sza; ++ia) {
        int idxA =  (ia==sza?-1:board[ar][ac][ia]);
        int pa =    (ia==sza?0:perfomance[idxA]);
        for (int ib = 0; ib <= szb; ++ib) {
            int idxB =  (ib==szb?-1:board[br][bc][ib]);
            int pb =    (ib==szb?0:perfomance[idxB]);
            if (idxA == idxB) mx = max(mx,pa);
            else mx = max(mx,pa+pb);
        }
    }


    ans += mx;
    // cout << "ans : " << ans << '\n';
}


void run() 
{
    // 시작위치
    calc();

    for (int step = 0; step < move_cnt; ++step) {
        // 이동 
        for (int person = 0; person < 2; ++person) {
            cust[person][0] += dirs[movement[step][person]][0];
            cust[person][1] += dirs[movement[step][person]][1];
        }
        // 계산
        calc();
    }
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	// freopen("~/Download/sample_input (1).txt", "r", stdin);
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        run();

        cout << '#' << test_case << ' ' << ans << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
