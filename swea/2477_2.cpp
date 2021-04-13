#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 987654321;

enum STEP
{
    ARV,
    TAKE,
    REPAIR
};

typedef struct _info
{
    int _num;
    int _time;
    int _take_index;
    int _repair_index;
    STEP _step;
    _info(int num, int arr_time) : _num(num), _time(arr_time), _step(ARV) {};
}info;

struct take_cmp
{
    bool operator()(const info& a, const info& b) {
        return a._num>b._num;
    }
};

struct repair_cmp
{
    bool operator()(const info& a, const info& b) {
        if (a._time == b._time) return a._take_index > b._take_index;
        return a._time > b._time;
    }
};

struct comp
{
    bool operator()(const info& a, const info& b) {
    }
};
bool use_repair[10], use_take[10];
int time_repair[10], time_take[10];
int count_repair, count_take, count_customer;

priority_queue<info, vector<info>, comp> qu;
int ans;
int a, b;

void init()
{
    ans = 0;
    cin >> count_take >> count_repair >> count_customer >> a >> b;
    --a, --b;
    for (int i = 0; i < count_take; ++i) cin >> time_take[i];
    for (int i = 0; i < count_repair; ++i) cin >> time_repair[i];
    for (int i = 0; i < count_customer; ++i) {
        int t; cin >> t;
        qu.push(info(i+1,t));
    }
}

void run()
{
    int cur_time = 0;

    priority_queue<info, vector<info>, take_cmp> take_wating;
    priority_queue<info, vector<info>, repair_cmp> repair_wating;

    while (!qu.empty()) {
        auto tp = qu.top(); qu.pop();
        cur_time = tp._time;

        if (tp._step == REPAIR) {
            if (tp._take_index == a && tp._repair_index == b) ans += tp._num;
            use_repair[tp._repair_index] = false;


            if (!repair_wating.empty()) {
                use_repair[tp._repair_index] = true;
                auto wt = repair_wating.top(); repair_wating.pop();
                wt._repair_index = tp._repair_index;
                wt._time = cur_time + time_repair[tp._repair_index];
                wt._step = REPAIR;

                qu.push(wt);
            }
        } 
        else if (tp._step == TAKE) {
            use_take[tp._take_index] = false;

            if (!take_wating.empty()) {
                use_take[tp._take_index] = true;
                auto wt = take_wating.top(); take_wating.pop();
                wt._take_index = tp._take_index;
                wt._time = cur_time + time_take[tp._take_index];
                wt._step = TAKE;

                qu.push(wt);
            }

            int repair_index = 0;
            while (repair_index < count_repair && use_repair[repair_index]) ++repair_index;

            if (repair_index == count_repair) repair_wating.push(tp);
            else {
                use_repair[repair_index] = true;
                tp._time += time_repair[repair_index];
                tp._step = REPAIR;
                tp._repair_index = repair_index;
                qu.push(tp);
            }

        }
        else {
            int take_index = 0;
            while (take_index < count_take && use_take[take_index]) ++take_index;

            if (take_index == count_take) {
                take_wating.push(tp);
            }
            else {
                use_take[take_index] = true;
                tp._time += time_take[take_index];
                tp._step = TAKE;
                tp._take_index = take_index;
                qu.push(tp);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << (ans==0?-1:ans) << '\n';
    }

    return 0;
}
