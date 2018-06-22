#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);

	int i, j;

	for (i=0;i<N;i++){
		for (j=1;j<=N-i;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}