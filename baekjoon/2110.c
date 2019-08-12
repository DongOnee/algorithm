#include <stdio.h>

int home[200001];
int num = 0;

void insert();

int main(void) {
  int N, C;
  scanf("%d %d", &N, &C);

  for (int i = 0; i < N; i++) {
    insert();
  }

  return 0;
}

void insert() {
  int temp;
  scanf("%d", &temp);
  if (num == 0) home[num] = temp;
  else {
    temp_num = num-1;
    while (temp < home[temp_num]) {
      home[temp_num+1] = home[temp_num--];
    }
    home[temp_num+1] = temp;
  }
  num++;
}
