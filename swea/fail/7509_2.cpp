#include <cstdio>
#include <vector>
using namespace std;

int h, w, q;
long long map[10000][3];
// long long mmap[10000][3][10000][3];
long long mmmap[100000000][9];

int dir[4][2] = { {1, 0}, {0, 1}, {-1, 0}, {0, -1} };

bool chk(int row, int col) { return 0<=row&&row<h&&0<=col&&col<w; }

int main(int argc, char** argv)
{
	freopen("input_7509.txt", "r", stdin);
	int T; scanf("%d", &T);
	for(int test_case = 1; test_case <= T; ++test_case)
	{
        // vector<pair<pair<int, int>, pair<int, int>>> empty_vt; swap(empty_vt, sibal);
        long long ans = 0;
        scanf("%d%d%d", &h, &w, &q);

        for (int i=0; i<h; i++) for (int j=0; j<w; j++)
        { 
            scanf("%lld", map[i]+j);
            // for (int ii=0; ii<h; ii++) for (int jj=0; jj<w; jj++) mmap[i][j][ii][jj] = 0x7fffffffffffffffLL;
            for (int ii=0; ii<h; ii++) for (int jj=0; jj<w; jj++) mmmap[i*h+ii][j*w+jj] = 0x7fffffffffffffffLL;
        }

        for (int i=0; i<h; i++) for (int j=0; j<w; j++)
        {
            for (int k=0; k<4; k++)
            {
                int next_row = i + dir[k][0];
                int next_col = j + dir[k][1];
                if (!chk(next_row, next_col)) continue;
                // mmap[i][j][next_row][next_col] = map[i][j] + map[next_row][next_col];
                mmmap[i*h+next_row][j*w+next_col] = map[i][j] + map[next_row][next_col];
            }
            mmmap[i*h+i][j*w+j] = map[i][j];
            // mmap[i][j][i][j] = map[i][j];
        }

        for (int iii=0; iii<h; iii++) for (int jjj=0; jjj<w; jjj++)
        {
            for (int i=0; i<h; i++) for (int j=0; j<w; j++)
            {
                for (int ii=0; ii<h; ii++) for (int jj=0; jj<w; jj++)
                {
                    // if (mmap[i][j][iii][jjj] != 0x7fffffffffffffffLL && mmap[iii][jjj][ii][jj] != 0x7fffffffffffffffLL)
                    //     mmap[i][j][ii][jj] = min( mmap[i][j][ii][jj], mmap[i][j][iii][jjj] + mmap[iii][jjj][ii][jj] - map[iii][jjj]);
                        
                    if (mmmap[i*h+iii][j*w+jjj] != 0x7fffffffffffffffLL && mmmap[iii*h+ii][jjj*w+jj] != 0x7fffffffffffffffLL)
                        mmmap[i*h+ii][j*w+jj] = min( mmmap[i*h+ii][j*w+jj], mmmap[i*h+iii][j*w+jjj] + mmmap[iii*h+ii][jjj*w+jj] - map[iii][jjj]);
                }
            }
        }

        for (int i=0, a, b, c, d; i<q; i++)
        {
            scanf("%d%d%d%d", &a, &b, &c, &d);

            // ans += mmap[a][b][c][d];
            ans += mmmap[a*h+c][b*w+d];
        }

        printf("#%d %lld\n", test_case, ans);
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}