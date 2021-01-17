#include <iostream>
#include <deque>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

typedef struct _command
{
    int sec;
    char turncode;
    _command() : sec(0), turncode(0) {};
    _command(int s, char c) : sec(s), turncode(c) {};
}command;

pii operator+(const pii& a, const pii& b) { return make_pair(a.first + b.first, a.second + b.second); }

const int MAXN = 100;
const int BLOCK = -1;
const int APPLE = -2;
const pii dirs[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

deque<pii> snake;
int snakeDir;
int board[MAXN+2][MAXN+2];
int boardSize, appleCount, commandCount;
vector<command> cmds;
int cmdIdx;

void print_debug()
{
    cout << snakeDir << '\n';
    for (int i = 1; i <= boardSize; ++i)
    {
        for (int c = 1; c <= boardSize; ++c)
        {
            cout << board[i][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int run()
{
    int sec = 0;
    snake.emplace_back(1, 1);
    board[1][1] = 1;

    while (1)
    {
        if (cmds[cmdIdx].sec == sec)
        {
            if (cmds[cmdIdx].turncode == 'L') snakeDir += 3;
            else if (cmds[cmdIdx].turncode == 'D') snakeDir += 1;
            snakeDir %= 4;
            cmdIdx++;
        }

        pii prevHead = snake.back();
        pii nextHead = prevHead + dirs[snakeDir];
        
        sec++;
        auto& nxt = board[nextHead.first][nextHead.second];
        if (nxt == BLOCK || nxt == 1) break;

        snake.push_back(nextHead);
        if (nxt == 0) 
        {
            pii tail = snake.front(); snake.pop_front();
            board[tail.first][tail.second] = 0;
        }
        nxt = 1;

        // print_debug();
    }

    return sec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> boardSize;
    for (int i = 0; i <= boardSize +1; ++i)
    {
        board[i][0] = BLOCK;
        board[0][i] = BLOCK;
        board[i][boardSize+1] = BLOCK;
        board[boardSize+1][i] = BLOCK;
    }

    cin >> appleCount;
    for (int i = 0, x, y; i < appleCount; ++i)
    {
        cin >> x >> y;
        board[x][y] = APPLE;
    }

    cin >> commandCount;
    for (int i = 0, sec; i < commandCount; ++i)
    {
        char c;
        cin >> sec >> c;
        cmds.emplace_back(sec, c);
    }
    cmds.emplace_back();

    cout << run() << '\n';

    return 0;
}
