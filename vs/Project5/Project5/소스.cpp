#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include "stacksADT.h"
int main() {
	unsigned int num;
	int* digit;
	int* sum_8;
	int* sum_16;
	STACK* stack_2;
	STACK* stack_8;
	STACK* stack_16;
	//STACK* temp;
	int count = 0, sum = 0;
	int s8=0,s16=0;
	stack_2 = createStack();
	stack_8 = createStack();
	stack_16 = createStack();
	//temp = createStack();

	printf("Enter an integer:\t");
	scanf("%d", &num);
	
	while (num > 0) {
		digit = (int*)malloc(sizeof(int));
		sum_8 = (int*)malloc(sizeof(int));
		sum_16 = (int*)malloc(sizeof(int));
		*digit = num % 2;

		pushStack(stack_2, digit);

		count++;

		sum = *digit;
		for (int i = 0; i < (count-1) % 3; i++) {
			sum *= 2;
		}
		s8 += sum;
		if (count % 3 == 0) {
			*sum_8 = s8;
			pushStack(stack_8, sum_8);
			s8 = 0;
		}

		sum = *digit;
		for (int i = 0; i < (count - 1) % 4; i++) {
			sum *= 2;
		}
		s16 += sum;
		if (count % 4 == 0) {
			*sum_16 = s16;
			pushStack(stack_16, sum_16);
			s16 = 0;
		}

		num = num / 2;

		if (!num) {
			if (count % 3) {
				*sum_8 = s8;
				pushStack(stack_8, sum_8);
			}
			if (count % 4) {
				*sum_16 = s16;
				pushStack(stack_16, sum_16);
			}
		}
	}
	printf("\nThe binary number is :\t");
	while (!emptyStack(stack_2)) {
		digit = (int*)popStack(stack_2);

		printf("%ld", *digit);
	}
	printf("\nThe octal number is :\t");
	while (!emptyStack(stack_8)) {
		digit = (int*)popStack(stack_8);
		printf("%ld", *digit);
	}
	printf("\nThe hexadcimal is :\t");
	while (!emptyStack(stack_16)) {
		digit = (int*)popStack(stack_16);
		if (*digit >= 10) {
			printf("%c", (*digit) - 10 + 'A');
		}
		else printf("%ld", *digit);
	}
	printf("\n");
	destroyStack(stack_2);
	destroyStack(stack_8);
	destroyStack(stack_16);
	return 0;
}