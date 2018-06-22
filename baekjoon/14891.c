#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void circle(int* c, int mode){
    if ( mode == 1) { // 시계방향
        int temp=*(c+7);
        for(int i=7; i!=0; i--) *(c+i) = *(c+i-1);
        *c = temp;
    } else if ( mode == -1 ) { // 반시계방향
        int temp=*c;
        for(int i=0; i<7; i++) *(c+i) = *(c+i+1);
        *(c+7) = temp;
    } else return;
}

void allcircle(int** cc, int mode, int start, int end) {
    while(start <= end) {
        circle(cc[start], mode);
        start++;
        mode *= (-1);
    } 
}

int* init(int temp) { // N 극 =0, S 극 =1
    int* result = (int*) malloc(sizeof(int)*8);
    for (int i=7; i>=0 ;i--) {
        *(result + i) = temp%10;
        temp /=10;
    }

    return result;
}

void getsol(int** cc) {
    int sol=0;
    if (cc[0][0] == 1) sol +=1;
    if (cc[1][0] == 1) sol +=2;
    if (cc[2][0] == 1) sol +=4;
    if (cc[3][0] == 1) sol +=8;
    printf("%d", sol);
}
int main(void) { // n극 = 0, s극 =1
    int c[4];
    int* cc[4];
    for (int i=0; i<4; i++) {
        scanf("%d", &c[i]);
        cc[i] = init(c[i]);
    }

    int n;
    scanf("%d", &n);

    while (n-- !=0) {
        int select, mode;
        scanf("%d %d", &select, &mode);
        int start = select-1;
        int end = select-1;
        while (end<3){ //오른쪽으로
            if(cc[end][2] != cc[end+1][6]) end +=1;
            else break;
        }
        while (0< start){ // 왼쪽으로
            if(cc[start][6] != cc[start-1][2]) {start -=1; mode *= (-1);}
            else break;
        }
        allcircle(cc, mode, start, end);
    }
    getsol(cc);

    return 0;
}

