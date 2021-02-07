#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

int gear[4][8];
vector<pii> cmds;

void print_gears()
{
    for (int g = 0; g < 4; ++g) {
        for (int i = 0; i < 8; ++i) {
            cout << gear[g][i] << ' ';
        }
        cout << '\n';
    }
}

void turn(int index, int turn_code) 
{
    // cout << "index : " << index << "\tturn_code : " << turn_code << '\n';
    int cur = 0;
    int temp = gear[index][cur];

    for (int i = 1; i < 8; ++i) {
        int nxt = (cur + 8 - turn_code) % 8;
        gear[index][cur] = gear[index][nxt];
        cur = nxt;
    }
    gear[index][cur] = temp;
}

void check_nighbor_turn(int index, bool isLeft, int turn_code)
{
    int nxt_index = index + (isLeft?-1:1);
    int nxt_turn_code = -turn_code;
    if (nxt_index < 0 || nxt_index > 3) return;

    if (gear[index][(8 + (isLeft?-2:2))%8] != gear[nxt_index][(8 + (isLeft?2:-2))%8]) {
        cmds.emplace_back(nxt_index, nxt_turn_code);
        check_nighbor_turn(nxt_index, isLeft, nxt_turn_code);
    }
}

void run()
{
    cmds.clear();

    int idx, turn_code;
    cin >> idx >> turn_code;
    --idx;

    cmds.emplace_back(idx, turn_code);
    check_nighbor_turn(idx, true, turn_code);
    check_nighbor_turn(idx, false, turn_code);

    for (auto& x : cmds) {
        turn(x.first, x.second);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char c;
    for (int g = 0; g < 4; ++g)
        for (int i = 0; i < 8; ++i) {
            cin >> c;
            gear[g][i] = (c=='1'?1:0);
        }

    int cmd_count; cin >> cmd_count;
    while (cmd_count--)
        run();

    cout << (
            (gear[0][0]?1:0) + 
            (gear[1][0]?2:0) + 
            (gear[2][0]?4:0) + 
            (gear[3][0]?8:0)) << '\n';

    return 0;
}
