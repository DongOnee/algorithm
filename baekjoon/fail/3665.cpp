#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAXN 500
#define MAXN_PLUS_1 501
#define MAXM 25000

typedef pair<int, int> pii;

int n, m, prev_[MAXN_PLUS_1];   // prev_[i]는 작년에 i등을 한 팀의 번호
int cnt_upper_rank[MAXN_PLUS_1];
bool reversed[MAXN_PLUS_1][MAXN_PLUS_1];
pii change_score[MAXM];         // first 가  second 보다  등수 높음
vector<int> lower_rank[MAXN_PLUS_1];

void algo()
{
    // 1. cont upper rank == 0 --> qu
        // 1-1. qu is empty  __ end
    // 2. qu front --> f, pop
        // 2-1. qu is not empty() __ end
    // 3. vector push f
    // 4. for ( a : lower rank[f]) cnt upper rank --
    queue<int> qu;
    vector<int> answer;
    for (int numTeam=1; numTeam<=n; ++numTeam)
        if (cnt_upper_rank[numTeam] == 0) 
            cout << "test\t" << numTeam << endl, qu.push(numTeam);

    // cout << "input -- \n";
    // for (int i = 1; i<=n; i++)
    // {
    //     int numTeam = prev_[i];
    //     cout << "prev[" << i << "] : " << numTeam << "\n";
    //     cout << "lower_rank[ prev[" << i << "] ] ";
    //     for (auto& x : lower_rank[numTeam])
    //         cout << x << ' ';
    // }
    
    for (--n; qu.size() == 1; --n)
    {
        int numTeam = qu.front(); qu.pop();
        cout << numTeam << '\n';
        answer.push_back(numTeam);
        for (int& lowerTeam : lower_rank[numTeam])
            if (!reversed[lowerTeam][numTeam])
                if (--cnt_upper_rank[lowerTeam] == 0)
                    qu.push(lowerTeam);
    }

    if ( n == 0 )
        for (int& numTeam : answer)
            cout << numTeam << ' ';
    else if (qu.empty())
        cout << '?';
    else
        cout << "IMPOSSIBLE";
    cout <<'\n';
}

void input_()
{
    cin >> n;
    for (int rank=1, numTeam; rank<=n; rank++)
    {
        cin >> numTeam;
        prev_[rank] = numTeam;
        lower_rank[numTeam].clear();
        cnt_upper_rank[numTeam] = 0;
        if ( rank != 1)
        {
            lower_rank[prev_[rank-1]].push_back(numTeam);
            cnt_upper_rank[numTeam] = 1;
        }
        for (int j=1; j<=n; j++) reversed[rank][j] = false;
    }

    cin >> m;
    for (int i=0, _win, _lose; i<m; i++)
    {
        cin >> _win >> _lose;
        reversed[_lose][_win] = true;
        lower_rank[_lose].push_back(_win);
        /* --cnt_upper_rank[_win],*/ ++cnt_upper_rank[_lose];
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;

    for (int test_case = 1; test_case <= T; test_case++)
    {
        input_();
        algo();
    }
    
    return 0;
}

/*
1
5
5 4 3 2 1
2
2 4
3 4
3
2 3 1
0
4
1 2 3 4
3
1 2
3 4
2 3
*/