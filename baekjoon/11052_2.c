#include <stdio.h>
int a[1001];
int d[1001];

int main() {
    int n;
    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%d",&a[i]);
    
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (d[i] < d[i-j] + a[j]) {
                d[i] = d[i-j] + a[j];
            }
        }
    }
    printf("%d\n",d[n]);
    return 0;
}