#include <iostream>

using namespace std;

const int MAXN  = 100;
int belt[MAXN * 2];
bool robots[MAXN * 2];
int belt_size, k;
int st, ed;

#define BELT_NEXT(cur)      ((cur+1)%(belt_size*2))
#define BELT_BEFORE(cur)    ((cur+2*belt_size-1)%(belt_size*2))
#define BELT_END()          ((st+belt_size-1)%(belt_size*2))

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> belt_size >> k;
    for (int i = 0; i < 2 * belt_size; ++i) cin >> belt[i];

    st = 0, ed = belt_size - 1;

    int t = 0, cnt = 0;
    while (cnt < k) {
        ++t;
        st = BELT_BEFORE(st);
        ed = BELT_END();
        if (robots[ed]) robots[ed] = false;
        for (int idx = ed; idx != st; idx = BELT_BEFORE(idx)) {
            int i = BELT_BEFORE(idx);
            if (robots[i] && !robots[idx] && belt[idx] > 0) {
                robots[i] = false;
                robots[idx] = true;
                if (--belt[idx] == 0) ++cnt;
            } 
        }
        if (robots[ed]) robots[ed] = false;

        if (belt[st] > 0) {
            robots[st] = true;
            if (--belt[st] == 0) ++cnt;
        }
    }

    cout << t << '\n';

    return 0;
}
