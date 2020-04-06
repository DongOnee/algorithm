/**
 * 2020.04.06 20:33 ~ 20:44
 */
#include <iostream>
using namespace std;

int n, board[128][128], cnt[2];

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
        cnt[board[x][y]]++;
    }
    else
    {
        run(x, y, len/2);
        run(x+len/2, y, len/2);
        run(x, y+len/2, len/2);
        run(x+len/2, y+len/2, len/2);
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

    cout << cnt[0] << '\n' << cnt[1] << '\n';

    return 0;
}
