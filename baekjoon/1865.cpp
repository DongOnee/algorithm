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
int travel_time[MAXPOINT][MAXPOINT];

void init() {
    count_point = 0;
    count_road = 0;
    count_worm = 0;

    for (int i=0; i < MAXPOINT; ++i) {
        for (int j = 0; j < MAXPOINT; ++j)
            travel_time[i][j] = MAXTIME;
        travel_time[i][i] = 0;
        road_time[i].clear();
    }
}

void inputData() {
    cin >> count_point >> count_road >> count_worm;
    for (int i = 0, s, e, t; i < count_road; ++i) {
        cin >> s >> e >> t;
        travel_time[s-1][e-1] = min(travel_time[s-1][e-1], t);
        travel_time[e-1][s-1] = min(travel_time[e-1][s-1], t);
    }
    
    for (int i = 0, s, e, t; i < count_worm; ++i) {
        cin >> s >> e >> t;
        travel_time[s-1][e-1] = min(travel_time[s-1][e-1], -t);
    }
}

bool run() {
    
    for (int way = 0; way < count_point; ++way) {
        for (int src = 0; src < count_point; ++src) {
            for (int dest = 0; dest < count_point; ++dest) {
                travel_time[src][dest] = min(travel_time[src][dest], travel_time[src][way] + travel_time[way][dest]);

                if (src == dest && travel_time[src][dest] < 0) return false;
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
