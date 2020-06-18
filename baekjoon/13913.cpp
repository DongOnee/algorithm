/**
 * 2020.06.18. 22:30 ~ 25:24
 * 너무 오래 걸렸는데.. 역시 조건을 잘보자.. 
 * 0 부터 시작하는건데.. 왜 나는 0을 예외 처리 했을까
 */
#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

const int MAXN = 100000;

int n, k, indexOfPrev[MAXN+1];
queue<int> qu;

void bfs()
{
    qu.push(n);
    int answer = 0;

    while (!qu.empty())
    {
        int count = qu.size();
        while (count--)
        {
            int f = qu.front(); qu.pop();
            if (f == k)
            {
                cout << answer << '\n';
                
                vector<int> array;

                while (n != k)
                {
                    array.push_back(k);
                    k = indexOfPrev[k];
                }

                cout << k;
            
                for (int i=array.size()-1; 0 <= i; --i)
                    cout << ' ' << array[i];

                return ;
            }
    
            for (int nxt : {f-1, f+1, 2*f} )
            {
                if (0 <= nxt && nxt <= MAXN)
                {
                    if (indexOfPrev[nxt] == -1)
                    {
                        indexOfPrev[nxt] = f;
                        qu.push(nxt);
                    }
                }
            }
        }
        answer++;
    }
}

int main(int argc, const char* argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;

    memset(indexOfPrev, -1, sizeof(indexOfPrev)); 

//    indexOfPrev[n] = 0;

    bfs();
    
    return 0;
}
