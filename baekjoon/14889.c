#include <stdio.h>
#include <stdlib.h>

int n;
int map[20][20];
int person[20]={};

int min = -1;

void getMin() {
    int sol;
    int score[2]={0,0};
    for(int i=0; i<n; i++){
        int team = person[i];
        for(int j=0; j<n; j++) {
            if(team == person[j]) score[team] += map[i][j];
        }
    }
    sol = abs(score[0]-score[1]);
    if (sol<min||min == -1) min = sol;
    return;
}

void dfs(int x, int count) {
    if(count == n/2){
        getMin();
    }else {
        for(int i=x+1; i<n; i++) {
            person[i] = 1;
            dfs(i, count+1);
            person[i] = 0;
        }
    }return;
}

int main(void) {
    scanf("%d", &n);
    for (int i=0; i<n; i++) for(int j=0; j<n; j++) scanf("%d", &map[i][j]);
    dfs(-1,0);
    printf("%d\n", min);
    return 0;
}