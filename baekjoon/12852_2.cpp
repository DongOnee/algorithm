/**
 * 좀더 쉬운 방법으로 풀었는데 이전에는 시퀀스를 저장했다면
 * 이번 에는 파생된 배열의 인덱스를 집어 넣었다.
 * @first : 값
 * @second : 파생된 어미 인덱스
 * ex) {3, 5} 의 의미는 arr[5].first 에서 연산('/3', '/2', '-1')을 해서 나온 값이 3이라는 의미이다.
 */
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<pii> arr;
int answerCnt, answerGrp;
bool isVisited[1000001];

void bfs()
{
    int stIdx = 0;
    while (true)
    {
        answerCnt++;
        int endIdx = arr.size();
        for (; stIdx<endIdx; stIdx++)
        {
            if (arr[stIdx].first == 1)
            {
                answerGrp = stIdx;
                return ;
            }
            
            if (arr[stIdx].first %3 == 0 && arr[stIdx].first > 2 && !isVisited[arr[stIdx].first/3])
            {
                isVisited[arr[stIdx].first/3] = true;
                arr.push_back({arr[stIdx].first/3, stIdx});
            }
            if (arr[stIdx].first %2 == 0 && !isVisited[arr[stIdx].first/2])
            {
                isVisited[arr[stIdx].first/2] = true;
                arr.push_back({arr[stIdx].first/2, stIdx});
            }
            if (!isVisited[arr[stIdx].first-1])
            {
                isVisited[arr[stIdx].first-1] = true;
                arr.push_back({arr[stIdx].first-1, stIdx});
            }
        }
        stIdx = endIdx;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    arr.push_back({n, -1});
    isVisited[n] = true;
    bfs();

    cout << answerCnt-1 << '\n';
    vector<int> tmp;
    while (answerGrp != -1)
    {
        // cout << arr[answerGrp].first << ' ';
        tmp.push_back(arr[answerGrp].first);
        answerGrp = arr[answerGrp].second;
    }
    
    for (int i=tmp.size() -1; 0<=i; i--)
    {
        cout << tmp[i] << ' ';
    }

    return 0;
}

