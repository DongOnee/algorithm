#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m; // 가로줄 n 개 세로줄 m 개
int d[102][102] ={};
int sol[102][102] ={};
int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

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

void search(qu* _q, pair* _p) {
    int count=0;
}

void bfs(qu* _q) {
    pair * init = (pair*) malloc(sizeof(pair));
    init->x =1;
    init->y =1;
    init->next =NULL;
    sol[1][1]=1;

    push(_q, init);

    while(_q->size) {
        pair * cur = pop(_q);
        for(int i=0; i<4; i++) {
            if(d[cur->x+dir[i][0]][cur->y+dir[i][1]]){
                if(sol[cur->x+dir[i][0]][cur->y+dir[i][1]] == 0 ||
                sol[cur->x+dir[i][0]][cur->y+dir[i][1]] > sol[cur->x][cur->y]+1) {
                    sol[cur->x+dir[i][0]][cur->y+dir[i][1]]=sol[cur->x][cur->y]+1;
                    pair * tmp = (pair *) malloc(sizeof(pair));
                    tmp->x = cur->x+dir[i][0];
                    tmp->y = cur->y+dir[i][1];
                    push(_q, tmp);
                }
            }
        }

        free(cur);
    }
}

int main (void) {
    scanf("%d %d", &n, &m);

    for (int i =1; i<=n; i++)
        for(int j=1; j<=m; j++) 
            scanf("%1d", &d[i][j]);

    // for (int i =1; i<=n; i++){
    //     printf("\n");
    //     for(int j=1; j<=m; j++) 
    //         printf("%d ", d[i][j]);
    // }
    qu* q = (qu*) malloc(sizeof(qu));
    bfs(q);

    printf("%d\n",sol[n][m]);

    return 0;
}