#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
pii operator+(const pii &a, const pii &b) { return {a.first+b.first, a.second+b.second }; }
pii operator-(const pii &a, const pii &b) { return {a.first-b.first, a.second-b.second }; }
void operator+=(pii &a, const pii&b) { a.first+=b.first; a.second+=b.second; }
void operator-=(pii &a, const pii&b) { a.first-=b.first; a.second-=b.second; }

int n, m;
pii answer;

pii func(int input)
{
    pii ans = {0, 0};

    while (input && input % 2 == 0)
    {
        ans.first++;
        input /= 2;
    }

    while (input && input % 5 == 0)
    {
        ans.second++;
        input /= 5;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i=0; i < m && i < n-m; i++)
    {
        answer = answer + func(n-i);
        answer = answer - func(i+1);
    }

    printf("%d\n", min(answer.first, answer.second));

    return 0;
}
