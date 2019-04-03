#include <cstdio>
#include <string>
#include <queue>
using namespace std;

// typedef pair<pair<int, int>, string> sibal;
typedef pair<pair<int, pair<int, int>>, string> sibal;

int t;

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++)
    {
        int sol=0;
        int n;
        priority_queue<sibal> pq;

        scanf("%d", &n);
        for (int i=0; i<n; i++)
        {
            char np[100001];
            scanf("%s", np);
            char single = np[0];
            int cnt_s=0, cnt_w=0, score=0, cnts=0;
            for (int i=0; np[i]!=0; i++)
            {
                if (np[i] == 'S')
                {
                    cnt_s++;
                    score += cnts;
                }
                else
                {
                    cnt_w++;
                    cnts++;
                }
                
            }
            // pq.push(make_pair(make_pair(cnt_s-cnt_w, -cnt_w), np));
            // pq.push(make_pair(make_pair((cnt_s-cnt_w>0?1:0), cnt_s-cnt_w), np));
            // pq.push(make_pair(make_pair((cnt_w==0?1:cnt_s==0?-1:0), score), np));
            pq.push(make_pair(make_pair((cnt_w==0?1:cnt_s==0?-1:0), make_pair(cnt_s-cnt_w, -cnt_w)), np));
        }

        string p;
        while (!pq.empty())
        {
            sibal tp = pq.top();
            pq.pop();
            string tmp = tp.second;
            for (int i=0; i<tmp.size(); i++)
                p.push_back(tp.second[i]);
            printf("%s ", tp.second.c_str());
        }
        printf("\n");

        // printf("%s\n", p.c_str());

        int cnt =0;
        for (int i=p.size()-1; 0<=i; --i)
        {
            if (p[i] == 'S') sol += cnt;
            else cnt++;
            printf("%c cnt : %d\n", p[i],cnt);
        }

        printf("#%d %d\n", tc+1, sol);

    }
    return 0;
}