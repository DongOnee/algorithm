/**
 * 19.1.1.
 */
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

pair<int, int> vt[100005];

int maximum, N;
int max_chk[100000];

void greedy(int before, int start_index, int cur_count)
{
    if (N<=start_index) {maximum = max(maximum, cur_count);}
    // else if (vt[start_index].first < before) greedy(before, start_index+1, cur_count);
    else
    {
        for (int i=start_index; i<N; i++)
        {
            if (max_chk[i] !=0 && max_chk[i] >= cur_count+1) continue;
            if (before<=vt[i].first)
            {
                // printf("i : %d\n", i);
                max_chk[i] = cur_count+1;
                greedy(vt[i].second, i+1, cur_count+1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i=0; i<N; i++)
    {
        scanf("%d %d", &vt[i].first, &vt[i].second);
    }
    sort(vt, vt+N);
    greedy(0,0,0);
    // puts("");
    // for (int i=0; i<N; i++) printf("%d : %d %d\n", i, vt[i].first, vt[i].second);
    // puts("");
    printf("%d\n", maximum);
    return 0;
}
