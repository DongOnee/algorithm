// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    if (A.size() == 1) return -2;
    sort(A.begin(), A.end());
    vector<int>::iterator itr_begin = A.begin();
    vector<int>::iterator itr_next;
    for (itr_next = A.begin(); itr_next != A.end(); itr_next++)
    {
        if (*itr_next == *itr_begin) continue;
        else break;
    }

    if (itr_next == A.end()) return 0;

    int ans = 100000001;

    while (itr_next != A.end())
    {
        if (itr_next - itr_begin != 1) return 0;
        ans = (ans < *itr_next - *itr_begin ? ans : *itr_next - *itr_begin);
        itr_begin = itr_next;
        while (itr_next != A.end() && *itr_next == *itr_begin) itr_next++;
    }
    
    return (ans == 100000001 ? -1 : ans);
}