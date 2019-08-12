#include <stdio.h>

int bill[4] = {};
int month[12] = {};
int day[15]={};
int min[15]={};

int main(void)
{
	int test_case;
	int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for(int i =0; i<4; i++) scanf("%d", &bill[i]);
        for(int i =0; i<12; i++) {
			scanf("%d", &month[i]);
			if(bill[1] < bill[0]*month[i]) day[i] = bill[1];
			else day[i] = bill[0]*month[i];
		}

		for(int i = 11; 0<=i; i--) {
			min[i] = day[i] + min[i+1];
			if (min[i] > bill[2] + min[i+3]) min[i] = bill[2] + min[i+3];
			if (min[i] > bill[3]) min[i] = bill[3];
		}
		printf("#%d %d\n", test_case, min[0]);
	}
	return 0; 
}