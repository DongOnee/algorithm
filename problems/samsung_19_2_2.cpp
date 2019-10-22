#include <cstdio>
#include <map>
using namespace std;

//               0                   5                        10                       15                       20        22        24             27        29        31        33
int score[34] = {0, 20, 40, 60 ,80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300, 320, 340, 360, 380, 400, 500, 100, 150, 200, 250, 270, 290, 200, 220, 240, 250, 300, 350};
map<pair<int, int>, int> movement;

int arr[10], ho[4], cnt_ho, answer;

void dfs(int step)
{
    // 이제 돌게 없으면 값을 구하자.
    if (step == 10)
    {
        int sum = 0;
        for (int i=0; i<4; i++) sum += score[ho[i]];
        answer = answer<sum?sum:answer;
    }
    else 
    {
        // 새로운 말이 출격하는 경우.
        if (cnt_ho < 4)
        {
            ho[cnt_ho++] = arr[step];
            dfs(step+1);
            ho[--cnt_ho] = 0;
        }
        // 기존에 출격한 말을 이동하는 경우.
        for (int i=0; i<cnt_ho; i++)
        {
            int tmp = ho[i];
            if (tmp == 21) continue; // 도착지점이 가장 크니까...
            ho[i] = movement[make_pair(tmp, arr[step])];
            // 여기선 턴을 해줘야되니까...
            if (ho[i] == 5) ho[i] = 22;
            else if (ho[i] == 10) ho[i] = 28;
            else if (ho[i] == 25) ho[i] = 30;
            dfs(step+1);
            ho[i] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    // map 을 이용하여 key 값 (i, j) : i 위치해서 j 만큼 이동 할때 value (도착지점)
    for (int i=0; i<22; i++)
    {
        for (int j=1; j<=5; j++) movement[make_pair(i, j)] = (i + j < 22?i + j:21);
    }
    for (int i=22; i<28; i++)
    {
        for (int j=1; j<=5; j++) movement[make_pair(i, j)] = (i + j < 28?i + j:28-i-j+15);
    }
    for (int i=28; i<34; i++)
    {
        for (int j=1; j<=5; j++) movement[make_pair(i, j)] = (i + j < 34?i + j:(i+j==34?20:21));
    }

    int t; scanf("%d", &t);
    for (int test_case = 1; test_case <= t; test_case++)
    {
        // 초기화
        for (int i=0; i<10; i++) scanf("%d", arr+i);
        for (int i=0; i<4; i++) ho[i] = 0;
        cnt_ho = 0, answer = 0;;

        // DFS
        dfs(0);

        printf("#%d %d\n", test_case, answer);
    }

    return 0;
}

