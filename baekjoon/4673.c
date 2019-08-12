#include <stdio.h>

void selfD(int,int*);

int main(void) {
  int num[10000]={0,};

  int* ptr=num;

  for (int i = 0; i < 10000; i++) {
    if (num[i]==0) selfD(i, ptr);
  }

  for (int i = 0; i < 10000; i++) {
    if (num[i]==0) printf("%d\n", i+1 );
  }
  return 0;
}

void selfD(int index,int* num){
  int value=index+1;
  if (index<10000) {
    int temp=0;
    while (value!=0){
      temp += value%10;
      value = value/10;
    }
    if (index+temp<10000){
      num[index+temp]=1;
      selfD(index+temp,num);
    }
  }

}
