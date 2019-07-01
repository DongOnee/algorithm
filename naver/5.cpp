// you can use includes, for example:
#include <algorithm>
#include <vector>
using namespace std;

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> ans;
    for (int i=0; i<n; i++)
    {
        for (int j=i; j<n; j++) ans.push_back(A[i] + A[j] + (j-i));
    }
    sort(ans.rbegin(), ans.rend());
    return *ans.begin();
}