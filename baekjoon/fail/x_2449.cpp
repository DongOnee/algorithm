/**
 * 19.1.31.
 * 반례를 못찾겠다..
 * 실패가 뜬다.
 */
#include <cstdio>
#include <stack>
using namespace std;

int N, K;
int map[201];
bool chk[21];

stack<int> st;

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);

    int ret = 0;
    for (int i=0; i<N; i++)
    {
        scanf("%d", &map[i]);
        if (st.empty())
        {
            st.push(map[i]);
            chk[map[i]] = true;
            continue;
        }
        int tp = st.top();
        if (tp == map[i]) continue;
        if (!chk[map[i]])
        {
            st.push(map[i]);
            chk[map[i]] = true;
        }
        else
        {
            while(tp != map[i])
            {
                st.pop();
                ret++;
                chk[tp] = false;
                tp = st.top();
            }
        }
    }

    printf("%ld\n", ret+st.size()-1);

    return 0;
}
