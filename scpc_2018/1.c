/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

int N, K;
int A[200000];

int n_buses;
int buses[200000];

void input_bus(int index_bus, int input_a) {
  buses[index_bus].as[buses[index_bus].count++] = input_a;
}

int chech_bus(int index_bus, int input_a) {
  for(int i=0; i<buses[index_bus].count; i++) {
    int tmp = input_a - buses[index_bus].as[i];
    if (tmp < 0) tmp *= -1;
    if (tmp <= K) return 0;
  }
  return 1;
}

void output_bus(int index_bus) {
  buses[index_bus].as[--buses[index_bus].count] = 0;
}

void dfs(int index) {
  if(index == N) {
    if (n_buses < Answer) Answer = n_buses;
    return;
  }
  for(int i=0; i<n_buses; i++) {
    if(chech_bus(i, A[index])) {
      input_bus(i, A[index]);
      dfs(index+1);
      output_bus(i);
    }
  }
  buses[n_buses].count = 0;
  input_bus(n_buses++, A[index]);
  dfs(index+1);
  output_bus(--n_buses);
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
	   If you remove the statement below, your program's output may not be rocorded
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
    scanf("%d %d", &N, &K);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    Answer = N;
    n_buses = 1;

    buses[0].count = 0;
    input_bus(0, A[0]);
    dfs(1);

    /////////////////////////////////////////////////////////////////////////////////////////////

        		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
