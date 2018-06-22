/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// scanf("%d", &a);                      // int 변수 1개 입력받는 예제
// scanf("%f %f", &b, &c);               // float 변수 2개 입력받는 예제 
// scanf("%lf %lf %lf", &d, &e, &f);     // double 변수 3개 입력받는 예제
// scanf("%c", &g);                      // char 변수 1개 입력받는 예제
// scanf("%s", &var);                    // 문자열 1개 입력받는 예제
// scanf("%lld", &AB);                   // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// printf("%d", a);                      // int 변수 1개 출력하는 예제
// printf("%f %f", b, c);                // float 변수 2개 출력하는 예제
// printf("%lf %lf %lf", d, e, f);       // double 변수 3개 출력하는 예제
// printf("%c", g);                      // char 변수 1개 출력하는 예제
// printf("%s", var);                    // 문자열 1개 출력하는 예제
// printf("%lld", AB);                   // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>

int n, m, r, c, l;
int type[50][50];
int visit[50][50];

void up(int x, int y, int count) {
    if(x-1<0) return;
    if(type[x-1][y] == 0) return;
    if(type[x-1][y] == 3) return;
    if(type[x-1][y] == 4) return;
    if(type[x-1][y] == 7) return;
    if(visit[x-1][y] != 0) return;
    visit[x-1][y] = count;
}

void down(int x, int y, int count) {
    if(n<=x+1) return;
    if(type[x+1][y] == 0) return;    
    if(type[x+1][y] == 3) return;
    if(type[x+1][y] == 5) return;
    if(type[x+1][y] == 6) return;
    if(visit[x+1][y] != 0) return;
    visit[x+1][y] = count;
}

void left(int x, int y, int count) {
    if(y-1<0) return;
    if(type[x][y-1] == 0) return;    
    if(type[x][y-1] == 2) return;
    if(type[x][y-1] == 6) return;
    if(type[x][y-1] == 7) return;
    if(visit[x][y-1] != 0) return;
    visit[x][y-1] = count;
}

void right(int x, int y, int count) {
    if(m<=y+1) return;
    if(type[x][y+1] == 0) return;    
    if(type[x][y+1] == 2) return;
    if(type[x][y+1] == 4) return;
    if(type[x][y+1] == 5) return;
    if(visit[x][y+1] != 0) return;
    visit[x][y+1] = count;
}

int main(void)
{
	int test_case;
	int T;
	/* 아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	freopen 함수를 이용하면 이후 scanf 를 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	// freopen("input.txt", "r", stdin);
	/* 아래 코드를 수행하지 않으면 여러분의 프로그램이 제한 시간 초과로 강제 종료 되었을 때,
	출력한 내용이 실제 표준 출력에 기록되지 않을 수 있습니다.
	따라서 안전을 위해 반드시 setbuf(stdout, NULL); 을 수행하시기 바랍니다.
	*/
	setbuf(stdout, NULL);
	scanf("%d", &T);
	/*
	여러 개의 테스트 케이스를 처리하기 위한 부분입니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        for (int i=0; i<n; i++) for(int j=0; j<m; j++) {
            scanf("%d", &type[i][j]);
            visit[i][j] = 0;
        }
        int sol = 0;
        visit[r][c] = 1;

        for (int k=1; k<l; k++) {
            for(int i=0; i<n; i++) for(int j=0; j<m; j++){
                if(visit[i][j] == k) {
                    switch(type[i][j]){
                        case 1:
                        up(i,j,k+1);
                        down(i,j,k+1);
                        left(i,j,k+1);
                        right(i,j,k+1);
                        break;
                        case 2:
                        up(i,j,k+1);
                        down(i,j,k+1);
                        break;
                        case 3:
                        left(i,j,k+1);
                        right(i,j,k+1);
                        break;
                        case 4:
                        up(i,j,k+1);
                        right(i,j,k+1);
                        break;
                        case 5:
                        right(i,j,k+1);
                        down(i,j,k+1);
                        break;
                        case 6:
                        down(i,j,k+1);
                        left(i,j,k+1);
                        break;
                        case 7:
                        left(i,j,k+1);
                        up(i,j,k+1);
                        break;
                        default:
                        break;
                    }
                }
            }
        }
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) if(visit[i][j] != 0 )sol++;
		printf("#%d %d\n", test_case, sol);
	}
	return 0; //정상종료시 반드시 0을 리턴해야 합니다.
}