#include <stdio.h>
#include <stdlib.h>

int n, m; // 가로줄 n 개 세로줄 m 개
int map[8][8] ={};
int cp[8][8] ={};
int dir[4][2] = { {1,0}, {-1,0}, {0, 1}, {0, -1}};

int maxmum;

typedef struct node{
    int x;
    int y;
    struct node* next;
} pair;

typedef struct queue {
    pair* head;
    pair* tail;
    int size;
} qu;

void push(qu* _q, pair* _p) {
    if (_q->size ==0) {
        _q->head = _p;
        _q->tail = _p;
        _q->size=1;
    } else{
        _q->tail->next = _p;
        _q->tail = _p;
        _q->size++;
    }
}

pair* pop(qu* _q) {
    if (_q->size == 0) return NULL;
    pair * res = _q->head;
    _q->head = res->next;
    res->next = NULL;
    _q->size--;
    return res;
}

//--------------------------------------------

void bfs() {
    qu* _q = (qu*) malloc(sizeof(qu));
    _q->size =0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) 
            if(cp[i][j] == 2) {
                pair * tmp = (pair*) malloc(sizeof(pair));
                tmp->x =i;
                tmp->y =j;
                tmp->next =NULL;
                push(_q, tmp);
            }

    while(_q->size) {
        pair * cur = pop(_q);
        for(int i=0; i<4; i++) {
            int new_x = cur->x+dir[i][0];
            int new_y = cur->y+dir[i][1];
            if(new_x < 0 || new_y < 0||new_x >= n || new_y >= m) continue;
            if(cp[new_x][new_y] == 0){
                cp[new_x][new_y] = 2;
                pair * tmp = (pair *) malloc(sizeof(pair));
                tmp->x = new_x;
                tmp->y = new_y;
                tmp->next=NULL;
                push(_q, tmp);
            }
        }
        free(cur);
    }
}

void dfs(int _x, int _y, int count) {
    if(count ==3) {
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) cp[i][j] = map[i][j];
        bfs();
        int sol=0;
        for(int i=0; i<n; i++) for(int j=0; j<m; j++) {
            if (map[i][j] == 0){
                if(cp[i][j] == 0) sol++;
                else cp[i][j] = map[i][j];
            }
        }
        if(maxmum < sol) maxmum = sol;
    }else {
        for(int j=_y; j < m; j++) {
            if(map[_x][j] == 0) {
                map[_x][j] = 1;
                dfs(_x, j, count+1);
                map[_x][j] = 0;
            }
        }
        for(int i=_x+1; i<n; i++)
            for(int j=0; j<m; j++) {
                if(map[i][j] == 0) {
                    map[i][j] = 1;
                    dfs(i, j, count+1);
                    map[i][j] = 0;
                }
            }
    }

}

int main (void) {
    for (int i =0; i<8; i++) for(int j=0; j<8; j++)map[i][j]=1;
    maxmum =0;

    scanf("%d %d", &n, &m);

    for (int i =0; i<n; i++)
        for(int j =0; j<m; j++) 
            scanf("%1d", &map[i][j]);
    dfs(0,0,0);
    printf("%d\n", maxmum);
    return 0;
}