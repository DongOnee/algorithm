/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

<<<<<<< HEAD
int N, K;
int A[200000][2];

int n_buses;

typedef struct node{
  int a;
  struct node* next;
} n;

typedef struct {
  int size;
  n* start;
  n* end;
} bus;

void input_bus(bus* b, n* a) {
  if(b->size == 0) {
    b->start = a;
    b->end = a;
  } else {
    b->end->next = a;
    b->end = a;
  }
  b->size++;
}

n* output_bus(bus* b) {
  n* tmp;
  if (b->size == 1) {
    tmp = b->end;
    b->start = NULL;
    b->end = NULL;
  } else {
    tmp = b->start;
    for (int i=2; i<b->size; i++) tmp = tmp->next;
    b->end = tmp;
    tmp = tmp->next;
    b->end->next = NULL;
  }
  b->size--;
  return tmp;
}

int check_bus(bus* b, n* a) {
  n* tmp = b->start;
  for (int i=0; i<b->size; i++) {
    int kk = tmp->a - a->a;
    if (kk < 0) kk *=-1;
    if (kk <=K) return 0;
  }
  return 1;
}

void dfs(int index) {
  if(index == N) {
    if (n_buses < Answer) Answer = n_buses;
    return; 
  }
  if (Answer < n_buses) return;
  for(int i=1; i<=n_buses; i++) {
    if(check_bus(&buses[i], &A[index])) {
      input_bus(&buses[i], &A[index]);
      dfs(index+1);
      output_bus(&buses[i]);
    }
  }

  input_bus(n_buses++, index);
  dfs(index+1);
  output_bus(index);
  n_buses--;
}

=======
>>>>>>> 092dd80323c7f003ebac8bf5e59dd0d60d7ef361
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
	// freopen("input.txt", "r", stdin);

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

        		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
