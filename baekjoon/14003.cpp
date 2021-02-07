/**
 * 2020.04.13 21:24 ~ 11:32
 * BOJ#14002 와 연결되는 문제이다.
 * 
 * 문제의 핵심은 다음과 같다.
 * 1. 속도를 향상시키기 위한 Binary Search 를 이용하고,
 * 2. 변경된 LIS 수열에 무관하게 출력시키는데 있다.
 * 
 * 순열을 임시로 만드는데 아래 코드의 vt 이다.
 * arr 를 모두 돌면서 
 *  수열(vt)의 마지막(vt.back())보다 클 경우 마지막에 붙이고(push_back)
 *  아닌경우, lower_bound 를 이용해서 <크거나 같은 원소 중 가장 작은 인덱스>에 해당하는 곳에 수정한다.
 * 이때! 수열(vt) 의 수정이 일어난다.
 *  --> 이로 인해 위 루프의 결과 나오는 수열(vt) 는 우리가 원하는 순열이 아닐 수 있다.
 *      ex) 1 2 4 5 3 이라는 입력이 들어왔을 때,
 *          최종 수열(vt) 는 1 2 3 5 로 변하지만
 *          옳은 답은 1 2 4 5 이다.
 * 따라서 핵심.2 를 만족시켜야 된다.
 * 이를 위해 position 이라는 배열을 추가하였다.
 * position[i]는 순열을 만들때 arr[i]가 들어가는 인덱스 값이다.
 * 
 * 순열은 앞에서 구성하기 때문에 삽입된 요소같은 경우는 제일 끝에 있는 요소보다 arr 에서 뒤에 있다.
 * 설명이 어려우니 예를 들어 보겠다.
 *      ex) 1 2 4 5 3 이라는 입력이 들어왔을 때, 순열은 1 2 3 5 로 되고
 * position 1 2 3 4 3 값이 된다.
 *          3에 해당하는 값은 순열중간에 들어가지만,
 *          stack 엔 들어가지 않는다.
 *          따라서 최종 출력에는 3 이 아닌 4 가 출력된다.
 */
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 1'000'000;
// const int MAXA = 1'000'000'000;
const int MINA = -1'000'000'000;

int n, arr[MAXN], position[MAXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i=0; i<n; i++)
        cin >> arr[i];

    vector<int> vt;
    vt.push_back(MINA - 1);
    for (int i=0; i<n; i++)
    {
        if (vt.back() < arr[i])
        {
            position[i] = vt.size();
            vt.push_back(arr[i]);
        }
        else
        {
            auto itr = lower_bound(vt.begin(), vt.end(), arr[i]);
            *itr = arr[i];
            position[i] = itr-vt.begin();
        }
    }

    cout << vt.size()-1 << endl;

    stack<int> st;
    for (int i=n-1, idx = vt.size()-1; 0<=i; i--)
    {
        if (position[i] == idx)
        {
            st.push(arr[i]);
            idx--;
        }
    }

    while(!st.empty())
    {
        cout << st.top() << ' ';
        st.pop();
    }

    return 0;
}
