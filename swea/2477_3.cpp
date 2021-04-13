#include <iostream>
#include <queue>

using namespace std;

enum STEP
{
    ARRIVE,
    RECEPTION,
    REPAIR
};

typedef 
struct {
    int customer_number;
    int index_reception;
    int index_repair;
    STEP step;
    int t;
}info;

bool operator<(const info& a, const info& b) 
{
    if (a.t == b.t) {
        if (a.step == b.step) {
            if (a.step == ARRIVE) return a.customer_number > b.customer_number;
            else if (a.step == RECEPTION) {
                if (a.t == b.t) return a.index_reception > b.index_reception;
                return a.t > b.t;
            }
            return a.t > b.t;
        }
        return a.step > b.step;
    }
    return a.t > b.t;
}

const int INF = 987654321;

int time_reception[10], time_repair[10];
int last_time_reception[10], last_time_repair[10];
int count_reception, count_repair, count_customer;
int a, b;

int ans;

priority_queue<info> pq;

void init()
{
    cin >> count_reception >> count_repair >> count_customer >> a >> b;
    --a, --b;
    for (int i = 0; i < count_reception; ++i) {
        cin >> time_reception[i];
        last_time_reception[i] = 0;
    }
    for (int i = 0; i < count_repair; ++i) {
        cin >> time_repair[i];
        last_time_repair[i] = 0;
    }
    for (int i = 1; i <= count_customer; ++i) {
        int t; cin >> t;
        info tmp;
        tmp.customer_number = i;
        tmp.t = t;
        tmp.step = ARRIVE;
        tmp.index_reception = INF;
        tmp.index_repair = INF;
        pq.push(tmp);
    }
    ans = 0;
}

void run()
{
    while (!pq.empty()) {
        auto tp = pq.top(); pq.pop();

        if (tp.step == ARRIVE) {
            int min_index = 0;
            for (int idx = 1; idx < count_reception; ++idx) {
                if (last_time_reception[idx] < last_time_reception[min_index] && tp.t < last_time_reception[min_index]) min_index = idx;
            }

            tp.step = RECEPTION;
            tp.index_reception = min_index;
            last_time_reception[min_index] = max(tp.t, last_time_reception[min_index]);
            tp.t = last_time_reception[min_index] += time_reception[min_index];

            pq.push(tp);
        }
        else if (tp.step == RECEPTION) {
            int min_index = 0;
            for (int idx = 1; idx < count_repair; ++idx) {
                if (last_time_repair[idx] < last_time_repair[min_index] && tp.t < last_time_repair[min_index]) min_index = idx;
            }

            tp.step = REPAIR;
            tp.index_repair = min_index;
            last_time_repair[min_index] = max(tp.t, last_time_repair[min_index]);
            tp.t = last_time_repair[min_index] += time_repair[min_index];

            pq.push(tp);
        }
        else if (tp.step == REPAIR) {
            if (tp.index_repair == b && tp.index_reception == a) ans += tp.customer_number;
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
