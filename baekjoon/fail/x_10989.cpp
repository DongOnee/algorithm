/**
 * 18.12.21. 금요일
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    vector<int> v;
    while (N--)
    {
        int input;
        scanf("%d", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it<v.end(); it++) printf("%d\n", *it);
    return 0;
}
