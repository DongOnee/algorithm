/**
 * 2020.04.13 20:19 ~ 20:43
 * 참고 자료 LIS 최장 증가 수열 https://jason9319.tistory.com/113
 * 세그먼트 트리, 이분 탐색 이용 해서 LIS 의 최대 길이를 구할 수 있지만
 * 최대 일때의 요소를 구할 수는 없다.
 */
#include <iostream>
#include <stack>

using namespace std;

int n, arr[1001], cnt[1001], dp[1001];

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);   

    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> arr[i];

    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<i; j++)
        {
            if (arr[j] < arr[i] && cnt[j] +1 > cnt[i])
            {
                cnt[i] = cnt[j] +1;
                dp[i] = j;
            }
        }
    }

    int ansCnt = 0, ansLoc = 0;
    for (int i=1; i<=n; i++)
    {
        // cout << arr[i] << ' ' << cnt[i] << ' ' << dp[i] << endl;
        if (ansCnt < cnt[i])
        {
            ansLoc = i;
            ansCnt = cnt[i];
        }
    }

    cout << ansCnt << '\n';
    
    stack<int> st;
    while (ansLoc)
    {
        st.push(arr[ansLoc]);
        ansLoc = dp[ansLoc];
    }

    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }
    
    return 0;
}
