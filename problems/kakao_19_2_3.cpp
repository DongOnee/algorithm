/**
 * 2019.10.03. 18:30 ~ 20:21
 */
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;

pii rotPoint1(const int i, const int j, const int width) { return {j, width-1-i}; }
pii rotPoint2(const int i, const int j, const int width) { return {width-1-i, width-1-j}; }
pii rotPoint3(const int i, const int j, const int width) { return {width-1-j, i}; }

int subsol(const int start_i, const int start_j, const vvi& key, const vvi& lock)
{
    int ret = -2;
    int n = lock.size();
    int m = key.size();
    
    for (int rot=0; rot<4; rot++)
    {
        int cnt = 0;
        for (int idxKey_i=0; idxKey_i<m && start_i+idxKey_i<n; idxKey_i++)
        {
            if (start_i+idxKey_i <0) continue;
            for (int idxKey_j=0; idxKey_j<m && start_j+idxKey_j<n; idxKey_j++)
            {
                if (start_j+idxKey_j < 0) continue;
                pii rot_idxKey;
                if (rot == 1) rot_idxKey = rotPoint1(idxKey_i, idxKey_j, m);
                else if (rot == 2) rot_idxKey = rotPoint2(idxKey_i, idxKey_j, m);
                else if (rot == 3) rot_idxKey = rotPoint3(idxKey_i, idxKey_j, m);
                else rot_idxKey = {idxKey_i, idxKey_j};
                int rot_i = rot_idxKey.first;
                int rot_j = rot_idxKey.second;
                
                if (key[rot_i][rot_j] == 0) continue;
                if (lock[start_i+idxKey_i][start_j+idxKey_j] == 1)
                {
                    cnt = -1;
                    idxKey_i=m;
                    break;
                }
                else cnt++;
            }
        }
        ret = ret > cnt ? ret : cnt;
    }
    
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int m = key.size();
    int n = lock.size();
    
    int totals = 0;
    for (auto x : lock)
        for (auto y : x) if (y == 0) totals++;
    if (totals == 0) return true;

    for (int i=1-m; i<n; i++)
    {
        for (int j=1-m; j<n; j++)
        {
            int cntMatch = subsol(i, j, key, lock);
            if (cntMatch == totals) return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    printf("%s\n", solution({{0, 0, 0}, {1, 0, 0}, {0, 1, 1}}, {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}})?"true":"false");
    printf("%s\n", solution({{1, 1, 0}, {1, 0, 0}, {0, 0, 0}}, {{1, 1, 1}, {1, 1, 1}, {1, 1, 0}})?"true":"false");
    printf("%s\n", solution({{1, 0, 1}, {0, 1, 0}, {1, 0, 0}}, {{0, 1, 0}, {1, 0, 1}, {1, 1, 0}})?"true":"false");
    printf("%s\n", solution({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {{0, 1, 1}, {1, 1, 1}, {1, 1, 1}})?"true":"false");
    return 0;
}


/*
true
true
true
true
*/
