#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

typedef struct
{
    pii point;
    int dir;
}fish_info;

const pii dirs[8] = {{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1}};

int board[4][4], ans;
fish_info fishes[17];
fish_info shark;

bool chk(pii c) { return 0<=c.first&&c.first<4&&0<=c.second&&c.second<4; }

void eat_fish(int idx) 
{
    auto& f = fishes[idx];
    
    board[shark.point.first][shark.point.second] = 0;
    shark = f;
    f.point.first = -1;
    board[shark.point.first][shark.point.second] = -1;
}

void move_fishes()
{
    for (int idx = 1; idx <= 16; ++idx) {
        if (fishes[idx].point.first == -1) continue;
        
        pii point = fishes[idx].point;
        int dir = fishes[idx].dir;

        for (int i = 0; i < 8; ++i, dir = (dir+1)%8) {
            pii nxt = point + dirs[dir];

            if (!chk(nxt)) continue;
            if (board[nxt.first][nxt.second] == -1) continue;
            else if (board[nxt.first][nxt.second] == 0) {
                fishes[idx].point = nxt;
                fishes[idx].dir = dir;

                board[nxt.first][nxt.second] = idx;
                board[point.first][point.second] = 0;

                break;
            }
            else {
                fishes[board[nxt.first][nxt.second]].point = point;
                board[point.first][point.second] = board[nxt.first][nxt.second];

                fishes[idx].point = nxt;
                fishes[idx].dir = dir;
                board[nxt.first][nxt.second] = idx;

                break;
            }
        }
    }
}

void run(int score)
{
    int cp_board[4][4];
    fish_info cp_fishes[17];
    fish_info cp_shark = shark;

    for (int row = 0; row < 4; ++row) for (int col = 0; col < 4; ++col) cp_board[row][col] = board[row][col];
    for (int idx = 0; idx < 17; ++idx) cp_fishes[idx] = fishes[idx];

    vector<int> hunting_index;
    pii nxt = shark.point + dirs[shark.dir];

    while (chk(nxt)) {
        if (board[nxt.first][nxt.second] > 0) hunting_index.push_back(board[nxt.first][nxt.second]);
        nxt = nxt + dirs[shark.dir];
    }

    if (hunting_index.empty()) {
        ans = max(ans, score);
    }
    else {
        for (int num : hunting_index) {
            eat_fish(num);
            move_fishes();
            run(score + num);
            for (int row = 0; row < 4; ++row) for (int col = 0; col < 4; ++col) board[row][col] = cp_board[row][col];
            for (int idx = 0; idx < 17; ++idx) fishes[idx] = cp_fishes[idx];
            shark = cp_shark;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int row = 0; row < 4; ++row) for (int col = 0; col < 4; ++col) {
        int num, d; cin >> num >> d;
        board[row][col] = num;
        fishes[num] = {{row,col},d-1};
    }

    int fish_num = board[0][0];
    eat_fish(fish_num);
    move_fishes();

    run(fish_num);

    cout << ans << '\n';

    return 0;
}
