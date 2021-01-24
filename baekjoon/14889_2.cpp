#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 20;

int people_count;
int arr[MAXN];
int abilities[MAXN][MAXN];
int ans = 987654321;


void dfs()
{
    int ab = 0;
    for (int i = 0; i < people_count; ++i)
        for (int j = 0; j < people_count; ++j)
            if (arr[i] == arr[j]) {
                ab += (arr[i] == 1?-1:1) * abilities[i][j];
            }

    ans = min(ans, abs(ab));
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> people_count;
    for (int row = 0; row < people_count; ++row)
        for (int col = 0; col < people_count; ++col)
            cin >> abilities[row][col];

    for (int i = 0; i < people_count / 2; ++i) {
        arr[i] = 0;
        arr[i + people_count / 2] = 1;
    }

    do {
        dfs();
    } while(next_permutation(arr, arr+people_count));

    cout << ans << '\n';

    return 0;
}
