/**
 * 2019.10.27. 22:27 ~
 */
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int n, e, map[801][801];
int visited[801];
vector<int> vt[801];

int calc_dist(int start, int end)
{
    if (start == end) return 0;
    priority_queue<pair<int, int>> pq;
    int visite[801] = {-1, };
    visite[start] = 0;
    pq.push({0, start});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (visite[tp.second] == -1 ) visite[tp.second] = tp.first;
        else
        {
            if (visite[tp.second] <= tp.first) continue;
            else
            {
                visite[tp.second] = tp.first;
                for (int k : vt[tp.second])
                {
                    if (k == end) return tp.first+map[k][tp.second];
                    pq.push({tp.first + map[k][tp.second], k});
                }
            }
        }
    }
    return -1;
}
 
int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &e);
    for (int i=0, a, b, c; i<e; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        map[a][b] = c;
        map[b][a] = c;
        vt[a].push_back(b);
        vt[b].push_back(a);
    }

    int point[2]; scanf("%d %d", point, point+1);

    int dir[5] = { -1, };
    // 1 ~ point[0]
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (tp.second == point[0])
        {
            dir[0] = tp.first;
            priority_queue<pair<int, int>> empty_pq;
            swap(pq, empty_pq);
        }
        else
        {
            for (int dest : vt[tp.second]) pq.push({tp.first+map[dest][tp.second], dest});
        }
    }
    
    // 1 ~ point[1]
    pq.push({0, 1});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (tp.second == point[1])
        {
            dir[1] = tp.first;
            priority_queue<pair<int, int>> empty_pq;
            swap(pq, empty_pq);
        }
        else
        {
            for (int dest : vt[tp.second]) pq.push({tp.first+map[dest][tp.second], dest});
        }
    }

    // n ~ point[0]
    pq.push({0, n});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (tp.second == point[0])
        {
            dir[2] = tp.first;
            priority_queue<pair<int, int>> empty_pq;
            swap(pq, empty_pq);
        }
        else
        {
            for (int dest : vt[tp.second]) pq.push({tp.first+map[dest][tp.second], dest});
        }
    }
    
    // n ~ point[1]
    pq.push({0, n});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (tp.second == point[1])
        {
            dir[3] = tp.first;
            priority_queue<pair<int, int>> empty_pq;
            swap(pq, empty_pq);
        }
        else
        {
            for (int dest : vt[tp.second]) pq.push({tp.first+map[dest][tp.second], dest});
        }
    }
    
    // point[0] ~ point[1]
    pq.push({0, point[0]});
    while(!pq.empty())
    {
        pair<int, int> tp = pq.top(); pq.pop();
        if (tp.second == point[1])
        {
            dir[4] = tp.first;
            priority_queue<pair<int, int>> empty_pq;
            swap(pq, empty_pq);
        }
        else
        {
            for (int dest : vt[tp.second]) pq.push({tp.first+map[dest][tp.second], dest});
        }
    }
    
    dir[4] += min( (dir[0] !=-1 && dir[3] != -1 ? dir[0] + dir[3] : 987654321) , (dir[1] !=-1 && dir[2] != -1 ? dir[1] + dir[2] : 987654321));
    printf("%d\n", (dir[4] > 987654321 ? -1 : dir[4]));

    return 0;
}
