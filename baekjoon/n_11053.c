#include <stdio.h>

int map[1001];
int d[1001];
int max_index;

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i=1; i<=N; i++) {
        scanf("%d", &map[i]);
        for (int j=0; j<i; j++) {
            if ()
        }
    }

    int i =1;
    a[0] = d[0] = 0;
    while (i <= N) {
        scanf("%d", &a[i]);

        d[i] = 1;
        int j = i -1;
        while (j) {
            if(a[j] < a[i] && d[i] < d[j] + 1) d[i] = d[j] + 1;
            j--;
        }
        i++;
    }
    printf("%d\n", d[N]);
    return 0;
}
