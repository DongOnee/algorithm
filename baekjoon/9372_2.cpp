#include <cstdio>


int main(void) {
    int T;
	scanf("%d", &T);
	for(int tc=1, N, M; tc<=T; tc++)
    {
		scanf("%d%d", &N, &M);
		for(int i=0, r, c; i<M; i++) scanf("%d%d", &r, &c);

		printf("%d\n", N-1);
	}
}