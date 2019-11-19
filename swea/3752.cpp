#include <cstdio>
#include <vector>
using namespace std;

int n;
vector<int> scores;
bool bScores[10001];

void init()
{
}

int main(int argc, char const *argv[])
{
    int tc; scanf("%d", &tc);
    for (int test_case=1; test_case<=tc; test_case++)
    {
        for (int i=0; i<10001; i++) bScores[i] = false;
        bScores[0] = true;
        scores.clear();
        scores.push_back(0);

        scanf("%d", &n);
        for (int i=0, a; i<n; i++)
        {
            long sz = scores.size();
            scanf("%d", &a);
            for (int idx=0; idx<sz; idx++)
            {
                if (bScores[a + scores[idx]]) continue;
                bScores[a + scores[idx]] = true;
                scores.push_back(a + scores[idx]);
            }
        }

        printf("#%d %ld\n", test_case, scores.size());
    }
    return 0;
}
