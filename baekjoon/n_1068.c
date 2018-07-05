#include <stdio.h>

void deleteOperation(int, int[], int);
void countleafnode(int[], int);

int main(void) {
  // the # of nodes
  int N;
  scanf("%d",&N);

  // initialize nodes
  int parentofi[N];
  for (int i = 0; i < N; i++)
    scanf("%d",&parentofi[i]);
  int nodesize = sizeof(parentofi)/sizeof(int);

  // get deletenode's index
  int deletenode;
  scanf("%d",&deletenode);
  parentofi[deletenode]=-1;

  // delete!!
  deleteOperation(deletenode, parentofi, nodesize);

  // delete node without leafnode
  countleafnode(parentofi, nodesize);

  // count leafnode
  int solution=0;
  for (int i = 0; i < N; i++) {
    if(parentofi[i]!=-1) solution++;
  }
  printf("%d\n",solution);
  return 0;
}

void deleteOperation(int index, int nodes[], int nodesize) {
  nodes[index]=-1;
  for (int i=0;i<nodesize;i++){
    if(nodes[i]==index) deleteOperation(i, nodes, nodesize);
  }
}

void countleafnode(int nodes[], int nodesize){
  for (int i = 0; i < nodesize; i++) {
    for (int j = 0; j < nodesize; j++) {
      if (nodes[j]==i) {
        nodes[i]=-1;
        break;
      }
    }
  }
}
