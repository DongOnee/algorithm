#include <iostream>
#include <vector>

using namespace std;

#define MAXN 49

int n;
int cmdCount;
int ConvertRowCol2index[MAXN][MAXN];
int dirs[5][2] = { {0,0}, {-1,0}, {1,0}, {0,-1}, {0,1} };
int nextDir[5] = {0, 4, 3, 1, 2};
vector<int> board;
long long ansCnt[4];

void init()
{
    cin >> n >> cmdCount;
    int cur[2] = {0, 0};
    int d = 4;
    for (int i = n * n, j = 2 * n, k = j / 2; 0 < i;) {
        ConvertRowCol2index[cur[0]][cur[1]] = --i;
        if (--k == 0) {
            d = nextDir[d];
            k = --j / 2;
        }
        cur[0] += dirs[d][0];
        cur[1] += dirs[d][1];
    }

    board.resize(n * n);
    for (int i = 0 ; i < n ; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int num; cin >> num;
            board[ConvertRowCol2index[i][j]] = num;
        }
    }
}

void reRange()
{
    vector<int> newBoard(1,0);
    int i, j;
    for (i = 1, j = 2; j < board.size() && newBoard.size() < n * n; ++j)
    {
        if (board[i] != board[j])
        {
            newBoard.push_back(j - i);
            newBoard.push_back(board[i]);
            i = j;
        }
    }
    if (newBoard.size() < n * n && board.size() > 1)
    {
        newBoard.push_back(j - i);
        newBoard.push_back(board[i]);
    }

    swap(board, newBoard);
}

void run()
{
    int centerPosition[2] = { n / 2, n / 2};
    while (cmdCount--) {
        int di, si; cin >> di >> si;

        // 공굴러가유
        for (int i = 1; i <= si; ++i)
        {
            int nr = centerPosition[0] + dirs[di][0] * i;
            int nc = centerPosition[1] + dirs[di][1] * i;
            int index = ConvertRowCol2index[nr][nc];    
        
            if (index < board.size())
                board[index] = 0;
        }

        // 4개 이상이면 터지기
        int i, s, cnt;
        bool flag = false;
        do
        {
            // 구슬 이동
            vector<int> newBoard(1,0);
            for (auto num : board)
            {
                if (num == 0) continue;
                newBoard.push_back(num);
            }

            flag = false;
            for (i = 1, s = 2; s < newBoard.size(); ++s)
            {
                if (newBoard[i] == newBoard[s]) continue;
                if (s - i >= 4)
                {
                    while (i < s)
                    {
                        if (newBoard[i] <= 3)
                            ++ansCnt[newBoard[i]];
                        newBoard[i++] = 0;
                    }
                    flag = true;
                }
                else
                {
                    i = s;
                }
            }
            if (s - i >= 4)
            {
                while (i < s)
                {
                    if (newBoard[i] <= 3)
                        ++ansCnt[newBoard[i]];
                    newBoard[i++] = 0;
                }
                flag = true;
            }

            swap(board, newBoard);
        }
        while(flag);

        reRange();
    }
}

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();

    run();

    cout << ansCnt[1] + 2 * ansCnt[2] + 3 * ansCnt[3] << '\n';

    return 0;
}