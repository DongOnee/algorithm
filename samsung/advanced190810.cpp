#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

#define MAXN 10000000

int N, K, pow_k, arr[7] = {1000000, 100000, 10000, 1000, 100, 10, 1};
bool visited[MAXN];
int ans, cnt;

int make_swap(int input, int i, int j)
{
    int new_number= 0;
    for (int cur_index = 0; cur_index < 7; cur_index++)
    {
        int aa = input/arr[cur_index];
        input %= arr[cur_index];
        if (cur_index < i && cur_index < j) new_number += aa * arr[cur_index];
        else if (cur_index == i || cur_index == i+1) new_number += aa * arr[j + (cur_index - i)];
        else if (i < j && cur_index < j+2) new_number += aa * arr[cur_index -2]; 
        else if (j < i && cur_index < i+2) new_number += aa * arr[cur_index +2]; 
        else new_number += aa * arr[cur_index];
    }
    return new_number;
}

void bfs()
{
    queue<int> qu;
    qu.push(N);
    visited[N] = true;
    bool isEnd = false;
    while (!qu.empty() && !isEnd)
    {
        long sz = qu.size();
        while (sz--)
        {
            int f = qu.front(); qu.pop();
            for (int i=0; i<6; i++)
            {
                for (int j=0; j<6; j++)
                {
                    if (j == i) continue;
                    int after_swap = make_swap(f, i, j);
                    if (visited[after_swap]) continue;
                    visited[after_swap] = true;
                    int a = after_swap / arr[pow_k];
                    int b = after_swap % arr[pow_k];
                    // printf("new number : %d a : %d b : %d\n", after_swap, a, b);
                    if (a-b == K)
                    {
                        ans = max(ans, after_swap);
                        isEnd = true;
                    }
                    else qu.push(after_swap);
                }
            }
        }
        cnt++;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    for (int test_case=1; test_case<=T; test_case++)
    {
        cin >> N >> K;
        memset(visited, false, sizeof(visited));
        pow_k = -1, ans=0, cnt=0;
        for (int tmp=K; 0<tmp; tmp /= 10) pow_k++;
        if (pow_k == 2) pow_k++;
        printf("%d\n", pow_k);

        bfs();

        printf("#%d %d %d\n", test_case, cnt, ans);
    }
    return 0;
}
