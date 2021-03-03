#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
typedef struct board_info_s board_info_t;
typedef struct shark_info_s shark_info_t;

const pii dirs[4] = { {-1,0}, {1,0}, {0,-1}, {0,1} };
const int MAX_BOARD_SIZE = 20;
const int MAX_SHARK_COUNT = 400;

struct board_info_s {
    int shark_index;
    int smell_own_index;
    int smell_remain;
};

struct shark_info_s {
    pii point;
    int dir;
    int priority_dir[4][4];
};

int board_size, shark_count, smell_remain;
board_info_t board[MAX_BOARD_SIZE][MAX_BOARD_SIZE];
shark_info_t sharks[MAX_SHARK_COUNT];

void smell_extract() {
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            board_info_t& board_case = board[row][col];
            if (board_case.smell_remain > 0) {
                if (--board_case.smell_remain == 0) {
                    board_case.smell_own_index = 0;
                }
            }

            if (board_case.shark_index > 0) {
                board_case.smell_own_index = board_case.shark_index;
                board_case.smell_remain = smell_remain;
            }
        }
    }
}

void move_shark() {
    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        if (sharks[shark_index].point.first == MAX_BOARD_SIZE) continue;
        board[sharks[shark_index].point.first][sharks[shark_index].point.second].shark_index = 0;

        bool flag = true;
        for (int i = 0; i < 4; i++) {
            int new_dir = sharks[shark_index].priority_dir[sharks[shark_index].dir][i];
            int next_row = sharks[shark_index].point.first + dirs[new_dir].first;
            int next_col = sharks[shark_index].point.second + dirs[new_dir].second;
            if (!(0 <= next_row && next_row < board_size && 0 <= next_col && next_col < board_size)) continue;
            if (board[next_row][next_col].smell_remain > 0) continue;
            flag = false;
            sharks[shark_index].point = {next_row, next_col};
            sharks[shark_index].dir = new_dir;
            break;
        }

        if (flag) {
            for (int i = 0; i < 4; i++) {
                int new_dir = sharks[shark_index].priority_dir[sharks[shark_index].dir][i];
                int next_row = sharks[shark_index].point.first + dirs[new_dir].first;
                int next_col = sharks[shark_index].point.second + dirs[new_dir].second;
                if (!(0 <= next_row && next_row < board_size && 0 <= next_col && next_col < board_size)) continue;
                if (board[next_row][next_col].smell_own_index != shark_index) continue;

                sharks[shark_index].point = {next_row, next_col};
                sharks[shark_index].dir = new_dir;
                break;
            }
        }

        int row = sharks[shark_index].point.first;
        int col = sharks[shark_index].point.second;

        if (board[row][col].shark_index != 0 && board[row][col].shark_index < shark_index) { // 잡아 먹기 실패
            sharks[shark_index].point.first = MAX_BOARD_SIZE;
        // } else if (board[row][col].shark_index > 0 && shark_index < board[row][col].shark_index) { // 잡어 먹기
        //     sharks[board[row][col].shark_index].point.first = MAX_BOARD_SIZE;
        //     board[row][col].shark_index = shark_index;
        } else {
            board[row][col].shark_index = shark_index;
        }
    }
}

bool check_board() {
    for (int row = 0; row < board_size; ++row) {
        for (int col = 0; col < board_size; ++col) {
            if (board[row][col].shark_index != 0 && board[row][col].shark_index != 1) return false;
        }
    }

    return true; 
}

int run() {
    int ret = 0;

    while (++ret < 1001) {
        smell_extract();
        move_shark();
        if (check_board())
            return ret;
    }

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> board_size >> shark_count >> smell_remain;

    for (int row = 0; row < board_size; ++row) {
        for (int col = 0, shark_index; col < board_size; ++col) {
            cin >> shark_index;
            board[row][col].shark_index = shark_index;
            if (shark_index != 0) {
                sharks[shark_index].point = {row, col};
            }
        }
    }

    for (int shark_index = 1, input_dir; shark_index <= shark_count; ++shark_index) {
        cin >> input_dir; --input_dir;
        sharks[shark_index].dir = input_dir;
    }

    for (int shark_index = 1; shark_index <= shark_count; ++shark_index) {
        for (int i = 0, input_dir[4]; i < 4; ++i) {
            cin >> input_dir[0] >> input_dir[1] >> input_dir[2] >> input_dir[3];
            sharks[shark_index].priority_dir[i][0] = --input_dir[0];
            sharks[shark_index].priority_dir[i][1] = --input_dir[1];
            sharks[shark_index].priority_dir[i][2] = --input_dir[2];
            sharks[shark_index].priority_dir[i][3] = --input_dir[3];
        }
    }

    cout << run() << "\n";

    return 0;
}
