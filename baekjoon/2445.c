#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);

	for (int i=0;i<N;i++){
        for (int j=0; j<=i; j++) printf("*");
		for (int j=2; j<2*(N-i); j++) printf(" ");
        for (int j=0; j<=i; j++) printf("*");
		printf("\n");
	}
    for (int i=N-2;0<=i;i--){
        for (int j=0; j<=i; j++) printf("*");
		for (int j=2; j<2*(N-i); j++) printf(" ");
        for (int j=0; j<=i; j++) printf("*");
		printf("\n");
	}
	return 0;
}