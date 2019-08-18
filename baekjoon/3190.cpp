/**
 * BOJ 3190
 * ~18.11.28 언제 시작한지 모름.
 * 너무 오래 걸렸다. 이런 문제는 집중하고 풀어 보도록 하는 시간을 가져야 겠다. 
 * 문제 알고리즘 생각은 쉬운데 구현에 많은 시간을 소비하곤 하니까 시간 체크를 하며 시간을 줄여 나가는 연습을 해야겠다.
 */
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

int N, apple_cnt;
int map[100][100]; // 0:empty, 1:snake, 2: apple
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
queue<pair<int, int>> snake;
int mv_cnt;

queue<pair<int, char>> cmd;

pair<int, int> head;
int head_dir;

bool chk(int row, int col) { return 0<=row&&row<N&&0<=col&&col<N; }

bool straight() {
    int next_row = head.first+dir[head_dir][0];
    int next_col = head.second+dir[head_dir][1];
    mv_cnt++;
    if (!chk(next_row, next_col)) return false;
    if (map[next_row][next_col] == 1) return false;
    else if (map[next_row][next_col] == 0)
    {
        int tail_row = snake.front().first;
        int tail_col = snake.front().second;
        map[tail_row][tail_col] = 0;
        snake.pop();
    }
    head = {next_row, next_col};
    snake.push(head);
    map[next_row][next_col] = 1;
    // printf("move cont %d\thead dir %d\tcur %d, %d\tsnake length %ld\n", mv_cnt, head_dir, head.first, head.second, snake.size());
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N); // map size
    for (int i=0; i<N; i++) for (int j=0; j<N; j++) map[i][j] = 0;

    scanf("%d", &apple_cnt); // apple count
    for (int i=0; i<apple_cnt; i++)
    {
        int row, col;
        scanf("%d %d", &row, &col);
        map[row-1][col-1] = 2;
    }

    head=make_pair(0, 0);
    snake.push(head);
    map[0][0]=1;
    head_dir=0;
    mv_cnt=0;

    int L; // turn count
    scanf("%d", &L);
    for (int i=0; i<L; i++)
    {
        int cmd_cnt;
        char cmd_char;
        scanf("%d %c", &cmd_cnt, &cmd_char);
        cmd.push({cmd_cnt, cmd_char});
    }

    while(!cmd.empty())
    {
        int turn_cnt=cmd.front().first;
        char turn_char=cmd.front().second;
        while(mv_cnt<turn_cnt)
        {
            if(straight()) continue;
            printf("%d\n", mv_cnt);
            return 0;
        }

        if (turn_char == 'L') head_dir +=3;// 왼쪽
        else if (turn_char == 'D') head_dir +=1;// 오른쪽
        head_dir %=4;
        cmd.pop();
    }
    while(straight());
    printf("%d\n", mv_cnt);
    return 0;
}
