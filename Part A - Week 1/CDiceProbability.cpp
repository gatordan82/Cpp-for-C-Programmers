#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIDES 6
#define R_SIDE (rand() % SIDES + 1)

//int main()
//{
//	srand(clock());
//
//	int trials = 0;
//	printf("\nEnter number of trials: ");
//	scanf_s("%d", &trials);
//
//	int outcomes[SIDES * 2 + 1] = { 0 };
//	int d1 = 0, d2 = 0;
//
//	for (int j = 0; j < trials; ++j)
//		outcomes[(d1 = R_SIDE) + (d2 = R_SIDE)]++;
//
//	printf("probability\n");
//
//	int n_dice = 2;
//	for (int j = 2; j < n_dice * SIDES + 1; ++j)
//		printf("j = %d p = %lf\n", j,
//		(double)(outcomes[j]) / trials);
//
//	return 0;
//}
