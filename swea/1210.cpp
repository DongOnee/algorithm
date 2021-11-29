#include <iostream>
#include <string.h>

using namespace std;

int ans;
int column_to_line[100];
int idx_to_column[51];
int colum_count;

void init()
{
    colum_count = 0;
    ans = 0;
    memset(column_to_line, 0, sizeof(column_to_line));
    memset(idx_to_column, 0, sizeof(idx_to_column));
    
    for (int c = 0; c < 100; ++c) {
        int tmp; cin >> tmp;
        if (tmp == 1) {
            column_to_line[c] = ++colum_count;
            idx_to_column[colum_count] = c;
        }
    }

    int cur_idx[51];
    for (int i = 1; i <= colum_count; ++i) cur_idx[i] = i;

    int connect_idx;
    int end_idx;
    for (int r = 1; r < 100; ++r) {
        bool connected = false;
        for (int c = 0; c < 100; ++c) {
            int tmp; cin >> tmp;

            if (tmp == 1) {
                if (!connected) {
                    connected = true;
                    connect_idx = column_to_line[c];
                }
                else {
                    end_idx = column_to_line[c];
                }
            }
            else if (tmp == 2) {
                ans = cur_idx[column_to_line[c]];
                return;
            }
            else {
                if (connected) {
                    int tmp_idx = cur_idx[connect_idx];
                    cur_idx[connect_idx] = cur_idx[end_idx];
                    cur_idx[end_idx] = tmp_idx;
                }
                connected = false;
            }
        }
        if (connected) {
            int tmp_idx = cur_idx[connect_idx];
            cur_idx[connect_idx] = cur_idx[end_idx];
            cur_idx[end_idx] = tmp_idx;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int T; cin >> T;
    for (int tc = 1; tc <= 10; ++tc) {
     int T; cin >> T;
        init();

        cout << '#' << tc << ' ' << idx_to_column[ans] << '\n';
    }

    return 0;
}
