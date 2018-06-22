#include <stdio.h>
#include <string.h>
/**
 * push X: 정수 X를 큐에 넣는 연산이다.
 * pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * size: 큐에 들어있는 정수의 개수를 출력한다.
 * empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 * front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 * back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 */

#define MAX_INPUT 10000

typedef struct queue{
    int front;
    int end;
    int data[MAX_INPUT];
} Q;

void init(Q *q) {
    q->front =0;
    q->end = -1;
}

void push(Q *q, int i) {
    q->data[++q->end] = i;
}

int size(Q *q) {
    return q->end - q->front +1 ;
}

int empty(Q *q) {
    if (size(q) == 0) return 1;
    else return 0;
}

int pop(Q *q){
    if (empty(q) == 1) return -1;
    return q->data[q->front++];
}

int front(Q *q) {
    if (empty(q) == 1) return -1;
    else return q->data[q->front];
}

int back(Q *q) {
    if (empty(q) == 1) return -1;
    else return q->data[q->end];
}

int main(void){
    int n;
    scanf("%d", &n);
    char command[6];
    Q q;
    init(&q);
    while (0<n--){
        scanf("%s", command);

        if (!strcmp(command, "push")) {
            int i;
            scanf("%d", &i);
            push(&q, i);
        } else if (!strcmp(command, "pop")) printf("%d\n", pop(&q));
        else if (!strcmp(command, "size")) printf("%d\n", size(&q));
        else if (!strcmp(command, "empty")) printf("%d\n", empty(&q));
        else if (!strcmp(command, "front")) printf("%d\n", front(&q));
        else if (!strcmp(command, "back")) printf("%d\n", back(&q));
        
    }
    return 0;
}