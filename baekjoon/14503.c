#include <stdio.h>
#include <stdlib.h>

int dir[4][2] = { {-1,0}, {0,1}, {1, 0}, {0, -1}};
int n, m;
int map[50][50];

typedef struct {
    int loc[2];
    int to;
} cleaner;

int isWall(int* x) {
    if( x[0] <0 || x[1]<0 || x[0]>=n || x[1]>=m ) return 1;
    return 0;
}

void turn(cleaner* c) {
    c->to +=3;
    c->to %=4;
}

int* left(cleaner* c) {
    int* res = (int*) malloc(sizeof(int)*2);
    res[0] = c->loc[0]+dir[(c->to+3)%4][0];
    res[1] = c->loc[1]+dir[(c->to+3)%4][1];

    return res;
}

void go(cleaner* c, int where) {
    if(where==1){
        c->loc[0] += dir[c->to][0];
        c->loc[1] += dir[c->to][1];
    } else {
        c->loc[0] -= dir[c->to][0];
        c->loc[1] -= dir[c->to][1];
    }
}

int main (void) {
    scanf("%d %d", &n, &m);
    cleaner* machine = (cleaner*) malloc(sizeof(cleaner));
    scanf("%d %d %d", &machine->loc[0], &machine->loc[1], &machine->to);
    for (int i =0; i<n; i++) 
        for(int j =0; j<m; j++) 
            scanf("%1d", &map[i][j]);

    int sol=0;
    int turn_count=0;
    while(1) {
        int x = machine->loc[0];
        int y = machine->loc[1];
        if(turn_count == 4) {
            int ba[2] = {x-dir[machine->to][0], y-dir[machine->to][1]};
            if(isWall(ba) || map[ba[0]][ba[1]]==1) {
                printf("%d\n", sol);
                break;
            } go(machine, 0);
            turn_count =0;
            continue;
        }
        if(map[x][y] == 0 ) {
            sol++;
            map[x][y] = 2;
        }
        int * le = left(machine);
        if(isWall(le)==1) {
            turn(machine);
            turn_count++;
            continue;
        } if(map[le[0]][le[1]]!=0){
            turn(machine);
            turn_count++;
            continue;
        }
        turn(machine);
        go(machine, 1);
        turn_count=0;
    }
}
