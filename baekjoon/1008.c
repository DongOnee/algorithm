#include <stdio.h>
int main() {
    int a,b;
    double c;
    scanf("%d %d", &a, &b);
    c=a*(1.0)/b;
    printf("%.9lf\n",c);
    return 0;
}
