#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int,int> pii;

int board[9][9];
vector<pii> blank;

vector<int> chk(int row, int col)
{
    bool can_replace[10] = {true, true, true, true, true, true, true, true, true, true};

    for (int i=0; i<9; i++)
    {
        can_replace[board[row][i]] = false;
        can_replace[board[i][col]] = false;
    }

    for (int i=0; i<3; i++) for (int j=0; j<3; j++) can_replace[board[(row/3)*3+i][(col/3)*3+j]] = false;

    vector<int> ret;
    for (int i=1; i<10; i++) if (can_replace[i]) ret.push_back(i);

    return ret;
}

bool run(int idx)
{
    if (idx == blank.size()) return true;
    else
    {
        int row = blank[idx].first, col = blank[idx].second;
        vector<int> prob = chk(row, col);
        for (auto x : prob)
        {
            board[row][col] = x;
            if (run(idx+1)) return true;
        }
        board[row][col] = 0;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<9; i++) for (int j=0; j<9; j++) 
    {
        scanf("%d", board[i]+j);
        if (board[i][j] == 0) blank.push_back({i, j});
    }

    run(0);

    for (int i=0; i<9; i++)
    {
        for (int j=0; j<9; j++) printf("%d ", board[i][j]);
        printf("\n");
    }

    return 0;
}
