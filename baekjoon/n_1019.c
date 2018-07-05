#include <stdio.h>

int main(void) {
    unsigned int a;
    unsigned int c[10]={};
    scanf("%d",&a);
    while(a--){
        unsigned int j;
        j =a+1;
        while(j!=0){
            c[j%10]++;
            j=j/10;
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d\n",c[0] ,c[1] ,c[2] ,c[3] ,c[4] ,c[5] ,c[6] ,c[7] ,c[8] ,c[9]);
    return 0;
}
