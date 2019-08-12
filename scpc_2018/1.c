/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

typedef struct node {
  int val;
  struct node *next;
} node;

typedef struct bus {
  node *start;
  node *end;
  int size;
} bus;

node A[200000];
bus B[200000];

int n, k;

int in_bus(int input_index, int bus_index) {
  if(B[bus_index].size == 0) {
    B[bus_index].start = &A[input_index];
    B[bus_index].end = &A[input_index];
    B[bus_index].size++;
    return 1;
  }
  node *tmp = B[bus_index].start;
  while ( tmp != NULL ) {
    int diff = tmp->val - A[input_index].val;
    if (diff < 0) diff *=-1;
    if (diff <= k) return 0;
    tmp = tmp->next;
  }
  B[bus_index].end->next = &A[input_index];
  B[bus_index].end = &A[input_index];
  B[bus_index].size++;
  return 1;
}

void out_bus(int bus_index) {
  node *tmp = B[bus_index].start;
  if(B[bus_index].size == 1) {
    B[bus_index].start = NULL;
    B[bus_index].end = NULL;
    B[bus_index].size--;
  } else {
    for (int i=2; i<B[bus_index].size; i++) tmp = tmp->next;
    tmp->next = NULL;
    B[bus_index].end = tmp;
    B[bus_index].size--;
  }
}

void dfs(int input_index, int bus_count) {
  if (input_index == n) {
    if (bus_count < Answer) Answer = bus_count;
    return;
  }
  for (int i=0; i<bus_count; i++) {
    if(in_bus(input_index, i)){
      dfs(input_index+1, bus_count);
      out_bus(i);
    }
  }
  in_bus(input_index, bus_count);
  if (bus_count+1 < Answer)
    dfs(input_index+1, bus_count+1);
  out_bus(bus_count);
}

int main(void)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using scanf function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */
	// freopen("sample_input_1.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be recorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

        		// Print the answer to standard output(screen).
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) {
      scanf("%d", &A[i].val);
      A[i].next = NULL;
    }
    Answer = n;

    dfs(0,0);

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
