#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int ining, ans;
vector<int> order;
int vvi[50][9];

void run()
{
    int cur_hitter = 0, score = 0;
    order.insert(order.begin()+3, 0);
    for (int curIning = 0; curIning < ining; curIning++)
    {
        int outCount = 0;
        bool bases[4] = {false, }; // 0:Home
        while (outCount < 3)
        {
            int idxHitter = order[cur_hitter];
            int hit = vvi[curIning][idxHitter];
            bases[0] = true;
            switch (hit)
            {
            case 0:
                outCount++;
                break;
            
            default:
                for (int i=3; 0<=i; i--) if (bases[i])
                {
                    if (hit + i > 3) score++;
                    else bases[hit + i] = true;
                    bases[i] = false;
                }
            }
            cur_hitter = (cur_hitter+1)%9;
        }
    }
    
    order.erase(order.begin()+3);
    ans = ans>score?ans:score;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &ining);
    for (int i=0; i<ining; i++) for (int j=0; j<9; j++) scanf("%d", vvi[i]+j);

    for (int i=1; i<9; i++) order.push_back(i);

    while (true)
    {
        run();
        if (!next_permutation(order.begin(), order.end())) break;
    }


    printf("%d\n", ans);

    return 0;
}
