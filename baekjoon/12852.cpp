/**
 * BFS 를 이용해서 풀었다.
 * 정답은 맞았으나 running time 이 굉장히 오래 걸리는 소스이다.
 * 문제점은 string을 이용해서 풀어서 컴퓨팅 파워가 많이 필요한가 보다.
 * pair<int, string> 을 이용했는데 의미는
 * @first : 현재 값
 * @second : 현재값이 올때까지 연산 시퀀스
 *          1: 나누기 2
 *          2: 나누기 3
 *          3: 빼기 1
 * ex) {1, "2312"} 의 원래 숫자는 (((1*3)*2)+1)*3 의 값을 가진다.
 * 정답을 보고 12852_2.cpp 을 풀었다.
 */
#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int n, ans2 = -1;
string answer;
queue<pair<int, string>> qu;
vector<int> vv;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    qu.push({n, ""});
    
    bool flag = true;
    while (flag)
    {
        ans2++;
        long sz = qu.size();
        while (sz--)
        {
            pair<int, string> f = qu.front(); qu.pop();

            if (f.first == 1)
            {
                flag = false;
                answer = f.second;
                break;
            }
            
            if (f.first % 2 == 0)
                qu.push({f.first/2, f.second+"1"});
            if (f.first % 3 == 0 && f.first > 2)
                qu.push({f.first/3, f.second+"2"});
            qu.push({f.first-1, f.second+"3"});
        }
    }

    cout << ans2 << endl;
    vv.push_back(1);
    while (ans2--)
    {

        if (answer.back() == '1')
            vv.push_back(vv.back()*2);
        if (answer.back() == '2')
            vv.push_back(vv.back()*3);
        if (answer.back() == '3')
            vv.push_back(vv.back()+1);
        answer.pop_back();
    }
    
    for (vector<int>::iterator i = vv.end()-1; vv.begin() <= i; i--)
        cout << *i << ' ';

    return 0;
}

