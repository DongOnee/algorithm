#include <iostream>
#include <vector>
#include <utility>

using namespace std;
typedef pair<int,int> pii;
pii operator+(pii& a, pii&b) { return {a.first+b.first, a.second+b.second}; }

typedef
struct 
{
    pii pos;
    int dir;
}fishInfo;

pii dirs[9] = { {0,0}, {-1,0}, {-1,-1}, {0,-1}, {1,-1}, {1, 0}, {1, 1}, {0,1}, {-1,1} };

int sol;

void printboard(const vector<vector<int>>& board) {
    for (auto row : board) {
        for (auto col : row)
        {
            cout << col << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void fishMov(vector<vector<int>>& board, vector<fishInfo>& fish_Info, pii shark)
{
    for (int fishIndex = 1; fishIndex <= 16; fishIndex++)
    {
        fishInfo& searchFish = fish_Info[fishIndex];
        if (searchFish.dir == 0) continue;
        for (int i=0; i<8; i++)
        {
            pii nextPos = searchFish.pos + dirs[searchFish.dir];
            if (0 <= nextPos.first && nextPos.first < 4 && 0 <= nextPos.second && nextPos.second < 4)
            {
                if (nextPos != shark)
                {
                    if (board[nextPos.first][nextPos.second] == 0)
                    {
                        board[nextPos.first][nextPos.second] = fishIndex;
                        board[searchFish.pos.first][searchFish.pos.second] = 0;
                        fish_Info[fishIndex].pos = nextPos;
                    }
                    else
                    {
                        int nextFishIndex = board[nextPos.first][nextPos.second];
                        fishInfo nextFish = fish_Info[nextFishIndex];

                        board[searchFish.pos.first][searchFish.pos.second] = nextFishIndex;
                        board[nextPos.first][nextPos.second] = fishIndex;

                        fish_Info[nextFishIndex].pos = searchFish.pos;
                        fish_Info[fishIndex].pos = nextFish.pos;
                    }
                    break;
                }
            }
            fish_Info[fishIndex].dir = fish_Info[fishIndex].dir % 8 + 1;
        }
        // printboard(board);
    }
}

void run(vector<vector<int>> board, vector<fishInfo> fish_Info, pii shark, int score)
{
    score += board[shark.first][shark.second];
    sol = max(sol, score);
    int shark_dir = fish_Info[board[shark.first][shark.second]].dir;
    fish_Info[board[shark.first][shark.second]].dir = 0;
    board[shark.first][shark.second] = 0;

    fishMov(board, fish_Info, shark);

    while (true)
    {
        shark = shark + dirs[shark_dir];
        if (0 <= shark.first && shark.first < 4 && 0 <= shark.second && shark.second < 4)
        {
            if (board[shark.first][shark.second] != 0) run(board, fish_Info, shark, score);
        }
        else break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> f(4);
    vector<fishInfo> fi(17);

    for (int i=0; i<4; i++) {
        for (int j=0, num, dir; j<4; j++) {
            cin >> num >> dir;
            f[i].push_back(num);
            fi[num] = { {i, j}, dir};
        }
    }

    run(f, fi, {0, 0}, 0);

    cout << sol;

    return 0;
}
