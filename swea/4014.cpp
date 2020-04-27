/**
 * 2020.04.27. 19:28 ~ 20:22
 */
#include <iostream>

using namespace std;

int board[21][21], n, x;


bool calc_row(int i)
{
    int ret = 1;
    for (int j = 1; j < n; ++j)
    {
        if (board[i][j-1]+1 < board[i][j]) return false;
        else if (board[i][j-1]+1 == board[i][j])
        {
            ret -= x;
            if (ret < 0) return false;
            ret = 1;
        }
        else if (board[i][j-1] == board[i][j]) ret++;
        else if (board[i][j-1] == board[i][j]+1)
        {
            if (ret < 0) return false;
            ret = 1-x;
        }
        else return false;
    }
    return ret>=0;
}

bool calc_col(int j)
{
    int ret = 1;
    for (int i = 1; i < n; ++i)
    {
        if (board[i-1][j]+1 < board[i][j]) return false;
        else if (board[i-1][j]+1 == board[i][j])
        {
            ret -= x;
            if (ret < 0) return false;
            ret = 1;
        }
        else if (board[i-1][j] == board[i][j]) ret++;
        else if (board[i-1][j] == board[i][j]+1)
        {
            if (ret < 0) return false;
            ret = 1-x;
        }
        else return false;
    }
    return ret>=0;
}


int sol()
{
    int ret = 0;

    // i 값 증가
    for (int i=0; i<n; i++)
    {
        ret += calc_row(i);
    }

    // j 값 증가
    for (int j=0; j<n; j++)
    {
        ret += calc_col(j);
    }

    return ret;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for (int tc=1; tc <= t; tc++)
    {
        cin >> n >> x;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++) cin >> board[i][j];
        
        cout << '#' << tc << ' ' << sol() << '\n';
    }
    return 0;
}
