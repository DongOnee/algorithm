#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 1000000

typedef pair<int, int> pii;

long long answer;
int arr[MAXN+1], n;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    for (int test_case = 1; test_case <= t; test_case++)
    {
        cin >> n;
        vector<pii> order;
        answer = 0;
        
        for (int i = 0; i<n; i++)
        {
            cin >> arr[i];
            order.push_back({arr[i], i});
        }

        sort(order.rbegin(), order.rend());

        int idx = 0, val = 0;

        for (int i=0; i<n; i++)
        {
            if (order[i].second <= idx) continue;

            int cnt = 0;
            while (idx < order[i].second)
            {
                answer -= arr[idx++];
                cnt++;
            }
            answer += (long long) (order[i].first * cnt);
            idx++;
        }

        cout << '#' << test_case << ' '<< answer << '\n';
    }
    return 0;
}
