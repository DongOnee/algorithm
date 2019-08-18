#include<stdio.h>

struct node {
  char left;
  char right;
};

void preorder(char);
void inorder(char);
void postorder(char);

struct node A[10000];

int main(void) {
  int n;
  scanf("%d", &n);
  for (int i =0; i<n; i++) {
    getchar();
    char temp1, temp2, temp3;
    scanf("%c %c %c", &temp1, &temp2, &temp3);
    A[temp1].left = temp2;
    A[temp1].right = temp3;
  }
  preorder('A');
  printf("\n");
  inorder('A');
  printf("\n");
  postorder('A');
  printf("\n");
}

void preorder(char root) {
  if (root == '.') return;
  else {
    printf("%c", root);
    preorder(A[root].left);
    preorder(A[root].right);
  }
}

void inorder(char root) {
  if (root == '.') return;
  else {
    inorder(A[root].left);
    printf("%c", root);
    inorder(A[root].right);
  }
}

void postorder(char root) {
  if (root == '.') return;
  else {
    postorder(A[root].left);
    postorder(A[root].right);
    printf("%c", root);
  }
}
