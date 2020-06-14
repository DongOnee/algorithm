/**
 * 2020.06.14. 13:05 ~
 * string 을 다루는 것에 대해서 .. .아니다 별루 배운게 없다
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> commands;

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    for (int i=0; i<n; i++)
    {
        commands.emplace_back();
        cin >> commands[i];
    }

    for (int i=0; i<commands[0].size(); i++)
    {
        for (int j=1; j<n; j++)
        {
            if (commands[0][i] != commands[j][i])
            {
                commands[0][i] = '?';
                j = n;
                continue;
            }
        }
    }

    cout << commands[0] << '\n';

    return 0;
}
