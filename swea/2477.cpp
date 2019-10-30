#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

typedef struct _info
{
    int idx;
    int tm;
    int st; // 0: 접수중 고객   1: 수리중 고객   2: 방문 고객
    int idx_counter;
}client_info;

bool operator<(const client_info& a, const client_info& b)
{
    if (a.tm == b.tm)
    {
        if (a.st == b.st)
        {
            if (a.idx_counter == b.idx_counter) return a.idx > b.idx;
            return a.idx_counter > b.idx_counter;
        }
        return a.st < b.st;
    }
    return a.tm > b.tm;
}


int n, m, nn[10], mm[10];
int k, kk[1000], kkk[1000];
int a, b, ans;
priority_queue<int> rec_counter, rep_counter;
queue<int> wait_rec, wait_rep;
priority_queue<client_info> pq;


void init()
{
    ans = -1;
    priority_queue<client_info> empty_pq; pq.swap(empty_pq);
    priority_queue<int> empty_pq2[2];
    rec_counter.swap(empty_pq2[0]);
    rep_counter.swap(empty_pq2[1]);
    
    scanf("%d%d%d%d%d", &n, &m, &k, &a, &b);
    a--, b--;
    for (int i=0; i<n; i++)
    {
        scanf("%d", nn+i);
        rec_counter.push(-i);
    }
    for (int i=0; i<m; i++)
    {
        scanf("%d", mm+i);
        rep_counter.push(-i);
    }
    for (int i=0; i<k; i++) 
    {
        scanf("%d", kk+i);
        kkk[i] = -1;
        pq.push({i, kk[i], 0, -1});
    }
}

void simulation()
{
    int cnt = k, cur_tm = 0, next_tm;
    while (!pq.empty())
    {
        // printf("test pq.size : %ld\n", pq.size());
        client_info tp = pq.top(); pq.pop();
        // printf("pq's top info\tidx: %d\ttm: %d\tst: %d\tcounter: %d\n", tp.idx, tp.tm, tp.st, tp.idx_counter);
        cur_tm = tp.tm;
        if (tp.st == 0) wait_rec.push(tp.idx); // 방문 고객
        else if (tp.st == 1) // 접수 끝  
        {
            wait_rep.push(tp.idx);
            rec_counter.push(-tp.idx_counter);
            kkk[tp.idx] = tp.idx_counter;
        }
        else if (tp.st == 2) // 수리 끝
        {
            rep_counter.push(-tp.idx_counter);
            cnt--;
            if (kkk[tp.idx] == a && tp.idx_counter == b)
            {
                if (ans == -1) ans = tp.idx+1;
                else ans += tp.idx+1;
            }
        }

        if (!rec_counter.empty() && !wait_rec.empty())
        {
            int idx_rec_counter = -rec_counter.top(); rec_counter.pop();
            int idx_rec_client = wait_rec.front(); wait_rec.pop();
            pq.push({idx_rec_client, cur_tm+nn[idx_rec_counter], 1, idx_rec_counter});
        }
        if (!rep_counter.empty() && !wait_rep.empty())
        {
            int idx_rep_counter = -rep_counter.top(); rep_counter.pop();
            int idx_rep_client = wait_rep.front(); wait_rep.pop();
            pq.push({idx_rep_client, cur_tm+mm[idx_rep_counter], 2, idx_rep_counter});
        }
    }
}
    
int main(int argc, char const *argv[])
{
    // freopen("2477_input.txt", "r", stdin);
    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        init();
        simulation();
        printf("#%d %d\n", test_case, ans);
    }

    return 0;
}
