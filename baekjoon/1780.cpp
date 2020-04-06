/**
 * 2020.04.06 20:45 ~ 20:48
 */
#include <iostream>
using namespace std;

int n, board[2187][2187], cnt[3];

bool fullsearch(int x, int y, int len)
{
    for (int i=0; i<len; ++i)
        for (int j = 0; j < len; j++)
            if (board[x+i][y+j] != board[x][y])
                return false;
    return true;
}

void run(int x, int y, int len)
{
    if (fullsearch(x, y, len))
    {
        cnt[board[x][y]+1]++;
    }
    else
    {
        run(x, y, len/3);
        run(x+len/3, y, len/3);
        run(x+2*len/3, y, len/3);
        run(x, y+len/3, len/3);
        run(x+len/3, y+len/3, len/3);
        run(x+2*len/3, y+len/3, len/3);
        run(x, y+2*len/3, len/3);
        run(x+len/3, y+2*len/3, len/3);
        run(x+2*len/3, y+2*len/3, len/3);
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> board[i][j];

    run(0, 0, n);

    cout << cnt[0] << '\n' << cnt[1] << '\n' << cnt[2] << '\n';

    return 0;
}
