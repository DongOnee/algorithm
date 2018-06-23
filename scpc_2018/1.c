/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

int N, K;
int A[200000][2];

int n_buses;

void input_bus(int index_bus, int index_a) {
  A[index_a][1] = index_bus;
}

int chech_bus(int index_bus, int index_a) {
  for (int i=0; i<index_a; i++) {
    if (A[i][1] == index_bus) {
      int tmp = A[i][0] - A[index_a][0];
      if (tmp < 0) tmp *= -1;
      if (tmp <= K) return 0;
    }
  }
  return 1;
}

void output_bus(int index_a) {
  A[index_a][1] = 0;
}

void dfs(int index) {
  if(index == N) {
    if (n_buses < Answer) Answer = n_buses;
    return;
  }
  if (Answer < n_buses) return;
  for(int i=1; i<=n_buses; i++) {
    if(chech_bus(i, index)) {
      input_bus(i, index);
      dfs(index+1);
      output_bus(index);
    }
  }

  input_bus(n_buses++, index);
  dfs(index+1);
  output_bus(index);
  n_buses--;
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
    for(int i=0; i<N; i++) scanf("%d", &A[i][0]);

    Answer = N;
    n_buses = 1;

    input_bus(1, 0);
    dfs(1);

    /////////////////////////////////////////////////////////////////////////////////////////////

        		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
