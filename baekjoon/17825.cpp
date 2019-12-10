#include <cstdio>
#include <vector>
using namespace std;

#define FINISH 38

//               0               5                  10                  15                  20  21                  26              30              34
int score[39] = {0, 2, 4, 6 ,8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 10, 13, 16, 19, 25, 20, 22, 24, 25, 30, 28, 27, 26, 25, 30, 35, 40, 0};
bool visit[39];
int idx_horse[4];
int score_hores[4];
int arr[10];
int ans;
vector<int> test[4];

int move(int idx, int val)
{
    int idx_start = idx_horse[idx];
    idx_horse[idx] += val;
    if (idx_start < 21)
    {
        if (idx_horse[idx] == 5) idx_horse[idx] = 21;
        else if (idx_horse[idx] == 10) idx_horse[idx] = 26;
        else if (idx_horse[idx] == 15) idx_horse[idx] = 30;
        else if (idx_horse[idx] == 20) idx_horse[idx] = 37;
        else if (idx_horse[idx] > 20) idx_horse[idx] = FINISH;
    }
    else if (idx_start < 26 && idx_horse[idx] >= 25) idx_horse[idx] = (idx_horse[idx]-25) + 34;
    else if (idx_start < 30 && idx_horse[idx] >= 29) idx_horse[idx] = (idx_horse[idx]-29) + 34;
    else if (idx_horse[idx] > 37) idx_horse[idx] = FINISH;
    
    return idx_horse[idx];
}

void dfs(const int step, const int cnt_go)
{
    if (step == 10)
    {
        int sum = 0;
        for (int i=0; i < cnt_go; i++) sum += score_hores[i];
        ans = ans>sum?ans:sum;
    }
    else
    {
        if (cnt_go < 4)
        {
            move(cnt_go, arr[step]);
            if (visit[idx_horse[cnt_go]]) idx_horse[cnt_go] = 0;
            else
            {
                visit[idx_horse[cnt_go]] = true;
                score_hores[cnt_go] = score[idx_horse[cnt_go]];
                dfs(step+1, cnt_go+1);
                score_hores[cnt_go] = 0;
                visit[idx_horse[cnt_go]] = false;
                idx_horse[cnt_go] = 0;
            }
        }

        for (int i=0; i<cnt_go; i++)
        {
            int prev_idx = idx_horse[i];
            int prev_score = score_hores[i];
            if (prev_idx == FINISH) continue;
            move(i, arr[step]);
            if (visit[idx_horse[i]]) idx_horse[i] = prev_idx;
            else
            {
                visit[prev_idx] = false;
                if (idx_horse[i] != FINISH) visit[idx_horse[i]] = true;
                score_hores[i] += score[idx_horse[i]];
                dfs(step+1, cnt_go);
                score_hores[i] = prev_score;
                visit[idx_horse[i]] = false;
                visit[prev_idx] = true;
                idx_horse[i] = prev_idx;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i=0; i<10; i++) scanf("%d", arr+i);

    dfs(0, 0);

    printf("%d\n", ans);
    
    return 0;
}
