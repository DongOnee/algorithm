#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> pii;

pii operator+(const pii& a, const pii& b) { return {a.first+b.first, a.second+b.second}; }
pii operator-(const pii& a, const pii& b) { return {a.first-b.first, a.second-b.second}; }

bool chk(pii p, int n) { return 0<=p.first&&p.first<n&&0<=p.second&&p.second<n; }

int isSame(vector<string>& board, pii idxCenter)
{
    int ans = 0, mapSz = board.size();
    char centerChar = board[idxCenter.first][idxCenter.second];
    while (chk(idxCenter-make_pair(ans+1, ans+1), mapSz) && chk(idxCenter+make_pair(ans+1, ans+1), mapSz))
    {
        ans++;
        if (!(board[idxCenter.first-ans][idxCenter.second-ans] == centerChar
             && board[idxCenter.first-ans][idxCenter.second+ans] == centerChar
             && board[idxCenter.first+ans][idxCenter.second-ans] == centerChar
             && board[idxCenter.first+ans][idxCenter.second+ans] == centerChar))
        {
            ans--;
            break;
        }
    }
    return ans;
}

int solution(vector<string> board) {
    int answer = 0, mapSz = board.size();;
    for (int idxStart = (mapSz-1) / 2; 0 < idxStart; idxStart--)
    {
        if (answer >= idxStart) break;
        
        for (int i = idxStart; i < mapSz - idxStart; i++)
        {
            int tmp = isSame(board, {idxStart, i});
            answer = answer>tmp?answer:tmp;
            tmp = isSame(board, {i, idxStart});
            answer = answer>tmp?answer:tmp;
            tmp = isSame(board, {mapSz-idxStart-1, i});
            answer = answer>tmp?answer:tmp;
            tmp = isSame(board, {i, mapSz-idxStart-1});
            answer = answer>tmp?answer:tmp;
        }
    }
    
    return answer==0?0:answer*2+1;
}