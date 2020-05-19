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

const int MAXEXEC = 50000000;

string code, inp;
int m, c, i;
map<int, int> oc;

struct
{
    int curmem, curcode, curinput;
    unsigned char mem[100001];
    void init()
    {
        curmem = curcode = curinput = 0;
        memset(mem, 0x00, sizeof(mem));
    }
    void run()
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
        else if (code[curcode] == '[' && mem[curmem] == 0x00)
            curcode = oc[curcode];
        else if (code[curcode] == ']' && mem[curmem] != 0x00)
            curcode = oc[curcode];
        else if (code[curcode] == '.');
        else if (code[curcode] == ',')
        {
            if (curinput < i)
                mem[curmem] = inp[curinput++];
            else
                mem[curmem] = 0xff;
        }
        curcode++;
    }
} st;

void sol()
{
    st.init();

    cin >> m >> c >> i;
    cin >> code >> inp;

    oc.clear();
    vector<int> openidx;
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
    while (++cnt < MAXEXEC && st.curcode < c)
        st.run();

    if (st.curcode == c)
        cout << "Terminates\n";
    else
    {
        int loopIdx = st.curcode;
        while (--cnt)
        {
            st.run();
            loopIdx = max(loopIdx, st.curcode);
        }
        cout << "Loops " << oc[loopIdx] << " " << loopIdx << '\n';
    }
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