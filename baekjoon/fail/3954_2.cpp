/**
 * 2020.05.18 22:35 ~
 */
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;

int m, c, i;
unsigned char mem[100001];
string code, inp;

void sol()
{
    memset((char*)mem, 0x00, sizeof(mem));
    int curmem=0;
    int curcode = 0;
    int curinput = 0;

    cin >> m >> c >> i;
    cin >> code >> inp;

    map<int, int> oc;
    vector<int> openidx;
    vector<set<tuple<int, int, int, char>>> ocp;

    for (int i=0; i<c; i++)
    {
        if (code[i] == '[')
            openidx.push_back(i);
        else if (code[i] == ']')
        {
            int tp = openidx.back(); openidx.pop_back();
            oc[tp] = i;
            oc[i] = tp;
        }
    }

    int cnt = 0;
    while (++cnt < 500000)
    {
        if (code[curcode] == '-')
            mem[curmem] += 0xff;
        else if (code[curcode] == '+')
            mem[curmem] += 0x01;
        else if (code[curcode] == '<')
        {
            curmem += m-1;
            curmem %= m;
        }
        else if (code[curcode] == '>')
        {
            curmem += 1;
            curmem %= m;
        }
        else if (code[curcode] == '[' )
        {
            if (mem[curmem] == 0x00)
            {
                // Move
                curcode = oc[curcode];
            }
            else
            {
                // 지옥 시작
                ocp.push_back(set<tuple<int, int, int, char>>());
                ocp.back().insert({curcode, curinput, curmem, mem[curmem]});
            }
        }
        else if (code[curcode] == ']')
        {
            if (mem[curmem] == 0x00)
            {
                // Move
                ocp.pop_back();
            }
            else
            {
                curcode = oc[curcode];
                if (ocp.back().find({curcode, curinput, curmem, mem[curmem]}) != ocp.back().end())
                    break;
                ocp.back().insert({curcode, curinput, curmem, mem[curmem]});
            }
        }
        else if (code[curcode] == '.');
        else if (code[curcode] == ',')
        {
            if (curinput < i)
                mem[curmem] = inp[curinput++];
            else
                mem[curmem] = 0xff;
        }
        
        if (++curcode == c)
        {
            cout << "Terminates\n";
            return;
        }
    }
    cout << "Loops " << min(curcode, oc[curcode]) << ' ' << max(curcode, oc[curcode]) << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--)
        sol();

    return 0;
}


/*

8
10 9 3
+[-[><]-]
qwe
1 9 1
++[[++]+]
a
10 4 3
+-.,
qwe
1000 5 1
+[+-]
a
100 74 4
+++++[->++<]>[-<+++++++>]<[->+>+>+>+<<<<]>+++>--->++++++++++>---<<<.>.>.>.
xxyz
9999 52 14
+++++[>+++++++++<-],+[-[>--.++>+<<-]>+.->[<.>-]<<,+]
this_is_a_test
10 7 1
+[>+[]]
q
10 9 1
+[>-[-]<]
q


*/