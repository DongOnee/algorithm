/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

typedef struct node {
  int a;
  struct node* next;
} node;

typedef struct bus {
  node *start;
  node *end;
  int size;
} bus;

int n, k;

node a[200000];
bus b[200000];

int check(int bus_index, int input_index) {
  node *tmp = b[bus_index].start;
  while ( tmp!=NULL ) {
		int diff = tmp->a - a->a;
		if (diff < 0) diff *=-1;
		if (diff <= k) return 0;
  }
	return 1;
}

void bus_input(int bus_index, int input_index) {
	if (b[bus_index].size == 0) b[bus_index].start =a;
	else b[bus_index].end->next = a;
	b->end = a;
	b->size++;
}

void bus_output(bus *b) {
	node *tmp = b->start;
	if (b->size == 1) {
		b->start = NULL;
		b->end = NULL;
		b->size--;
	} else {
		for (int i=2; i<b->size; i++) tmp = tmp->next;
		b->end = tmp;
		tmp->next = NULL;
		b->size--;
	}
}

void dfs(int input_index, int bus_count) {
  if (input_index == n) {
    if (bus_count < Answer) Answer = bus_count;
    return;
  }
  for(int i=0; i<bus_count; i++) {
    if(check(i, input_index)) {
      bus_input(i, input_index);
      dfs(input_index+1, bus_count);
      bus_output(i);
    }
  }
  bus_input(bus_count+1, input_index);
  dfs(input_index+1, bus_count+1);
  bus_output(bus_count+1);
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
	freopen("sample_input_1.txt", "r", stdin);

	/*
	   If you remove the statement below, your program's output may not be recorded
	   when your program is terminated after the time limit.
	   For safety, please use setbuf(stdout, NULL); statement.
	 */
	//setbuf(stdout, NULL);

	scanf("%d", &T);
	for(test_case = 0; test_case < T; test_case++)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++) scanf("%d", &a[i].a);
		

    dfs(0, 0);

        		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
