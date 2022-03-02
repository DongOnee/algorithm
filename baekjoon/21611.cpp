#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

#define MAXN 49

int _board[MAXN][MAXN];
int _boardSize, _score[4];
int _shark_r, _shark_c;

int dirs[5][2] = {{0,0}, {-1,0}, {1,0}, {0,-1}, {0,1}};

bool bomb()
{
    int _search_r = _shark_r;
    int _search_c = _shark_c;
    int grp = 0;
    vector<pii> grps;
    bool ret = false;

    static int turnDir[4] = {3, 2, 4, 1};
    for (int i = 1, c = 1, di = 0; i < _boardSize * _boardSize; ++i) {
        int d = turnDir[di];
        _search_r += dirs[d][0];
        _search_c += dirs[d][1];
        if (--c == 0) {
            c = i / 2 + 1;
            di = (di + 1) % 4;
        }

        if (grp != _board[_search_r][_search_c]) {
            if (grps.size() > 3) {
                for (auto & p : grps) {
                    _board[p.first][p.second] = 0;
                }

                _score[grp] += grps.size();
            }

            grps.clear();
            ret = true;
        }
        grps.push_back({_search_c, _search_r});
    }

    return ret;
}

void blizard(int d, int s)
{
    for (int i = 0; i < s; ++i) {
        ++_score[_board[_shark_r + dirs[d][0] * i][_shark_c + dirs[d][1] * i]];
        _board[_shark_r + dirs[d][0] * i][_shark_c + dirs[d][1] * i] = 0;
    }

    while (true) {
        // 이동
        int _search_r = _shark_r;
        int _search_c = _shark_c;

        int _empty_idx = 1, _empty_di = 1, _empty_ch = 1;
        int _empty_r = _shark_r;
        int _empty_c = _shark_c - 1;

        static int turnDir[4] = {3, 2, 4, 1};
        for (int i = 1, c = 1, di = 0; i < _boardSize * _boardSize; ++i) {
            int d = turnDir[di];
            _search_r += dirs[d][0];
            _search_c += dirs[d][1];
            if (--c == 0) {
                c = i / 2 + 1;
                di = (di + 1) % 4;
            }
            
            if (_board[_search_r][_search_c] == 0) continue;

            if (!(_empty_r == _search_r && _empty_c == _search_c)) {
                _board[_empty_r][_empty_c] = _board[_search_r][_search_c];
                _board[_search_r][_search_c] = 0;
            }

            int empty_d = turnDir[_empty_di];
            _empty_r += dirs[empty_d][0];
            _empty_c += dirs[empty_d][1];
            if (--_empty_ch == 0) {
                _empty_ch = _empty_idx / 2 + 1;
                _empty_di = (_empty_di + 1) % 4;
            }
            ++_empty_idx;
        }

        // 찾기/폭발 - break; 4 개이상 연속된 그룹
        if (bomb()) break;
    }

    // 재배치
    int _search_r = _shark_r;
    int _search_c = _shark_c;
    int grp = _board[_search_r][_search_c - 1];
    vector<pii> grps;
    bool ret = false;

    int _empty_idx = 1, _empty_di = 1, _empty_ch = 1;
    int _empty_r = _shark_r;
    int _empty_c = _shark_c - 1;

    static int turnDir[4] = {3, 2, 4, 1};
    for (int i = 1, c = 1, di = 0; i < _boardSize * _boardSize; ++i) {
        int d = turnDir[di];
        _search_r += dirs[d][0];
        _search_c += dirs[d][1];
        if (--c == 0) {
            c = i / 2 + 1;
            di = (di + 1) % 4;
        }

        if (grp != _board[_search_r][_search_c]) {

            _board[_empty_r][_empty_c] = grps.size();

            int empty_d = turnDir[_empty_di];
            _empty_r += dirs[empty_d][0];
            _empty_c += dirs[empty_d][1];
            if (--_empty_ch == 0) {
                _empty_ch = _empty_idx / 2 + 1;
                _empty_di = (_empty_di + 1) % 4;
            }
            ++_empty_idx;


            _board[_empty_r][_empty_c] = _board[_search_r][_search_c];
            
            empty_d = turnDir[_empty_di];
            _empty_r += dirs[empty_d][0];
            _empty_c += dirs[empty_d][1];
            if (--_empty_ch == 0) {
                _empty_ch = _empty_idx / 2 + 1;
                _empty_di = (_empty_di + 1) % 4;
            }
            ++_empty_idx;

            grps.clear();
        }
        grps.push_back({_search_c, _search_r});
        _board[_search_r][_search_c] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int cmdCount;

    cin >> _boardSize >> cmdCount;
    _shark_r = _shark_c = _boardSize / 2;

    for (int i = 0 ; i < _boardSize; ++i)
        for (int j = 0; j < _boardSize; ++j) 
            cin >> _board[i][j];

    while (cmdCount--) {
        int d, c; cin >> d >> c;
        blizard(d, c);
    }

    cout << _score[1] + 2 * _score[2] + 3 * _score[3] << '\n';


    return 0;
}