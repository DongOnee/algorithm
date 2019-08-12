#include <stdio.h>
#include <string.h>


void push(stack*, int);
int pop(stack*);
int empty(stack*);
int top(stack*);

typedef struct {
  int array[1000];
  int size;
} stack;

int main(void) {
  char str[1000];
  scanf("%s", str);

  stack *stk_i;
  stack *stk_p;

  for (int i = 0; i < strlen(str); i++) {
    char c = *(str + i);
    if (c == '(') push(stk_i, 2);
    else if (c == '[') push(stk_i, 3);
    else {
      if (c == ')')
    }
  }
}

////////////// stack functions
void push(stack* stk, int number) {
  stack[size++] = number;
  printf("+\n");
}

int pop(stack* stk) {
  if (size == 0) {
    return -1;
  } else {
    printf("-\n");
    return stack[--size];
  }
}

int empty(stack* stk) {
  if (size == 0)  return 1;
  else return 0;
}

int top(stack* stk) {
  if (size == 0) {
    return -1;
  } else {
    return stack[size-1];
  }
}
/////////////// end stack functions
