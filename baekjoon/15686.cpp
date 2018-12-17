/**
 * 18.12.11. 화요일
 */

#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int map[50][50];
bool select_chicken[13];

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int ret;

void dfs(int chicken_index, int select_cnt) {
    if (chicken_index > chicken.size()) return;
    if (select_cnt == M)
    {
        int _ret=0;
        for (int _house=0; _house<house.size(); _house++)
        {
            int house_min = 12345;
            for (int _chicken=0; _chicken<chicken.size(); _chicken++)
            {
                if (select_chicken[_chicken])
                house_min = min(house_min, abs(house[_house].first-chicken[_chicken].first) + abs(house[_house].second-chicken[_chicken].second) );
            }
            _ret+=house_min;
        }
        ret = min(ret, _ret);

        return;
    }
    select_chicken[chicken_index] = true;
    dfs(chicken_index+1, select_cnt+1);
    select_chicken[chicken_index] = false;
    dfs(chicken_index+1, select_cnt);
}

int main(int argc, char const *argv[])
{
    ret = 1234567;
    scanf("%d %d", &N, &M);

    for (int i=0; i<N; i++) for (int j=0; j<N; j++)
    {
        scanf("%d", &map[i][j]);
        if (map[i][j] == 1) house.push_back(make_pair(i, j));
        else if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
    }

    dfs(0, 0);

    printf("%d\n", ret);

    return 0;
}
