#include <iostream>
using namespace std;

int answer;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("2072_input.txt", "r", stdin);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        answer = 0;
        for (int i=0, a; i < 10; i++)
        {
            cin >> a;
            if (a%2) answer += a;
        }

        cout << '#' << test_case << ' ' << answer << '\n';
    }
    return 0;
}