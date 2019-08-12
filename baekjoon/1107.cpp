/**
 * 18.12.18. 화요일
 */

#include <cstdio>

int N;
bool button[10] = { true, true, true, true, true, true, true, true, true, true}; // 이 부분.. 다르게 할 수도 있다.

int func(int input) {
    int res=0;
    while (input)
    {
        if (!button[input%10]) return -1;
        input /=10;
        res++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    int m; scanf("%d", &m);
    while (m--)
    {
        int exep_cmd; scanf("%d", &exep_cmd);
        button[exep_cmd] = false;
    }

    int ret=N-100;
    if (ret < 0) ret *= -1;
    if (button[0]) ret = ret < N+1 ? ret : N+1;

    for (int i=N+1; i<1111112; i++) // 이 부분에서 N = 0 일경우 i=N 으로 하면 에러가 날 수 있다.
    {
        int sol = func(i);
        if (sol < 0) continue;
        sol += i-N; // '-' 버튼 누르는 갯수를 더해준다.
        ret = ret<sol?ret:sol;
        break;
    }
    for (int i=N; 0<i; i--)
    {
        int sol = func(i);
        if (sol < 0) continue;
        sol += N-i; // '+' 버튼 누르는 갯수를 더해준다.
        ret = ret<sol?ret:sol;
        break;
    }

    printf("%d\n", ret);

    return 0;
}
