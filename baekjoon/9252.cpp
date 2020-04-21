/**
 * 2020.04.16. 23:30 ~ 2020.04.21. 
 * 결국 아무것도 모른채 그냥 코드 배끼는 수준으로 진행 하였다.
 * https://meylady.tistory.com/34 여기에 굉장히 정리가 잘 되어 있었다.
 * 일단 LCS 에 대한 개념부터 다시 배워야 될거 같다.
 * 이 문제는 스타 표시를 해두었기 때문에 다시 한번 보며 이해해야겠다.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string a, b;
vector<int> idx;
string ans = "";
int lcs[1002][1002], ans2;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b;
    a = " " + a;
    b = " " + b;

    int i, j;

    for (i=1; i<a.size(); i++)
    {
        for (j=1; j<b.size(); j++)
        {
            if (a[i] == b[j])
                lcs[i][j] = lcs[i-1][j-1] +1;
            else
            {
                if (lcs[i-1][j] < lcs[i][j-1]) lcs[i][j] = lcs[i][j-1];
                else lcs[i][j] = lcs[i-1][j];
            }

            ans2 = max(ans2, lcs[i][j]);
        }
    }
    cout << ans2 << '\n';

    i--;
    j--;
    while (i>0 & j>0)
    {
        if (lcs[i][j] == lcs[i-1][j]) i--;
        else if (lcs[i][j] == lcs[i][j-1]) j--;
        else
        {
            ans = a[i] + ans;
            i--; j--;
        }
        
    }

    cout << ans << '\n';

    return 0;
}
