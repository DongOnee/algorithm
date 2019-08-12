#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;
int L;
int map[200][100]={};

int main(void) {
    int sol = 0;
    scanf("%d %d", &N, &L);
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++) {
            int tmp;
            scanf("%d", &tmp);
            map[i][j] = tmp;
            map[j+N][i] = tmp;
        }
    
    for(int i=0; i<2*N; i++){
        int fst=map[i][0];
        int res=1;
        int count=1;
        for(int j=1; j<N; j++) {
            if (abs(fst-map[i][j])>1) {
                res=0;
                break;
            }if (fst == map[i][j]) {
                count++;
                continue;
            } if((map[i][j] - fst) == 1){
                if(count<L) {
                    res=0;
                    break;
                } count = 1;
            } else if((map[i][j] - fst) == -1){
                if(count<0) {
                    res=0;
                    break;
                } count = 1-L;
            } fst = map[i][j];
        }
        if(count<0) res=0;
        if(res) sol++;
    }
    printf("%d\n", sol);
    return 0;
}