#include <iostream>

using namespace std;

bool board[10][10];
int ans = 100;
int paperCount[5] = {5, 5, 5, 5, 5};

bool chk(int row, int col, int wid) { return row + wid < 10 && col + wid < 10; }
bool chk1(int row, int col, int wid) 
{ 
    for (int i = 0; i < wid; ++i)
        for (int j = 0; j < wid; ++j)
            if (!board[i + row][j + col])
                return false;
    return true;
}

void dfs(int count)
{
    if (ans < count) return;
    bool boardCpy[10][10];
    for (int row = 0; row < 10; ++row)
        for (int col = 0; col < 10; ++col)
            boardCpy[row][col] = board[row][col];

    bool isRun = false;
    for (int sum = 0; sum < 19; ++sum)
    {
        int col = (sum < 10? sum : 9);
        for (int row = sum - col; 0 <= col && row < 10; ++row, --col)
        {
            if (board[row][col])
            {

                for (int wi = 4; 0 <= wi; --wi)
                {
                    if (!chk(row,col,wi)) continue;
                    if (!chk1(row,col,wi + 1)) continue;
                    if (paperCount[wi] == 0) continue;

                    for (int r = 0; r < wi + 1; ++r)
                        for (int c = 0; c < wi + 1; ++c)
                            board[row + r][col + c] = 0;

                    isRun = true;
                    --paperCount[wi];
                    dfs(count +1);
        
                    for (int r = 0; r < wi + 1; ++r)
                        for (int c = 0; c < wi + 1; ++c)
                            board[row + r][col + c] = boardCpy[row + r][col + c];
                    ++paperCount[wi];

                }

                return;
            }

        }
    }

    ans = min(ans, count);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int row = 0; row < 10; ++row)
        for (int col = 0; col < 10; ++col)
            cin >> board[row][col];


    dfs(0);
    cout << (ans == 100? -1: ans) << '\n';

    return 0;
}
