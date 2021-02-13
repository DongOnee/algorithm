#include <iostream>
#include <map>

using namespace std;

const char pad_char[5] = { 'a', 'c', 'i', 'n', 't'};

int n, k, ans;
map<int, int> words;

void dfs(int st, int cnt, int bits)
{
    if (cnt == k) {
        int ret = 0;
        for (auto& word : words) {

            if ((word.first & ~bits) == 0) {
                ret += word.second;
            }
        }
        ans = max(ans, ret);

        return;
    }

    for (int idx = st; idx < 26; ++idx) {
        if ((bits & (1 << idx)) > 0) continue;

        dfs(idx+1, cnt+1, (bits | (1<<idx)));;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        string word; cin >> word;
        int word_i = 0;

        for (int idx = 0; idx < word.size(); ++idx) {
            word_i = word_i | (1 << (word[idx] - 'a'));
        }
        ++words[word_i];
    }

    if (k < 5);
    else {
        int init_i = 0;
        for (int pad_idx = 0; pad_idx < 5; ++pad_idx) {
            init_i = init_i | (1 << (pad_char[pad_idx] - 'a'));
        }

        dfs(0, 5, init_i);
    }


    cout << ans << '\n';

    return 0;
}
