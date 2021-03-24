#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>

using namespace std;

typedef pair<int,int> pii;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first+b.first,a.second+b.second); }

const pii dirs[4] = {{0,1},{0,-1},{-1,0},{1,0}};

map<pii, int> st;
map<pii, vector<int>> mp;

pii atoms[1000];
int atom_count;
int ans;

void init()
{
    st.clear();
    mp.clear();
    ans = 0;

    int m,x,y,d,k;
    cin >> m;
    for (atom_count = 0; atom_count < m; ++atom_count) {
        cin >> x >> y >> d >> k;
        x *= 2, y *= 2;
        atoms[atom_count] = {d, k};
        st[{x, y}] = atom_count;
    }
}

void move_atom()
{
    for (auto& atom : st) {
        pii cur = atom.first;
        int idx = atom.second;
        cur = cur + dirs[atoms[idx].first];
        if (cur.first < -2000 || cur.first > 2000 || cur.second <-2000 || cur.second > 2000) continue;
        mp[cur].push_back(idx);
    }
    st.clear();
}

void chk_atoms()
{
    for (auto& atom : mp) {
        if (atom.second.size() == 1) {
            st[atom.first] = atom.second[0];
        }
        else {
            int sum = 0;
            for (int i : atom.second) {
                sum += atoms[i].second;
            }
            ans += sum;
        }
    }
    mp.clear();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for (int test_case = 1; test_case <= T; ++test_case) {
        init();
        while (!st.empty()) {
            move_atom();
            chk_atoms();
        }

        cout << "#" << test_case << " " << ans << "\n";
    }

    return 0;
}
