/**
 * 2020.04.06 20:59 ~ 21:04
 */
#include <iostream>
using namespace std;

int matrix[100][100][2];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            cin >> matrix[i][j][0];

    cin >> m >> k;
    for (int i=0; i<m; i++)
        for (int j=0; j<k; j++)
            cin >> matrix[i][j][1];

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<k; j++)
        {
            int ret = 0;
            for (int l = 0; l < m; l++)
                ret += matrix[i][l][0] * matrix[l][j][1];
            cout << ret << ' ';
        }
        cout << '\n';
    }

    return 0;
}
