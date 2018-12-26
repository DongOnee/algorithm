/**
 * 18.12.20. 목요일 
 */
#include <cstdio>
#include <math.h>
using namespace std;

char map[2188][2188];

void blank(int row, int col, int po) {
    
}

void save(int row, int col, int po) {
    if (po == 1) map[row][col] = '*';
    else
    {
        int diff = po/3;
        save(row, col, diff);
        save(row, col+diff, diff);
        save(row, col+(2*diff), diff);
        save(row+diff, col, diff);
        for (int i=0; i<diff; i++) for (int j=0; j<diff; j++) map[row+i+diff][col+j+diff] = ' ';
        save(row+diff, col+(2*diff), diff);
        save(row+(2*diff), col, diff);
        save(row+(2*diff), col+diff, diff);
        save(row+(2*diff), col+(2*diff), diff);
    }
}

int main(int argc, char const *argv[])
{
    int N; scanf("%d", &N);
    save(0, 0, N);
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++) printf("%c", map[i][j]);
        printf("\n");
    }
    return 0;
}
