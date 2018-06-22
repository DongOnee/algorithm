#include <stdio.h>
#include <string.h>

int isVPN(char*);
void push(int);
int pop();
int empty();
int top();
void showstack();

int* stack;
int size;

int main(void) {
  int N;
  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int array[10000] = {0,};
    size=0;
    printf("array : %d\n", array);
    stack = array;
    showstack();
    char c[1000]="";
    scanf("%s", c);
    int bool=isVPN(c);
    showstack();
    if(bool == 1) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

int isVPN(char* str1) {
  int i = 0;
  char c;
  while ((c = *(str1 + i)) != '\0') {
    printf("c : %c\n", c);
    if (c == '(') push(1);
    else if ((c == ')') && (top() == 1)) pop();
    else return 0;
    i++;
  }
  if (empty() == 1) return 1;
  return 0;
}

void push(int number) {
  stack[size++] = number;
}

int pop() {
  if (size == 0) {
    return -1;
  } else {
    stack[size-1] = 0;
    return stack[--size];
  }
}

int empty() {
  if (size == 0)  return 1;
  else return 0;
}

int top() {
  if (size == 0) {
    return -1;
  } else {
    return stack[size-1];
  }
}

//////// stack 에 뭐들어있나 보자
void showstack() {
  int i = 0;
  char c;
  printf("stack : ");
  while ((c = *(stack + i)) == 1) {
    printf("%d", c);
    i++;
  }
  printf("\n");
}
