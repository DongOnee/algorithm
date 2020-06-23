/**
 * 2020.06.23 23:41 ~ 23:56
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<string> firstNames;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    firstNames.resize(n);
    for (int i=0; i<n; ++i)
        cin >> firstNames[i];

    sort(firstNames.begin(), firstNames.end());

    int cnt = 1;
    bool flag = true;
    char comp = firstNames[0][0];
    for (int i=1; i<n; i++)
    {
        if (comp == firstNames[i][0]) cnt++;
        else
        {
            if (cnt > 4)
            {
                cout << comp;
                flag = false;
            }
            comp = firstNames[i][0];
            cnt = 1;
        }
    }

    if (cnt > 4) cout << comp;
    else if (flag) cout << "PREDAJA\n";


    return 0;
}
