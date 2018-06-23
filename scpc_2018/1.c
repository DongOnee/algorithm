/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <stdio.h>

int Answer;

typedef struct Bus {
  int* person[200000];
  int count;
} B;

void in_bus(B* bus, int* person) {
  bus->count++;
  bus->person[bus->count] = person;
}

void out_bus(B* bus) {
  bus->count--;
}

int is_empty(B* bus) {
  if (bus->count ==0) return 1;
  return 0;
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
	freopen("input.txt_1", "r", stdin);

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
     Answer =0;
     int n, k;
     scanf("%d %d", &n, &k);
     int a[200000];
     for (int i=0; i<n; i++) scanf("%d", &a[i]);

     for (int i=0; i<n; i++) {
       for (int j=0; j<n_bus; j++) {
         in_bus(buses[j], a[i]);
       }
     }


		/////////////////////////////////////////////////////////////////////////////////////////////

        		// Print the answer to standard output(screen).

		printf("Case #%d\n", test_case+1);
	        	printf("%d\n", Answer);

	}

	return 0;//Your program should return 0 on normal termination.
}
