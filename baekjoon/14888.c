#include <stdio.h>

int N;
int number[11] = {};
int op[4]={}; // 0: + , 1: - , 2: x , 3: /
int opl[4] = {};

int min = 1000000000;
int max =-1000000000;

void dfs(int cur, int oper, int count){
    int res;
    if(oper == 0) res = cur + number[count];
    else if(oper == 1) res = cur - number[count];
    else if(oper == 2) res = cur * number[count];
    else res = cur / number[count];

    if( count == N-1) {
        if(res < min) min = res;
        if(max < res) max = res;
        return;
    } else {
        for(int j=0; j<4; j++) {
            if(op[j] !=0) {
                op[j]--;
                dfs(res, j, count+1);
                op[j]++;
            }
        }
    }
}

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i<N; i++) scanf("%d", &number[i]);
    for(int i = 0; i<4; i++) scanf("%d", &op[i]);
    
    dfs(0, 0, 0);
    printf("%d\n%d\n", max, min);
    return 0;
}