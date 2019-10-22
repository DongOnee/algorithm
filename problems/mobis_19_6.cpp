#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define MAX_N 500000

void update(vector<string>& arr, int idx)
{
    while (idx > 0)
    {
        if (arr[idx] <= arr[idx/2]) break;
        arr[idx/2] = arr[idx];
        idx <<=1;
    }
}

int query(vector<string>& arr, int en)
{
    string ret = arr[en];
    int idx = en;
    while (0<en)
    {
        if (ret < arr[en])
        {
            ret = arr[en];
            idx = en;
        }
        en -= en&(-en);
    }
    return idx;
}

string solution(vector<string> arr, int k)
{
    string answer = "";
    vector<string> seg(2*MAX_N);
    int idx = MAX_N;
    for (auto x : arr)
    {
        seg[idx] = x;
        update(seg, idx);
        idx++;
    }
    while (k--)
    {
        int maxidx = query(seg, MAX_N + arr.size() -1 - k);
        answer += seg[maxidx];
        seg[maxidx] = "";
        update(seg, maxidx);
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    string ret = solution({"z", "b", "g", "a", "j"} , 3);
    cout << ret << '\n';
    return 0;
}