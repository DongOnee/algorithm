#include <stdio.h>

int N, M, C;
int map[10][10]={};
int* sol[2];
int max;

void calc(int index, int cur, int count1, int count2) {
    if(index == 2*M) {
        if(max<cur) max = cur;
        return ;
    } 
    calc(index+1, cur, count1, count2);
    if(index/M ==0){
        if (count1 + sol[index/M][index%M] <= C){
            calc(index+1, cur + sol[index/M][index%M]*sol[index/M][index%M], count1 +sol[index/M][index%M], count2);
        }
    }
    if(index/M ==1){
        if (count2 + sol[index/M][index%M] <= C){
            calc(index+1, cur + sol[index/M][index%M]*sol[index/M][index%M], count1, count2+sol[index/M][index%M]);
        }
    }
}

int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);
    
	for (test_case = 1; test_case <= T; ++test_case)
	{
		scanf("%d %d %d", &N, &M, &C);
        for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &map[i][j]);
        max = -1;

        for(int i=0; i<N; i++) for(int j=0; j<=N-M; j++) {
            sol[0] = &map[i][j];
            for(int k=j+M; k<=N-M; k++) {
                sol[1] = &map[i][k];
                calc(0,0,0,0);
            }
            for(int l = i+1; l <N; l++) for(int k=0; k<=N-M; k++) {
                sol[1] = &map[l][k];
                calc(0,0,0,0);
            }
        }
        printf("#%d %d\n", test_case, max);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}