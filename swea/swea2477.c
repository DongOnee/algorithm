#include <stdio.h>

int n, m, k, a, b;
int ai[9];
int bi[9];
int tk[1000];

int c_index = 0;

void func() {
    int times = -1;
    while(1){
        times++;
        while(tk[c_index] == times)
    }
}

int main(void)
{
	int test_case;
	int T;
	
	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (test_case = 1; test_case <= T; ++test_case)
	{
        scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);
        for(int i=0; i<n; i++) scanf("%d", &ai[i]);
        for(int i=0; i<m; i++) scanf("%d", &bi[i]);
        for(int i=0; i<k; i++) scanf("%d", &tk[i]);


	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}