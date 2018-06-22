#include <stdio.h>

int a[101][10]; //a[length][last number]

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++) a[1][i] = 1;

	for (int i=0; i<=N; i++)
		for (int j=0; j<10; j++)
			for(int k=0; k<=j; k++) {
				a[i][j] += a[i-1][k];
				a[i][j] %= 10007;
			}
	
	unsigned long ret=0;
	for (int i = 0; i < 10; i++) ret += a[N][i];

	printf("%lu\n", ret%10007);

	return 0;
}
