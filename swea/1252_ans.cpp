#include <stdio.h>

int max(int a, int b){
    if (a < b)a = b;
    return a;
}

int e[103][103];
int out[10003][3];
int cst[3] = { 2, 4, 7 };

int main(){

    int t;
    scanf("%d", &t);

    int tc = 0;

    while (t--){

        int s, n;
        scanf("%d %d", &s, &n);

        for (int i = 0; i < s; i++)for (int j = 0; j < s; j++)e[i][j] = 0;

        while (n--){
            int x, y;
            scanf("%d %d", &x, &y);
            x--, y--;
            e[x][y] = 1;
        }

        int ans = 0, top = 0;

        for (int k = 2; k >= 1; k--){
            // 3 : 5,6,7,8
            // 2 : 2,3,4
            for (int g = (k + 1)*(k + 1); g >= k*k + max(k-1, 1); g--){
                for (int i = 0; i + k < s; i++){
                    for (int j = 0; j + k < s; j++){
                        int c = 0;
                        for (int a = i; a <= i + k; a++)for (int b = j; b <= j + k; b++)c += e[a][b];
                        if (c == g){
                            ans++;
                            out[top][0] = i + 1, out[top][1] = j + 1, out[top][2] = k + 1;
                            top++;
                            for (int a = i; a <= i + k; a++)for (int b = j; b <= j + k; b++)e[a][b] = 0;
                        }
                    }
                }
            }
        }

        for (int i = 0; i < s; i++){
            for (int j = 0; j < s; j++){
                if (e[i][j]){
                    ans++;
                    out[top][0] = i + 1, out[top][1] = j + 1, out[top][2] = 1;
                    top++;
                }
            }
        }

        printf("#%d %d ", ++tc, ans);
        for (int i = 0; i < top; i++){
            for (int j = 0; j < 3; j++)printf("%d ", out[i][j]);
        }
        puts("");

    }

}