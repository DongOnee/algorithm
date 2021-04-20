#include <iostream>
#include <utility>
#include <math.h>

using namespace std;

typedef pair<int,int> pii;
typedef pii (*func_ptr)(pii);

const pii dirs[4] = {{0,0},{0,1},{1,1},{1,0}};

int n, a, b, ans, step;
pii pa, pb;

pii func1(pii a) { return {a.second, a.first}; }
pii func2(pii a) { return a; }
pii func3(pii a) { return {pow(2,step)-1-a.second, pow(2,step)-1-a.first}; }

func_ptr logic[4] = { func1, func2, func2, func3 };

void init()
{
    cin >> n >> a >> b;
    --a, --b;
    ans = step = 0;
}

void run()
{
    for (; step < n; ++step) {
        int ca = a % 4;
        a /= 4;
        int cb = b % 4;
        b /= 4;
        
        if (step == 0) {
            pa = dirs[ca];
            pb = dirs[cb];
        }
        else {
            pa = logic[ca](pa);
            pa = {pow(2,step) * dirs[ca].first + pa.first, pow(2,step) * dirs[ca].second + pa.second };
            pb = logic[cb](pb);
            pb = {pow(2,step) * dirs[cb].first + pb.first, pow(2,step) * dirs[cb].second + pb.second };
        }
    }

    // cout << pa.first << ' ' << pa.second << endl << pb.first << ' ' << pb.second << endl;
    ans = (int) (sqrt((pow(abs(pa.first-pb.first), 2) + pow(abs(pa.second-pb.second), 2)) * 100) + 0.5);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for (int tc = 1; tc <=T; ++tc) {
        init();
        run();

        cout << '#' << tc << ' ' << ans << '\n';
    }

    return 0;
}
