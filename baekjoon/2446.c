#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);

    for (int i=0;i<N;i++){
        for (int j=0; j<i; j++) printf(" ");
		for (int j=1; j<N+N-i-i; j++) printf("*");
		printf("\n");
	}
	for (int i=1;i<N;i++){
        for (int j=1; j<N-i; j++) printf(" ");
		for (int j=0; j<=2*i; j++) printf("*");
		printf("\n");
	}
	return 0;
}