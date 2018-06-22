#include <stdio.h>

void insert(int[], int);
void quickSort(int[], int, int);
int partition(int[], int, int);
int binarySearch(int[], int, int);

int A[100001];
int B[100001];

int main(void) {
  int num_A;
  scanf("%d", &num_A);
  insert(A, num_A);

  quickSort(A, 0, num_A-1);

  int num_B;
  scanf("%d", &num_B);
  insert(B, num_B);

  for (int i = 0; i < num_B; i++) {
    printf("%d\n", binarySearch(A, num_A, B[i]));
  }

  return 0;
}

void insert(int a[], int num_A) {
  for (int i = 0; i < num_A; i++) {
    int temp;
    scanf("%d", &temp);
    a[i] = temp;
  }
}

void quickSort( int a[], int l, int r) {
   int j;

   if( l < r ) {
     // divide and conquer
     j = partition( a, l, r);
     quickSort( a, l, j-1);
     quickSort( a, j+1, r);
   }
}

int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;

   while( 1) {
     do ++i; while( a[i] <= pivot && i <= r );
     do --j; while( a[j] > pivot );
     if( i >= j ) break;
     t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

int binarySearch(int a[], int size, int b) {
  int head = 0;
  int tail = size-1;
  while (1) {
    int mid = (head + tail)/2;
    if (a[head] == b || a[mid] == b || a[tail] == b) return 1;
    if (a[mid] < b) head = mid +1;
    else tail = mid -1;
    if (head >= tail) return 0;
  }
}
