#include <stdio.h>

void push(int);
int pop();
int empty();
int top();

int stack[100000];
int size;

int main(void) {
  size=0;

  int N;
  scanf("%d", &N);
  int array[N];

  for (int i = 0; i < N; i++) {
    scanf("%d", &array[i]);
  }

  int i = 1;
  int j = 0;
  while (j < N) {
    if (top() == array[j]) {
      pop();
      j++;
    }
    else {
      if (N < i) {
        printf("NO\n");
        break;
      }
      push(i);
      i++;
    }
  }

  return 0;
}

void push(int number) {
  stack[size++] = number;
  printf("+\n");
}

int pop() {
  if (size == 0) {
    return -1;
  } else {
    printf("-\n");
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
