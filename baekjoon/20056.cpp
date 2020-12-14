#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
typedef struct {
    pii dir;
    int m, s, d;
}fireball_info;

pii operator+(const pii& a, const pii& b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

void operator+=(pii& a, const pii& b) {
    a.first += b.first;
    a.second += b.second;
}

pii operator*(const pii& a, const pii& p) {
    return make_pair(a.first * p.first, a.second * p.second);
}

const pii dirs[8] = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
const int MAXN = 50;

int board_width, fireball_count, cmd_count;

queue<fireball_info> fireballs;
vector<fireball_info> candidate[MAXN][MAXN];

void moveFireball() {
    while (!fireballs.empty()) {
        auto fireball = fireballs.front(); fireballs.pop();
        fireball.dir.first = (fireball.dir.first + dirs[fireball.d].first * fireball.s + board_width) % board_width;
        fireball.dir.second = (fireball.dir.second + dirs[fireball.d].second * fireball.s + board_width) % board_width;
        while (fireball.dir.first < 0) fireball.dir.first += board_width;
        while (fireball.dir.second < 0) fireball.dir.second += board_width;
        candidate[fireball.dir.first][fireball.dir.second].push_back(fireball);
    }
}

void composeFireball() {
    for (int row = 0; row < board_width; ++row) {
        for (int col = 0; col < board_width; ++col) {
            auto& candidates = candidate[row][col];

            if (candidates.size() == 0);
            else if (candidates.size() == 1) {
                auto& fireball = candidates[0];
                fireballs.push(fireball);
            }
            else {
                fireball_info new_fireball = {{0,0}, 0, 0, 0};
                new_fireball.dir = {row, col};
                int sz = candidates.size();
                bool new_dir = true;

                for (int i = 0; i < sz; ++i) {
                    new_fireball.m += candidates[i].m;
                    new_fireball.s += candidates[i].s;
                    new_dir = (new_dir && ((candidates[0].d % 2) == (candidates[i].d % 2)));
                }
                new_fireball.m /= 5;
                if (new_fireball.m == 0);
                else {
                    new_fireball.s /= sz;
                    if (new_dir) 
                        new_fireball.d = 0;
                    else
                        new_fireball.d = 1;
                    for (int i=0; i<4; i++) {
                        fireballs.push(new_fireball);
                        new_fireball.d += 2;
                    }
                }
            }
            while (!candidates.empty())
                candidates.pop_back();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> board_width >> fireball_count >> cmd_count;
    for (int i=0; i<fireball_count; ++i) {
        fireballs.emplace();
        auto& fireball = fireballs.back();

        cin >> fireball.dir.first
            >> fireball.dir.second
            >> fireball.m
            >> fireball.s
            >> fireball.d;
        fireball.dir.first--;
        fireball.dir.second--;
    }

    while (cmd_count--) {
        moveFireball();
        composeFireball();
    }

    int ans = 0;
    while (!fireballs.empty()) {
        ans += fireballs.front().m;
        fireballs.pop();
    }

    cout << ans << '\n';
    return 0;
}
