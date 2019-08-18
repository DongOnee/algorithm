// you can use includes, for example:
// #include <algorithm>
#include <vector>
#include <string>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<string> &T, vector<string> &R) {
    // write your code in C++14 (g++ 6.2.0)
    int n = T.size();
    int cnt = 0;
    vector<bool> ans(n, true);
    for (int i=0; i<n; i++)
    {
        int group = 0;
        const char *j = T[i].c_str();
        int len = T[i].size();
        for (int k=0; k<len; k++)
        {
            if ('0' <= j[k] && j[k] <= '9')
            {
                group *= 10;
                group += j[k] - '0';
                continue;
            }
        }
        if (R[i] == "OK") ans[group-1] = (ans[group-1] && true);
        else ans[group-1] = (ans[group-1] && false);
        cnt = (cnt > group ? cnt : group);
    }
    int ret = 0;
    for (int i=0; i<cnt; i++) if (ans[i]) ret++;
    return (ret*100)/cnt;
}