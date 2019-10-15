#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n; cin >> n;
        unordered_map<string, int> uomp;
        for (int i=0; i<n; i++)
        {
            string str; cin >> str;
            uomp[str] = i;
        }
        
        vector<int> order;
        for (int i=0; i<n; i++)
        {
            string str; cin >> str;
            order.push_back(uomp[str]);
        }

        vector<string> inputs(n);
        for (int i=0; i<n; i++)
        {
            string str; cin >> str;
            inputs[order[i]] = str;
        }

        for (string x : inputs) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}
