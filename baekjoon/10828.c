#include <stdio.h>
#include <string.h>

char stack[4096];
int size=0;

int pop();
int empty();
int top();

int main(void) {

  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    char c[200];
    scanf("%s", c);

    if (strcmp("push",c) == 0) {
      int number;
      scanf("%d", &number);
      stack[size++]=number;
    } else if (strcmp("pop", c) == 0) {
      printf("%d\n", pop());
    } else if (strcmp("size", c) == 0) {
      printf("%d\n", size);
    } else if (strcmp("empty", c) == 0) {
      printf("%d\n", empty());
    } else {
      printf("%d\n", top());
    }
  }
  return 0;
}

int pop() {
  if (size == 0) {
    return -1;
  } else {
    return stack[--size];
  }
}

int empty() {
  if (size == 0) return 1;
  else return 0;
}

int top() {
  if (size == 0) {
    return -1;
  } else {
    return stack[size-18];
  }
}
