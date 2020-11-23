/**
 * 2020/11/23 19:54
 */

#include <iostream>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;

typedef pair<int,int> pii;

const int MAXPOINT = 500;
const int MAXTIME = 0x3f3f3f3f;

int count_point, count_road, count_worm;

vector<pii> road_time[2700];
int travel_time[MAXPOINT];

void init() {
    count_point = 0;
    count_road = 0;
    count_worm = 0;

    for (int i=0; i < MAXPOINT; ++i) {
        travel_time[i] = MAXTIME;
        road_time[i].clear();
    }
}

void inputData() {
    cin >> count_point >> count_road >> count_worm;
    for (int i = 0, s, e, t; i < count_road; ++i) {
        cin >> s >> e >> t;
        road_time[s-1].emplace_back(e-1, t);
        road_time[e-1].emplace_back(s-1, t);
    }
    
    for (int i = 0, s, e, t; i < count_worm; ++i) {
        cin >> s >> e >> t;
        road_time[s-1].emplace_back(e-1, -t);
    }
}

bool run() {
    for (int i=0; i<count_point; ++i) {
        for (int index_point = 0; index_point < count_point; ++index_point) {
            for (auto& next_point : road_time[index_point]) {
                int dest = next_point.first;
                int t = next_point.second;
                if (travel_time[dest] > travel_time[index_point] + t) {
                    travel_time[dest] = travel_time[index_point] + t;
                    if (i == count_point - 1) return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tc; cin >> tc;
    while (tc--) {
        init();
        inputData();
        cout << (run()==true?"NO":"YES") << "\n";
    }


    return 0;
}
