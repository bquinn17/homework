#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double factorial(double n){
	if (n == 0){ 
 		return 1;
	} else {
		return  n * factorial(n-1);
	}
}


double stirlingOne(double n){
	return pow(n, n) * pow(M_E, (n * (-1))) * sqrt(2 * M_PI * n);
}

double stirlingTwo(double n){
	return stirlingOne(n) * (1 + (1/(12 * n)));
}

int main(void){
	char programState = 'y';

	while (programState == 'y'){

		double userInput;
		double counter = 1;
		printf("Please enter a number: ");
		scanf("%lf", &userInput);

		if (userInput < 1)
		{
			printf("Please enter a number greater than zero!\n");
			continue;
		}
		printf("Number\t\tFactorial\t\tSterling1\t\tSterling2\n");
		int i = 0; while( i < 75){ 
				i++; 
				printf("-");
			}
		while (counter <= userInput){
			
			printf("\n");
			printf("%0.5f\t\t%f\t\t%f\t\t%f\n", 
				counter, factorial(counter), stirlingOne(counter), stirlingTwo(counter));
			printf("\n");
			counter += userInput < 15 ? 1 : 5;
		}
		

		printf("\n Do you want to compute another factorial? (y/n): ");
		scanf(" %c", &programState);
	}

	printf("*** Program Terminated ***\n");
}
