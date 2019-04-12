/**
 * 19.4.12 9:9~
 */
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;

int n, t, target;
bool visited[10000];
queue<pair<string, int>> qu;
char cmds[4] = {'D', 'S', 'L', 'R'};

int cmdRun(int input_, char cmdChar)
{
    if (cmdChar == 'D')
    {
        input_ <<= 1;
        input_ %= 10000;
        return input_;
    }
    else if (cmdChar == 'S')
    {
        input_ += 9999;
        input_ %= 10000;
        return input_;
    }
    else if (cmdChar == 'L')
    {
        input_ *= 10;
        input_ += (input_/10000);
        input_ %= 10000;
        return input_;
    }
    else 
    {
        input_ = 1000*(input_%10) + input_/10;
        return input_;
    }
}

void bfs(pair<string, int> input)
{
    for (int i=0; i<4; i++)
    {
        int ret = cmdRun(input.second, cmds[i]);
        if (ret == target)
        {
            printf("%s", input.first.c_str());
            printf("%c\n", cmds[i]);
            queue<pair<string, int>> emptyqu;
            swap(emptyqu, qu);
            return;
        }
        if (visited[ret]) continue;
        visited[ret] = true;
        string tmp(input.first);
        tmp.push_back(cmds[i]);
        qu.push({tmp, ret});
    }
    
}

int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    for (int tc=0; tc<t; tc++)
    {
        for (int i=0; i<10000; i++) visited[i] = false;

        scanf("%d %d", &n, &target);
        visited[n] = true;
        qu.push({"", n});
        while (!qu.empty())
        {
            pair<string, int> f = qu.front();
            qu.pop();
            bfs(f);
        }
    }

    return 0;
}

/*
1234
D   2468
L   4682
S   4681
L   6814
S   6813
S   6812
L   8126
S   8125
D   6250
D   2500
D   5000
D   0000
*/