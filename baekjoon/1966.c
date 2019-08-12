#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DOCUMANT 100

typedef struct Node {
    int priority;
    struct Node *pre;
    struct Node *next;
} node;

node* initNode(int pri) {
    node* res = (node*) malloc(sizeof(node));
    res->priority = pri;
    res->pre = NULL;
    res->next = NULL;

    return res;
}

typedef struct Q{
    node * head;
    int size;
} q;

q* initQ(){
    q* res = (q*) malloc(sizeof(q));
    res->size = 0;
    res->head = NULL;

    return res;
}

void enQ(q* res, int pri) {
    node* n = initNode(pri);
    if (res->size == 0) {
        res->head = n;
        n->next=n;
        n->pre = n;
    } else if (res->size == 1) {
        res->head->next = n;
        res->head->pre = n;
        n->next = res->head;
        n->pre = res->head;
    } else {
        n->next = res->head;
        n->pre = res->head->pre;
        res->head->pre->next = n;
        res->head->pre = n;
    }
    res->size++;
}

node* deQ(q* in) {
    if(in->size == 0) return NULL;
    node* res = in->head;
    if(in->size == 1) {
        in->head = NULL;
        in->size--;
        return res;
    }
    res->pre->next = res->next;
    res->next->pre = res->pre;
    in->head = res->next;
    in->size--;

    res->next=NULL;
    res->pre=NULL;
    return res;
}

node* isHeadMax(q* sol) {
    if (sol->size == 1) return NULL;
    node* tmp = sol->head;
    int headpri = sol->head->priority;

    for(int i=0; i<sol->size; i++) {
        tmp = tmp->next;
        if(tmp->priority > headpri) return tmp;
    }
    return NULL;
}

int main(void) {
    int testcase;
    scanf("%d", &testcase);
    while(testcase-- != 0){
        int n, m;
        scanf("%d %d", &n, &m);
        q* sol = initQ();
        node* ptr_m;


        for(int i=0; i<n; i++) {
            int pri;
            scanf("%d", &pri);
            enQ(sol, pri);
            printf("");
            if(m==i) ptr_m = sol->head->pre;
        }
        
        int i;
        int times=1;
        while(sol->size) {
            node* max = isHeadMax(sol);
            if(max ==NULL){
                if(sol->head == ptr_m) printf("%d\n", times);
                deQ(sol);
                times++;
            } else {
                sol->head = max;
            }
        }
    }

    return 0;
}