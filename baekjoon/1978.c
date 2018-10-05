#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d\n",&N);
    int box[N];
    int count1=0;

    for (int i=0; i<N; i++) scanf("%d",&box[i]);

    for (int i=0; i<N; i++){
        int T= 1;
        if (box[i]==1) T =0;
        else{
            for (int j=2; j<=(int)sqrt(box[i]) && T; j++) 
                if (box[i]%j==0) T=0;
        }
        if (T) count1++;
    }

    printf("%d\n", count1);
    return 0;
}
