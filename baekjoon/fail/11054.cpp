#include <cstdio>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, arr[1000], foreward[1000], backward[1000];
vector<pii> sk;
// vector<int> sk;

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", arr+i);

    printf("test\n");

    sk.push_back({0, -1});
    for (int i=0, cnt=0; i<n; i++)
    {
        if (sk.back().first < arr[i]) sk.push_back({arr[i], i});
        else
        {
            while (sk.back().first >= arr[i])
            {
                pii tmp = sk.back();
                sk.pop_back();
                foreward[tmp.second] = sk.size();
            }
            sk.push_back({arr[i], i});
        }
    }

    while (sk.back().second != -1)
    {
        foreward[sk.back().second] = sk.size();
        sk.pop_back();
    }
    
    printf("test\n");
    
    for (int i=n-1; 0<=n; i--)
    {
        if (sk.back().first < arr[i]) sk.push_back({arr[i], i});
        else
        {
            while (sk.back().first >= arr[i])
            {
                pii tmp = sk.back();
                sk.pop_back();
                backward[tmp.second] = sk.size();
            }
            sk.push_back({arr[i], i});
        }
    }

    while (sk.back().second != -1)
    {
        backward[sk.back().second] = sk.size();
        sk.pop_back();
    }

    printf("test\n");

    for (int i=0; i<n; i++)
    {
        printf("%2d\t%d\n", foreward[i], backward[i]);
    }

    int ans = 0;
    for (int i=0; i<n; i++)
    {
        if (ans < foreward[i] + backward[i]) ans = foreward[i] + backward[i];
    }

    printf("%d\n", ans);

    return 0;
}
