#include <stdio.h>

int hannumber(int);

int main(void) {
    int N;
    scanf("%d", &N);

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if(hannumber(i)) count++;
    }
    printf("%d\n", count);
    return 0;
}

int hannumber(int i) {
    if (i/100 == 0) return 1;
    else {
        while( (i % 10 - i / 10 % 10) == (i / 10 % 10 - i / 100 % 10) ) {
            i = i/10;
            if(i/100==0) return 1;
        }
        return 0;
    }
}
