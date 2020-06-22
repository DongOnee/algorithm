/**
 * 2020.06.23 00:22 ~ 00:48
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m, w=0;
vector<string> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i=0; i<n; ++i) 
    {
        board.emplace_back();
        cin >> board[i];
    }
    
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            for (int k = w; ; k++)
            {
                if ( i + k >= n || j + k >= m ) break;
                char& ang = board[i+k][j+k];
                if ( ang == board[i][j]
                        && ang == board[i+k][j]
                        && ang == board[i][j+k])
                    w = k;
            }
        }
    }
    w++;
    cout << w * w<< '\n';

    return 0;
}
