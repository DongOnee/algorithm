#include <iostream>
using namespace std;
#define MAXN 1000001

int n, arr[MAXN];
long long answer;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("1859_input.txt", "r", stdin);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        cin >> n;
        answer = 0;
        for (int i = 0; i < n; i++) cin >> arr[i];

        int mx = arr[n-1];
        for (int idx = n-2; 0<=idx; idx--)
        {
            if (arr[idx] > mx) mx = arr[idx];
            answer += (mx - arr[idx]);
        }

        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}
