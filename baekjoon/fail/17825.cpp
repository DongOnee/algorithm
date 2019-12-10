#include <cstdio>
#include <vector>
using namespace std;

//               0               5                  10                  15                  20  21                  26              30              34
int score[39] = {0, 2, 4, 6 ,8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 10, 13, 16, 19, 25, 20, 22, 24, 25, 30, 28, 27, 26, 25, 30, 35, 40, 0};
bool visit[39];
int idx_horse[4];
int score_hores[4];
int arr[10];
int cnt_go, ans;
vector<int> test[4];

int move(int idx, int val)
{
    int idx_start = idx_horse[idx];
    idx_horse[idx] += val;
    if (idx_start < 21)
    {
        if (idx_horse[idx] > 20) idx_horse[idx] = 38;
    }
    else if (idx_start < 26)
    {
        if (idx_horse[idx] >= 25) idx_horse[idx] = (idx_horse[idx]-25) + 34;
    }
    else if (idx_start < 30)
    {
        if (idx_horse[idx] >= 29) idx_horse[idx] = (idx_horse[idx]-29) + 34;
    }
    else
    {
        if (idx_horse[idx] > 37) idx_horse[idx] = 38;
    }
    
    if (idx_horse[idx] == 5) idx_horse[idx] = 21;
    else if (idx_horse[idx] == 10) idx_horse[idx] = 26;
    else if (idx_horse[idx] == 15) idx_horse[idx] = 30;
    else if (idx_horse[idx] == 20) idx_horse[idx] = 37;

    return idx_horse[idx];
}

void dfs(int step)
{
    if (step == 10)
    {
        int sum = 0;
        for (int i=0; i<cnt_go; i++) 
        {
            sum += score_hores[i];
            printf("%d :", i);
            for (auto x : test[i]) printf("%d ", x);
            printf("\n");
        }
        ans = (ans>sum?ans:sum);
    }
    else
    {
        int next_move_val = arr[step];
        if (cnt_go < 4)
        {
            int nxt = move(cnt_go, next_move_val);
            test[cnt_go].push_back(nxt);
            if (!visit[nxt])
            {
                visit[nxt] = true;
                score_hores[cnt_go++] = score[next_move_val];

                dfs(step+1);
            }
            
            score_hores[--cnt_go] = 0;
            idx_horse[cnt_go] = 0;
            visit[nxt] = false;
            test[cnt_go].pop_back();
        }

        for (int i=0; i<cnt_go; i++)
        {
            if (idx_horse[i] == 38) continue;
            int prev_idx = idx_horse[i];
            int prev_scr = score_hores[i];
            
            visit[prev_idx] = false;
            int nxt = move(i, next_move_val);
            test[i].push_back(nxt);
            if (!visit[nxt])
            {
                if (nxt != 38) visit[nxt] = true;
                score_hores[i] += score[nxt];

                dfs(step+1);
                visit[nxt] = false;
                score_hores[i] = prev_scr;
            }

            idx_horse[i] = prev_idx;
            visit[prev_idx] = true;
            test[i].pop_back();
        }
    }
    
}


int main(int argc, char const *argv[])
{
    for (int i=0; i<10; i++) scanf("%d", arr+i);

    dfs(0);

    printf("%d\n", ans);
    
    return 0;
}
