#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first + b.first, a.second + b.second); }
pii operator-(const pii& a, const pii& b) { return make_pair(a.first - b.first, a.second - b.second); }

const int BOARDMAX = 20;
const pii dirs[4] = { {-1,0},{1,0},{0,-1},{0,1}};

enum DIR { UP, DOWN, LEFT, RIGHT };

int boardSize, ans;
int board[BOARDMAX][BOARDMAX];

void printBoard() 
{
   for (int row = 0; row < boardSize; ++row)
   {
       for (int col = 0; col < boardSize; ++col)
       {
           cout << board[row][col] << " ";

       }
       cout << "\n";
   }
   cout << "\n";
}

void checkAns() 
{
   for (int row = 0; row < boardSize; ++row)
       for (int col = 0; col < boardSize; ++col)
           ans = max(ans, board[row][col]);
}

void line_slide(pii cur, int sli)
{
    pii tail;

    if (sli == 0 || sli == 2) tail = cur;
    else if (sli == 3) tail = {cur.first, cur.second + boardSize -1};
    else tail = {cur.first + boardSize - 1, cur.second};

    // cout << "{" << tail.first << ", " << tail.second << "}";

    pii sr = tail;
    for (int i = 0; i < boardSize; ++i)
    {
        if (sr == tail || 0 == board[sr.first][sr.second]) 
        {
            sr = sr - dirs[sli];
            continue;
        }

        int val = board[sr.first][sr.second];
        board[sr.first][sr.second] = 0;

        while(1)
        {
            if (board[tail.first][tail.second] == 0)
            {
                board[tail.first][tail.second] = val;
            }
            else if (board[tail.first][tail.second] == val)
            {
                board[tail.first][tail.second] = 2 * val;
                tail = tail - dirs[sli];
            }
            else
            {
                tail = tail - dirs[sli];
                continue;
            }
            break;
        }
        sr = sr - dirs[sli];
    }
}

void turn(int sli)
{
    pii plusPii, curPii = {0, 0};

    if (sli < 2) plusPii = dirs[RIGHT];
    else plusPii = dirs[DOWN];

    for (int i = 0; i < boardSize; ++i)
    {
        line_slide(curPii, sli);
        curPii = curPii + plusPii;
    }

}

void dfs(int cnt)
{
    // printBoard();
    int board_copy[BOARDMAX][BOARDMAX];

    if (cnt == 5) {
        checkAns();
        return;
    }

    for (int row = 0; row < boardSize; ++row)
        for (int col = 0; col < boardSize; ++col)
            board_copy[row][col] = board[row][col];

    for (int d = 0; d < 4; ++d) 
    {
        turn(d);

        bool isModify = false;
        for (int row = 0; row < boardSize; ++row)
            for (int col = 0; col < boardSize; ++col)
                if (board_copy[row][col] != board[row][col])
                {
                    isModify = true;
                    row = boardSize;
                    col = boardSize;
                }

        if (false == isModify) {
            checkAns();
            continue;
        }

        dfs(cnt+1);
        for (int row = 0; row < boardSize; ++row)
            for (int col = 0; col < boardSize; ++col)
                board[row][col] = board_copy[row][col];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> boardSize;
    for (int row = 0; row < boardSize; ++row)
        for (int col = 0; col < boardSize; ++col)
            cin >> board[row][col];

    dfs(0);

    cout << ans << '\n';
    return 0;
}
