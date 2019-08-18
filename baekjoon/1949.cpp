/**
 * 19.3.5
 */
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define MAX_NUM 10001

int N;
int person[MAX_NUM];
vector<int> near[MAX_NUM];
priority_queue<pair<int, int>> pq;
bool supreme[MAX_NUM];
bool chk_near[MAX_NUM];

int main(int argc, char const *argv[])
{
    scanf("%d", &N);

    for (int i=0, a; i<N; i++) 
    {
        // scanf("%d", person+i);
        pq.push(make_pair(person[i], i+1));
    }
    for (int i=0, a, b; i<N-1; i++)
    {
        scanf("%d %d", &a, &b);
        near[a].push_back(b);
        near[b].push_back(a);
    }

    int ret=0;
    while (!pq.empty())
    {
        int q_size = pq.size();
        printf("size : %d\n", q_size);
        while (q_size--)
        {
            pair<int, int> tp = pq.top();
            int vil = tp.second;
            int pers = tp.first;
            pq.pop();

            if (chk_near[vil]) continue;
            
            bool near_supreme = false;
            for (auto n : near[vil])
                if (supreme[n])
                {
                    near_supreme = true;
                    break;
                }

            if (!near_supreme)
            {
                for (auto n : near[vil]) chk_near[n] = true;
                ret += pers;
                supreme[vil] = true;
            }
        }
        for (int i=1; i<=N; i++)
        {
            if (!(supreme[i] || chk_near[i])) pq.push(make_pair(person[i], i));
        }
    }

    printf("%d\n", ret);

    return 0;
}

/*

*/
