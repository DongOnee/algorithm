#include <iostream>
#include <string.h>

using namespace std;

typedef
struct {
    int r, c;
    int s;  // 속력
    int d;  // 방향 
    int z;  // 크기
}shark_info;

const int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
const int convd[4] = {3, 1, 0, 2};
const int MAXM = 10000;
const int MAXR = 100;

int board[MAXR][MAXR];
int bw, bh, ans;
shark_info sharks[MAXM+1];
int shark_count;

void init()
{
    cin >> bh >> bw >> shark_count;
    for (int i = 1; i <= shark_count; ++i) {
        int r, c, s, d, z; cin >> r >> c >> s >> d >> z;
        sharks[i] = {r-1, c-1, s, convd[d-1], z};
        board[r-1][c-1] = i;
    }
}

void run()
{
    for (int search_c = 0; search_c < bw; ++search_c) {
        for (int s_idx = 1; s_idx <= shark_count; ++s_idx) {
            if (sharks[s_idx].d == -1) continue;
            board[sharks[s_idx].r][sharks[s_idx].c] = s_idx;
        }

        for (int search_r = 0; search_r < bh; ++search_r) {
            int idx = board[search_r][search_c];
            if (idx > 0) {
                ans += sharks[idx].z;
                sharks[idx].d = -1;
                // cout << "idx : " << idx << " ans : "  << ans << endl;
                break;
            }
        }

        memset(board, 0, sizeof(board));
        for (int s_idx = 1; s_idx <= shark_count; ++s_idx) {
            shark_info& s = sharks[s_idx];
            if (s.d == -1) continue;
            int t_mov = s.s;

            t_mov %= ( (s.d%2?bh:bw) -1 ) * 2 ;
            s.r = ((s.r + dirs[s.d][0] * t_mov)) % ((bh-1) * 2);
            s.c = ((s.c + dirs[s.d][1] * t_mov)) % ((bw-1) * 2);

            if (s.r < 0) {
                s.r = -s.r;
                s.d = (s.d+2)%4;
            }
            if (s.c < 0) {
                s.c = -s.c;
                s.d = (s.d+2)%4;
            }
            if (bh <= s.r) {
                s.r = 2 * (bh - 1) - s.r;
                s.d = (s.d+2)%4;
            }
            if (bw <= s.c) {
                s.c = 2 * (bw - 1) - s.c;
                s.d = (s.d+2)%4;
            }

            if (board[s.r][s.c] > 0) {
                shark_info& ps = sharks[board[s.r][s.c]];
                if (ps.z < s.z) {
                    ps.d = -1;
                    board[s.r][s.c] = s_idx;
                }
                else {
                    s.d = -1;
                }
            }
            else {
                board[s.r][s.c] = s_idx;
            }
        }

    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    run();
    
    cout << ans << '\n';

    return 0;
}
