// Add your program here!
# include <stdio.h>
# include <stdlib.h>
#include <time.h>
int main(){
	int games[5];
	
	for (int i = 0; i < 5; i++){
		// a single game
	
		//generate a random target 1-10
		srand(time(NULL));
		int target = rand() % 10 + 1;

		printf("===============================\n");
		printf("CPU Says: Pick a number 1-10\n");
		printf("===============================\n");
		
		int guess;
		int num = 0;
		
		while(1){
			printf("Make a guess: ");
			scanf("%d", &guess);
			num ++;
			if (guess < target){
				printf("No guess higher!\n");
			}
			else if (guess > target){
				printf("No guess lower!\n");
			}
			else if (guess == target){
				printf("You got it!\n");
				break;
			}
		}
		games[i] = num;
	}

	printf("==================================================\n");
	printf("| Here are the results of your guessing abilities|\n");
	printf("==================================================\n");
	
	for (int i = 0; i < 5; i++){
		printf("Game %d took you %d guesses\n", i+1, games[i]);
	}

	return 0;
}


