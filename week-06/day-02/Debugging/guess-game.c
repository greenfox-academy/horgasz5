#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//project-guessing-game
//Note: the program gets harder, when you set a lower range

int main()
{
	int x, y;
	int count;
	int guess = 0;
	int rand_max;
	int rand_min;
	printf("please add the minimum number!\n");
	scanf("%d", &rand_min);
	printf("please add the maximum number!\n");
	scanf("%d", &rand_max);
	srand(time(NULL));
	int rand_num = rand() % (rand_max + 1 - rand_min) + rand_min;
	y = rand_max - rand_min;
	x = log10(y) / log10(2);

	printf("I have a number between %d and %d. You have %d lives\n", rand_min, rand_max, x - 3);

	for (count = 1; count < x - 2; count++) {
		printf("\n>");
		scanf("%d", &guess);

		while (1) {
			if (guess == rand_num) {
				printf("Yeeeeey, you did well! It took you %d tires!", count);
				break;
			} else if (guess > rand_num) {
				printf("Too big, You have %d, lives left\n", x - 3 - count);
				break;
			} else {
				printf("Too low, You have %d, lives left\n", x - 3 - count);
				break;
			}
		}
	}

	if (count = x)
		printf("You have used all your lives!\n");
		printf("%d\n", rand_num);

	return 0;
}