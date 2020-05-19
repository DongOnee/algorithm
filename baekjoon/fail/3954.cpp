#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

#define MOD 0x100
#define MAX_LOOP 50000000

int sm, sc, si;
string cmd, input;

void run(const map<int, int>& open2close, const map<int, int>& close2open)
{
    int idxCmd = 0, idxInput = 0, ptr = 0, loopcnt = 0, loop_start = sc+1;
    // vector<int> cntVisitCmd(sc, 0);
    vector<char> mem(sm, 0);
    while (idxCmd < sc)
    {
        if (cmd[idxCmd] == '-') mem[ptr] = (mem[ptr] + MOD - 1) % MOD;
        else if (cmd[idxCmd] == '+') mem[ptr] = (mem[ptr] + 1) % MOD;
        else if (cmd[idxCmd] == '<') ptr = (ptr + sm - 1) % sm;
        else if (cmd[idxCmd] == '>') ptr = (ptr + 1) % sm;
        else if (cmd[idxCmd] == '[' && mem[ptr] == 0) idxCmd = open2close.at(idxCmd);
        else if (cmd[idxCmd] == ']' && mem[ptr] != 0)
        {
            int idxCurClose = idxCmd;
            idxCmd = close2open.at(idxCmd);
            if (loopcnt >= 2 * MAX_LOOP) break;
            else if (loopcnt >= MAX_LOOP) loop_start = (loop_start<idxCmd?loop_start:idxCmd);
        }
        else if (cmd[idxCmd] == ',')
        {
            mem[ptr] = input[idxInput];
            if (ptr < si) idxInput++;
        }
        idxCmd++;
        loopcnt++;
    }
    if (loop_start > sc)cout << "Terminated\n";
    else cout << "Loops " << loop_start << ' ' << open2close.at(loop_start) << '\n';
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--)
    {
        cin >> sm >> sc >> si >> cmd >> input;

        stack<int> openSymbolIndex;
        map<int, int> open2close, close2open;
        for (int i=0; i<sc; i++) 
        {
            if (cmd[i] == '[') openSymbolIndex.push(i);
            else if (cmd[i] == ']')
            {
                int tp = openSymbolIndex.top(); openSymbolIndex.pop();
                open2close[tp] = i;
                close2open[i] = tp;
            }
        }

        input.push_back((char)255);
        run(open2close, close2open);
    }
    
    return 0;
}